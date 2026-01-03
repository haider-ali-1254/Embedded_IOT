#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --- CONFIGURATION ---
// REPLACE THIS WITH YOUR REAL 15-DIGIT IMEI
// Example: "354123091234567"
const char NEW_IMEI[] = "353420868600985"; 

#define TINY_GSM_MODEM_SIM800
#include <TinyGsmClient.h>

// --- PINS (Matches your previous code) ---
#define SIM_TX      27
#define SIM_RX      26
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// --- OBJECTS ---
HardwareSerial simSerial(1);
TinyGsm modem(simSerial);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  // 1. Init OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 failed"));
    for(;;); // Don't proceed if screen fails
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 10);
  display.println(F("IMEI FLASHER TOOL"));
  display.println(F("Initializing..."));
  display.display();

  // 2. Init Modem Serial
  simSerial.begin(9600, SERIAL_8N1, SIM_RX, SIM_TX);
  delay(1000);

  // 3. Restart Modem to ensure clean state
  display.println(F("Resetting Modem..."));
  display.display();
  if (!modem.restart()) {
    display.println(F("Modem Failed!"));
    display.display();
    while(true);
  }

  // 4. Send IMEI Change Command
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(F("WRITING IMEI..."));
  display.println(NEW_IMEI);
  display.display();
  
  // Send: AT+EGMR=1,7,"12345..."
  modem.sendAT(GF("+EGMR=1,7,\""), NEW_IMEI, GF("\""));
  
  // 5. Check Result
  int result = modem.waitResponse(5000); // Wait up to 5s for OK

  display.setCursor(0, 30);
  display.setTextSize(2);
  
  if (result == 1) {
    display.println(F("SUCCESS!"));
    display.setTextSize(1);
    display.setCursor(0, 50);
    display.println(F("Flash orig code now"));
  } else {
    display.println(F("FAILED!"));
    display.setTextSize(1);
    display.setCursor(0, 50);
    display.println(F("Chk wires / Valid IMEI"));
  }
  display.display();
}

void loop() {
  // Do nothing. Just sit here so you can read the screen.
}