# 🔆 ESP32 RGB LED Controller with OLED Display

**Author:** Haider Ali  
**Roll Number:** 23-NTU-CS-FL-1254  
**Assignment 1 – Task (a)**  

This project demonstrates an **ESP32-based RGB LED controller** featuring multiple LED modes, an **OLED display interface**, and **button-controlled mode switching** with **hardware interrupts** and **PWM fading effects**.

---

## 🎥 Demo Video

<video src="demo/demo.mp4" controls width="600"></video>

---

## 🌟 Features

✅ Smooth **PWM LED fading** using ESP32's hardware LEDC channels  
✅ **OLED display** showing the current LED mode  
✅ **Button interrupts** for mode changes and immediate LED OFF  
✅ Clean **debounce logic** for reliable button inputs  
✅ Modular, readable, and efficient code structure  

---

## 🧩 System Overview

| Component | Description |
|------------|-------------|
| **Microcontroller** | ESP32 Dev Module |
| **Display** | SSD1306 0.96" OLED (I2C) |
| **LEDs** | RGB LEDs (Common Cathode) |
| **Buttons** | 2x Push Buttons |
| **Buzzer** | Passive buzzer (optional feedback) |

---

## ⚙️ Pin Configuration

| Component | Pin | Mode | Description |
|------------|-----|------|-------------|
| 🔴 **Red LED** | 4 | Output (PWM) | LEDC Channel 0 |
| 🟢 **Green LED** | 2 | Output (PWM) | LEDC Channel 1 |
| 🔵 **Blue LED** | 5 | Output (PWM) | LEDC Channel 2 |
| 🔔 **Buzzer** | 27 | Output | Optional sound feedback |
| ⬇️ **Button 1** | 33 | Input (Pull-up) | Cycle between modes |
| ⏹️ **Button 2** | 32 | Input (Pull-up) | Immediately turn LEDs off |
| 🖥️ **OLED SDA** | 21 | I2C Data | OLED Communication |
| 🖥️ **OLED SCL** | 22 | I2C Clock | OLED Communication |

---

## 💡 LED Modes

| Mode | Description | Behavior |
|------|--------------|-----------|
| **0. OFF** | All LEDs OFF | Rest state |
| **1. ALT_BLINK** | Alternate Red+Blue ↔ Green | Blinks every 0.5 seconds |
| **2. ON** | All LEDs ON | Constant illumination |
| **3. PWM_FADE** | Fading effect | Smooth brightness cycling via PWM |

---

## 🖼️ OLED Display Output

The OLED dynamically updates to show the current mode:
```
Mode: LEDs OFF
Mode: ALT BLINK
Mode: LEDs ON
Mode: PWM FADE
```

---

## 🧠 Technical Highlights

- Uses **`ledcWrite()`** for PWM control (ESP32-specific)
- **Interrupt-based mode switching** for responsiveness  
- **OLED feedback** using the Adafruit SSD1306 + GFX libraries  
- **Non-blocking blink logic** with `millis()` timing  
- Compact and maintainable modular design  

---

## 🧰 Libraries Used

| Library | Purpose |
|----------|----------|
| `Adafruit_GFX.h` | Core graphics library for OLED |
| `Adafruit_SSD1306.h` | OLED display driver |
| `Wire.h` | I2C communication |
| `Arduino.h` | Base Arduino functionality |

---

## 🚀 How to Run

1. Open the project in **PlatformIO** or **Arduino IDE**  
2. Select your **ESP32 board**  
3. Install required libraries via Library Manager  
4. Upload the code  
5. Press the buttons and observe the OLED & LED behavior ✨  

---

## 📁 Folder Structure

```
📂 ESP32_RGB_Controller
 ┣ 📂 src
 ┃ ┗ main.cpp
 ┣ 📂 demo
 ┃ ┗ demo.mp4
 ┣ 📄 platformio.ini / .ino file
 ┣ 📄 README.md
```

---

## 🧾 License

This project is for **educational use** only and part of the **Embedded Systems (IoT)** coursework at **NTU Faisalabad**.

---

✨ *“Turning simple LEDs into smart displays — one blink at a time!”*
