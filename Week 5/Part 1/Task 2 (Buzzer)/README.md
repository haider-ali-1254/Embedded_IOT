# Week 4 Part 2 - OLED Display Text
# Week 5 — Buzzer Beep Project

Author: **Haider Ali**  
Roll No: **23-NTU-CS-1254**

---

This project demonstrates driving a buzzer (piezo) from an ESP32. It produces a simple tone pattern useful for alerts or feedback in embedded projects.

## Components
- ESP32 development board
- Passive buzzer or piezo speaker
- Current-limiting resistor (optional, depending on buzzer)

## Wiring / Pinout
| Signal | Board pin |
|---|---:|
| Buzzer + | Check `src/main.cpp` (configured GPIO) |
| Buzzer - | GND |

## How it works
- The sketch toggles a GPIO at the desired frequency to create an audible tone.
- Patterns or durations can be adjusted in `src/main.cpp`.

## Quick start (PlatformIO)
Build and upload:

```
platformio run --target upload
```

## Safety
- Keep volume/time reasonable to avoid damage to the buzzer or hearing.

---

See `src/main.cpp` for frequency and pattern configuration.
