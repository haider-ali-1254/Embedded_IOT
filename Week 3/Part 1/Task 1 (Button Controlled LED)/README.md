# Week 3 Part 1 - Timer Controlled LED

**Name:** Haider Ali
**Roll No:** 23-NTU-CS-1254  

## Description
This project uses an ESP32 hardware timer to blink an LED every 0.5 seconds using timer interrupts.  
The LED toggles only when the button is enabled — pressing the button toggles the LED on/off functionality.

## Components
- ESP32 Development Board
- On-board LED (GPIO 5)
- Push Button (GPIO 34)

# Week 3 — Timer Controlled LED

Author: **Haider Ali**  
Roll No: **23-NTU-CS-1254**

---

This small project demonstrates how to use an ESP32 hardware timer together with a GPIO interrupt to blink an LED at a precise 0.5 second interval. A push-button toggles the blinking functionality on and off. Debounce logic is included to avoid false triggers.

## Highlights
- Timer-driven, non-blocking LED blink (0.5 s)
- Button-controlled enable/disable using a GPIO interrupt
- Simple software debounce inside the ISR

## Components
- ESP32 development board
- On-board LED (GPIO 5)
- Push button (GPIO 34)

## Wiring / Pinout
| Signal | Board pin |
|---|---:|
| LED | GPIO 5 |
| Button (input) | GPIO 34 (internal pull-up used) |

> Note: Confirm pins in `src/main.cpp` if your board differs.

## How it works
1. A hardware timer is configured to tick at 1 MHz.
2. The timer ISR runs every 500,000 µs (0.5 s) and toggles the LED when blinking is enabled.
3. A falling-edge GPIO interrupt on the button toggles the `ledEnabled` flag.
4. Debounce logic (using a timestamp check) prevents multiple toggles from a single press.

## Quick start (PlatformIO)
1. Open the project in VS Code with PlatformIO installed.
2. Build and upload:

```
platformio run --target upload
```

## Notes
- The main loop is intentionally empty — the program is interrupt-driven.
- If you change pins, update `src/main.cpp` accordingly.

---

Licensed to the author above. For questions, inspect `src/main.cpp` or open an issue.
