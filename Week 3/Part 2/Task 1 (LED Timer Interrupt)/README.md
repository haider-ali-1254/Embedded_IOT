## Week 3 — Timer Interrupt Blink (1s)

Author: **Haider Ali**  
Roll No: **23-NTU-CS-1254**

## Description
---

A focused demo of using an ESP32 hardware timer to toggle an LED every second via an interrupt — no blocking `delay()` calls. Useful as a template for time-critical or low-power applications.

## Components
- ESP32 development board
- On-board LED (GPIO 5)

## Wiring / Pinout
| Signal | Board pin |
|---|---:|
| LED | GPIO 5 |

## Working
1. Initialize a hardware timer at 1 MHz (1 µs tick).
2. Configure the timer to call an ISR every 1,000,000 µs.
3. The ISR toggles the LED state.

## Learning Outcomes
## Quick start (PlatformIO)
Upload the firmware:

```
platformio run --target upload
```

## Code Author
---

See `src/main.cpp` for the full source and comments.
