# Week 4 Part 2 - OLED Display Text
# Week 5 — Both Outputs ON

Author: **Haider Ali**  
Roll No: **23-NTU-CS-1254**

---

Simple demo that turns two outputs ON together. Useful for verifying multiple GPIO outputs and combined behavior (for example LED + buzzer or two LEDs).

## Components
- ESP32 development board
- Two LEDs or an LED + buzzer (depending on the exercise)

## Wiring / Pinout
| Signal | Board pin |
|---|---:|
| Output A | See `src/main.cpp` |
| Output B | See `src/main.cpp` |

## Quick start (PlatformIO)
Build and upload:

```
platformio run --target upload
```

## Notes
- Check `src/main.cpp` to confirm which pins are driven high.
- Useful as a sanity check before combining logic with inputs or interrupts.

---

See `src/main.cpp` for implementation details.
