// Title: Assignment 1 - Task (a)
// Name: Haider Ali
// Roll Number: 23-NTU-CS-FL-1254

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

// Pin Definitions
#define RED_LED 4
#define GREEN_LED 2
#define BLUE_LED 5
#define BUZZER_PIN 27
#define BUTTON1_PIN 33
#define BUTTON2_PIN 32

// OLED Setup
#define OLED_SDA 21
#define OLED_SCL 22
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Debounce time
#define DEBOUNCE_DELAY 200

// LED Modes
enum Mode {
  OFF,
  ALT_BLINK,
  ON,
  PWM_FADE
};

volatile Mode currentMode = OFF;

// Flags to signal button presses
volatile bool button1Pressed = false;
volatile bool button2Pressed = false;

// === Function Prototypes ===
void updateDisplay(Mode mode);
void updateLEDs(Mode mode);
void changeMode(Mode newMode);

// === Interrupt Handlers ===
void IRAM_ATTR HandleButton1Press() {
  static unsigned long lastInterruptTime = 0;
  unsigned long now = millis();
  if (now - lastInterruptTime > DEBOUNCE_DELAY) {
    button1Pressed = true;
    lastInterruptTime = now;
  }
}

void IRAM_ATTR HandleButton2Press() {
  static unsigned long lastInterruptTime = 0;
  unsigned long now = millis();
  if (now - lastInterruptTime > DEBOUNCE_DELAY) {
    button2Pressed = true;
    lastInterruptTime = now;
  }
}

// === OLED Update Function ===
void updateDisplay(Mode mode) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2);
  switch (mode) {
    case OFF:
      display.println("Mode: LEDs OFF");
      break;
    case ALT_BLINK:
      display.println("Mode: ALT BLINK");
      break;
    case ON:
      display.println("Mode: LEDs ON");
      break;
    case PWM_FADE:
      display.println("Mode: PWM FADE");
      break;
  }
  display.display();
}

// === LED Behavior Function ===
void updateLEDs(Mode mode) {
  static unsigned long previousMillis = 0;
  static bool ledState = false;
  static int fadeValue = 0;
  unsigned long currentMillis = millis();

  switch (mode) {
    case OFF:
      ledcWrite(0, 0);
      ledcWrite(1, 0);
      ledcWrite(2, 0);
      break;

    case ALT_BLINK:
      if (currentMillis - previousMillis >= 500) {
        previousMillis = currentMillis;
        ledState = !ledState;
        if (ledState) {
          // Red + Blue ON, Green OFF
          ledcWrite(0, 255);
          ledcWrite(1, 0);
          ledcWrite(2, 255);
        } else {
          // Green ON, others OFF
          ledcWrite(0, 0);
          ledcWrite(1, 255);
          ledcWrite(2, 0);
        }
      }
      break;

    case ON:
      ledcWrite(0, 255);
      ledcWrite(1, 255);
      ledcWrite(2, 255);
      break;

    case PWM_FADE:
      fadeValue = (fadeValue + 5) % 256;
      ledcWrite(0, fadeValue);
      ledcWrite(1, fadeValue);
      ledcWrite(2, fadeValue);
      delay(30);
      break;
  }
}

// === Change Mode Function ===
void changeMode(Mode newMode) {
  currentMode = newMode;
  updateDisplay(currentMode);
}

// === Setup ===
void setup() {
  Serial.begin(115200);

  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // PWM setup (ESP32)
  ledcSetup(0, 5000, 8);
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);
  ledcAttachPin(RED_LED, 0);
  ledcAttachPin(GREEN_LED, 1);
  ledcAttachPin(BLUE_LED, 2);

  // OLED setup
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }
  display.clearDisplay();
  updateDisplay(currentMode);

  attachInterrupt(digitalPinToInterrupt(BUTTON1_PIN), HandleButton1Press, FALLING);
  attachInterrupt(digitalPinToInterrupt(BUTTON2_PIN), HandleButton2Press, FALLING);
}

// === Main Loop ===
void loop() {
  if (button1Pressed) {
    button1Pressed = false;
    // Cycle through modes
    if (currentMode == PWM_FADE)
      changeMode(OFF);
    else
      changeMode((Mode)(currentMode + 1));
  }

  if (button2Pressed) {
    button2Pressed = false;
    changeMode(OFF);
  }

  updateLEDs(currentMode);
}
