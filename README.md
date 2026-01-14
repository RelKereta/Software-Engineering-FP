# Smart Environmental Protection System (SEPS)
### COMP6100001 - Software Engineering Final Project
**BINUS University International - ODD Semester 2025/2026**

---

## Project Overview
This project is a Smart City prototype designed to address **Smart environmental monitoring** and **Smart public safety**. The system utilizes an ESP32 microcontroller to monitor real-time weather conditions, specifically rain and wind speed. 

When hazardous weather is detected (Rain or High Wind), the system automatically triggers a physical protection mechanism (Servos) to shield infrastructure or assets, such as an automated drying rack or a retractable roof system.

## Features
* **Real-time Wind Monitoring:** Uses an anemometer with an Interrupt Service Routine (ISR) for high-precision pulse counting.
* **Rain Detection:** Dual-layer monitoring using digital signals for immediate response.
* **Automated Actuation:** Two high-torque servos deploy protective covers when thresholds are met (Wind > 2.0 m/s or Rain detected).
* **Visual Status Updates:** 16x2 I2C LCD displays current wind speed and rain status for user convenience.
* **Data Integrity:** Implements interrupt management (`cli()` and `sei()`) to ensure sensor data isn't corrupted during processing.

## Hardware Requirements
* **Microcontroller:** ESP32 (NodeMCU)
* **Sensors:**
    * Rain Sensor Module (Digital/Analog)
    * Anemometer (Wind Speed Sensor)
* **Actuators:**
    * 2x MG995 or SG90 Servo Motors
* **Display:** 16x2 LCD with I2C Backpack
* **Others:** Breadboard, Jumper Wires, 5V External Power Supply (for servos)

## Software & Libraries
* **Arduino IDE**
* **Libraries:**
    * `ESP32Servo`
    * `LiquidCrystal_I2C`
    * `Wire.h` (Standard I2C)

## Pin Mapping
| Component | ESP32 GPIO |
| :--- | :--- |
| Rain Sensor (Digital) | 19 |
| Rain Sensor (Analog) | 18 |
| Wind Sensor (Pulse) | 14 |
| Rain Servo (PWM) | 13 |
| Wind Servo (PWM) | 26 |
| LCD SDA | 21 |
| LCD SCL | 22 |


## Team Contributions
* **Farrell Sevillen Arya:** System Architecture & Logic Development
* **Teuku Agrianshah Pradipta:** Hardware Integration & Prototype Assembly
* **Daniel Lim:** Documentation & Requirements Analysis

## 🔗 Links
* **YouTube Demo:** https://youtube.com/shorts/k0SsQ3Ksuuk?si=gW7kUHc6kqfy8HlW
* **GitHub Repository:** https://github.com/RelKereta/Software-Engineering-FP
