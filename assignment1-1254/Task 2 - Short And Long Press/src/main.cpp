// Title: Assignment 1 - Task (b)
// Name: Haider Ali
// Roll Number: 23-NTU-CS-FL-1254

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

// Pin Definitions (same as Task A)
#define RED_LED     4
#define GREEN_LED   2
#define BLUE_LED    5
#define BUZZER_PIN  27
#define BUTTON_PIN  33  // Using only one button now

// OLED Setup
#define OLED_SDA 21
#define OLED_SCL 22
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Debounce + press timing
#define DEBOUNCE_DELAY 50
#define LONG_PRESS_TIME 1500

unsigned long buttonPressedTime = 0;
unsigned long buttonReleasedTime = 0;
bool buttonState = HIGH;
bool lastButtonState = HIGH;
bool ledsOn = false;
bool isPressing = false;
unsigned long lastDebounceTime = 0;

void updateDisplay(const char* message) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 20);
  display.println(message);
  display.display();
}

void setup() {
  Serial.begin(115200);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  updateDisplay("Task (b): Ready!");
}

void toggleLEDs() {
  ledsOn = !ledsOn;
  digitalWrite(RED_LED, ledsOn);
  digitalWrite(GREEN_LED, ledsOn);
  digitalWrite(BLUE_LED, ledsOn);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  // Debouncing
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        buttonPressedTime = millis();
        isPressing = true;
      } else {
        buttonReleasedTime = millis();
        isPressing = false;

        unsigned long pressDuration = buttonReleasedTime - buttonPressedTime;

        if (pressDuration < LONG_PRESS_TIME) {
          toggleLEDs();
          updateDisplay("Short Press: LEDs Toggled");
          Serial.println("Short Press detected: LEDs toggled");
        } else {
          tone(BUZZER_PIN, 1000, 500);
          updateDisplay("Long Press: Buzzer ON");
          Serial.println("Long Press detected: Buzzer played");
        }
      }
    }
  }

  lastButtonState = reading;
}
