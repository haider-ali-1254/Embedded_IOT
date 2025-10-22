# Embedded IoT Projects

This repository contains weekly assignments and tasks completed as part of the **Embedded Systems & IoT** course.  
Each week introduces new microcontroller programming concepts using PlatformIO and C++, such as GPIO/button control, timers/interrupts, PWM/buzzer, and sensor interfacing.

---

## 📚 Weekly Index

| Week  | Part / Task                                | Description                         | Link                                  |
|-------|--------------------------------------------|-------------------------------------|---------------------------------------|
| Week 3 | Part 1 – Task 1 (Button Controlled LED)     | A button toggles an LED             | [`Week 3/Part 1/Task 1 (Button Controlled LED)`](./Week%203/Part%201/Task%201%20(Button%20Controlled%20LED)) |
|       | Part 1 – Task 2 (Dual Light Switch)         | Two switches control two lights     | [`Week 3/Part 1/Task 2 (Dual Light Switch)`](./Week%203/Part%201/Task%202%20(Dual%20Light%20Switch)) |
|       | Part 2 – Task 1 (LED Timer Interrupt)       | LED toggling using timer interrupt  | [`Week 3/Part 2/Task 1 (LED Timer Interrupt)`](./Week%203/Part%202/Task%201%20(LED%20Timer%20Interrupt)) |
|       | Part 2 – Task 2 (Debounced LED Toggle)      | Debouncing a button for LED toggle  | [`Week 3/Part 2/Task 2 (Debounced LED Toggle)`](./Week%203/Part%202/Task%202%20(Debounced%20LED%20Toggle)) |
| Week 4 | Hometask – Name & Roll Number Display       | Display of student name & roll no   | [`Week 4/Hometask/Hometask (Name and roll number display)`](./Week%204/Hometask/Hometask%20(Name%20and%20roll%20number%20display)) |
|       | Part 1 – Task 1 (LED Blink Using Timer)     | Blinking LED via timer              | [`Week 4/Part 1/Task 1 (LED BLINK USING TIMER)`](./Week%204/Part%201/Task%201%20(LED%20BLINK%20USING%20TIMER)) |
|       | Part 2 – Task 1 (LED Display Text)          | Displaying text using LED           | [`Week 4/Part 2/Task 1 (led-display-text)`](./Week%204/Part%202/Task%201%20(led-display-text)) |
| Week 5 | Bonus Task – Super Mario Tune                | Playing Super Mario tune with buzzer| [`Week 5/Bonus Task (Super Mario Tune)`](./Week%205/Bonus%20Task%20(Super%20Mario%20Tune)) |
|       | Part 1 – Task 1 (PWM LED)                   | PWM control of LED brightness       | [`Week 5/Part 1/Task 1 (PWM LED)`](./Week%205/Part%201/Task%201%20(PWM%20LED)) |
|       | Part 1 – Task 2 (Buzzer)                    | Buzzer tone control                 | [`Week 5/Part 1/Task 2 (Buzzer)`](./Week%205/Part%201/Task%202%20(Buzzer)) |
|       | Part 2 – Task 1 (LED + Buzzer)              | Combined LED and buzzer control     | [`Week 5/Part 2/Task 1 (LED + BUZZER)`](./Week%205/Part%202/Task%201%20(LED%20%2B%20BUZZER)) |
| Week 6 | Part 1 – Task 1 (Temperature Sensor)        | Reading temperature sensor          | [`Week 6/Part 1/Task 1 (Temprature Sensor)`](./Week%206/Part%201/Task%201%20(Temprature%20Sensor)) |
|       | Part 1 – Task 2 (LDR Sensor)                | Reading light-dependent resistor    | [`Week 6/Part 1/Task 2 (LDR Sensor)`](./Week%206/Part%201/Task%202%20(LDR%20Sensor)) |
|       | Part 1 – Task 3 (Temp + LDR)                | Combined temperature and light      | [`Week 6/Part 1/Task 3 (Temp + LDR)`](./Week%206/Part%201/Task%203%20(Temp%20%2B%20LDR)) |

---

## ⚙️ Platform & Build

All projects are developed using **PlatformIO** (embedded development environment) and the Arduino framework.  

To build and upload a project (inside each folder):  
```bash
platformio run
platformio run --target upload
```

## 🧠 Learning Outcomes
- GPIO and button control

- Timer interrupts and debouncing

- PWM signals and buzzer control

- Sensor interfacing (temperature, LDR)

- Integrating multiple peripherals into combined systems

## 👨‍💻 Author
##### Haider Ali (Roll No: 1254)
##### Embedded Systems & IoT Course – Fall 2025