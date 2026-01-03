#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --- CONFIGURATION ---
const char ownerNumber[] = "Number here"; 

// --- PINS (NodeMCU-32S) ---
#define SIM_TX      27 // Connect to SIM800L RX
#define SIM_RX      26 // Connect to SIM800L TX

// UI PINS
#define BTN_SEL     25
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// --- OBJECTS ---
HardwareSerial simSerial(1);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Variables
int signalStrength = 0;
String networkStatus = "Init...";
String deviceIMEI = "Unknown"; // Variable to store IMEI

// Prototypes
void updateSignal();
void makeCall();
void hangUp();
void getIMEI();

void setup() {
  Serial.begin(115200);
  
  // Button
  pinMode(BTN_SEL, INPUT_PULLUP);

  // 1. Init OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,10);
  display.println(F("Booting Module..."));
  display.display();
  delay(1000);

  // 2. Init SIM Serial
  simSerial.begin(9600, SERIAL_8N1, SIM_RX, SIM_TX);
  delay(1000);

  // 3. Basic Modem Config
  display.println(F("Syncing...")); display.display();
  simSerial.println("AT"); 
  delay(500);
  simSerial.println("AT+CMGF=1"); 
  delay(500);
  simSerial.println("AT+CLVL=100"); 
  delay(500);

  // 4. GET IMEI
  display.println(F("Reading IMEI...")); display.display();
  getIMEI();
  
  // 5. Force Network Search
  display.println(F("Check Signal...")); display.display();
  updateSignal();
}

void loop() {
  display.clearDisplay();
  
  // Header
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println(F("== DIAGNOSTICS =="));
  
  // Signal Info
  display.setCursor(0, 12);
  display.print(F("Sig: ")); display.print(signalStrength);
  if (signalStrength < 10) display.print(F(" (Weak)"));
  else display.print(F(" (OK)"));

  // IMEI Display
  display.setCursor(0, 24);
  display.print(F("IMEI:")); 
  display.setCursor(30, 24);
  display.print(deviceIMEI);

  // Status
  display.setCursor(0, 38);
  display.println(networkStatus);

  // Instruction
  display.setCursor(0, 54);
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE); // Inverted text for button
  display.println(F(" [SELECT] CALL NOW "));
  display.setTextColor(WHITE);
  
  display.display();

  // Button Logic
  if (digitalRead(BTN_SEL) == LOW) {
    delay(200); // Debounce
    makeCall();
  }

  // Refresh Signal every 2 seconds
  static unsigned long lastCheck = 0;
  if (millis() - lastCheck > 2000) {
    updateSignal();
    lastCheck = millis();
  }
}

void getIMEI() {
  // Clear buffer
  while(simSerial.available()) simSerial.read();
  
  simSerial.println("AT+GSN"); // Command for IMEI
  delay(500);
  
  String buffer = "";
  unsigned long t = millis();
  while(millis() - t < 1000) {
    if(simSerial.available()) {
      buffer += (char)simSerial.read();
    }
  }
  
  buffer.trim(); // Remove whitespace
  // Simple parser: usually response is AT+GSN\r\r\n<number>\r\nOK
  // We just look for the long number
  int len = buffer.length();
  if (len > 10) {
      // Find the pure number part (dirty hack for robustness)
      String cleanIMEI = "";
      for(int i=0; i<len; i++) {
        if(isDigit(buffer[i])) {
           cleanIMEI += buffer[i];
        }
      }
      if(cleanIMEI.length() > 10) {
        deviceIMEI = cleanIMEI;
      } else {
        deviceIMEI = "Read Error";
      }
  } else {
      deviceIMEI = "Timeout";
  }
}

void updateSignal() {
  while(simSerial.available()) simSerial.read();

  simSerial.println("AT+CSQ");
  unsigned long start = millis();
  
  while (millis() - start < 500) {
    if (simSerial.available()) {
      String response = simSerial.readString();
      int index = response.indexOf("+CSQ: ");
      if (index != -1) {
        String val = response.substring(index + 6, index + 8);
        val.trim();
        signalStrength = val.toInt();
      }
      
      if (signalStrength == 99 || signalStrength == 0) networkStatus = "No Signal";
      else networkStatus = "Ready to Dial";
    }
  }
}

void makeCall() {
  display.clearDisplay();
  display.setCursor(0, 20);
  display.setTextSize(2);
  display.println(F("DIALING..."));
  display.setTextSize(1);
  display.println(ownerNumber);
  display.display();

  simSerial.print("ATD");
  simSerial.print(ownerNumber);
  simSerial.println(";");
  
  delay(1000); 

  while (true) {
    if (digitalRead(BTN_SEL) == LOW) {
      hangUp();
      return; 
    }
    
    if (simSerial.available()) {
      String resp = simSerial.readString();
      if (resp.indexOf("NO CARRIER") != -1 || resp.indexOf("BUSY") != -1) {
        display.clearDisplay();
        display.setCursor(0,20);
        display.println(F("CALL ENDED"));
        display.display();
        delay(2000);
        return;
      }
    }
    
    display.fillRect(0, 50, 128, 14, BLACK);
    display.setCursor(0, 50);
    display.println(F("[SELECT] HANG UP"));
    display.display();
    delay(100);
  }
}

void hangUp() {
  simSerial.println("ATH");
  display.clearDisplay();
  display.setCursor(0, 20);
  display.println(F("ENDING..."));
  display.display();
  delay(1000);
}