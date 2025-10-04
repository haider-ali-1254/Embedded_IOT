# Week 3 Part 1 - Timer Controlled LED
# Week 3 — Debounced Timer LED

Author: **Haider Ali**  
Roll No: **23-NTU-CS-1254**

---

This project pairs a hardware timer with a GPIO button interrupt to blink an LED every 0.5s when enabled. The button toggles blinking and includes simple debounce to avoid spurious triggers.

## Features
- 0.5 second timer-based blink
- Button toggles blinking (debounced)
- Clean separation of ISR logic and main loop

## Components
- ESP32 development board
- On-board LED (GPIO 5)
- Push button (GPIO 34)

## Wiring / Pinout
| Signal | Board pin |
|---|---:|
| LED | GPIO 5 |
| Button (input) | GPIO 34 (use internal pull-up) |

## How it works
1. Timer configured at 1 MHz toggles the LED every 500,000 µs when enabled.
2. Button ISR flips `ledEnabled` and uses a timestamp check (`millis()`) to debounce.
3. When disabled, LED is forced LOW.

## Quick start (PlatformIO)
Build and upload:

```
platformio run --target upload
```

## Tips
- Tweak debounce interval in `src/main.cpp` if your button is noisy.
- Verify GPIO numbers for your board variant.

---

Source code in `src/main.cpp`.
