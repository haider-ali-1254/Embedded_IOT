# Week 3 Part 1 - Q2 Dual LED Button Control
# Week 3 — Dual LED Button Control

Author: **Haider Ali**  
Roll No: **23-NTU-CS-1254**

---

This exercise shows how a single button can control two LEDs simultaneously using GPIO interrupts on the ESP32. The program is interrupt-driven and keeps the main loop free for other tasks.

## Features
- Toggle two LEDs together with a single push button
- Uses falling-edge GPIO interrupt and internal pull-up
- Minimal, non-blocking design suitable for embedded demos

## Components
- ESP32 development board
- LED A (GPIO 18)
- LED B (GPIO 21)
- Push button (GPIO 35)

## Wiring / Pinout
| Signal | Board pin |
|---|---:|
| LED A | GPIO 18 |
| LED B | GPIO 21 |
| Button (input) | GPIO 35 (internal pull-up) |

## How it works
1. The button is configured with the internal pull-up and a falling-edge interrupt.
2. Each press triggers the ISR which flips a shared `ledState` flag.
3. Both LED outputs are driven according to `ledState` (ON or OFF).
4. The `loop()` does nothing so the system is responsive and non-blocking.

## Quick start (PlatformIO)
Build and upload with PlatformIO:

```
platformio run --target upload
```

## Tips
- Add a small debounce in software if you notice multiple triggers per press.
- Change LED pins in `src/main.cpp` to match your hardware.

---

Source and attribution available in `src/main.cpp`.
