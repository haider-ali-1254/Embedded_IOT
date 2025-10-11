# Week 4 Part 2 - OLED Display Text
# Week 4 — OLED Display Text (SSD1306)

Author: **Haider Ali**  
Roll No: **23-NTU-CS-1254**

---

This project demonstrates using an SSD1306-based OLED with the ESP32 over I2C. It initializes the display, draws simple graphics, and prints text using Adafruit GFX/SSD1306 libraries.

## Features
- Initialize SSD1306 (0x3C) over I2C
- Draw primitives and render text
- Simple animation switching between graphics and text

## Components
- ESP32 development board
- SSD1306 OLED (0.96" or 1.3", 128x64)
- I2C connection: SDA = GPIO 21, SCL = GPIO 22 (default)

## Wiring / Pinout
| Signal | Board pin |
|---|---:|
| SDA | GPIO 21 |
| SCL | GPIO 22 |

## How it works
1. The display is initialized with I2C address 0x3C.
2. The sketch draws two diagonal lines (an X), pauses, then clears the screen.
3. Two text messages are printed in different sizes and positions.
4. The display cycles between graphics and text every ~2 seconds.

## Quick start (PlatformIO)
Install required libraries and upload:

```
platformio run --target upload
```

## Notes
- If your display uses a different I2C address (0x3D) update `src/main.cpp`.
- Ensure the Adafruit GFX and SSD1306 libraries are available in `platformio.ini` or the lib folder.

---

See `src/main.cpp` for exact initialization and drawing code.
