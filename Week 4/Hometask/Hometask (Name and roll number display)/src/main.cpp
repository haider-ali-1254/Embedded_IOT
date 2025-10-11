#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---- OLED setup ----
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void drawPrimitives() {
  display.drawRect(2, 2, 125, 61, SSD1306_WHITE);

}

void drawTextDemo() {
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(25, 32);
  display.setTextSize(1);
  display.println("Haider (1254)");

}

void setup() {
  Wire.begin(21, 22); // ESP32 default I2C pins (SDA=21, SCL=22)

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    // If it fails, check wiring and address (0x3C/0x3D)
    for (;;);
  }



  // Example 2: shapes
  display.clearDisplay();
  drawPrimitives();
  display.display();
  delay(5000);

  // Example 1: text formatting
  //display.clearDisplay();
  drawTextDemo();
  display.display();
  delay(5000);

  
}

void loop() {
  
}
