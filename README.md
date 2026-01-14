# Smart Environmental Protection System (SEPS)
### COMP6100001 - Software Engineering Final Project
**BINUS University International - ODD Semester 2025/2026**

---

## Project Overview
[cite_start]This project is a Smart City prototype designed to address **Smart environmental monitoring** and **Smart public safety**[cite: 17, 19]. [cite_start]The system utilizes an ESP32 microcontroller to monitor real-time weather conditions, specifically rain and wind speed[cite: 10, 12]. 

[cite_start]When hazardous weather is detected (Rain or High Wind), the system automatically triggers a physical protection mechanism (Servos) to shield infrastructure or assets, such as an automated drying rack or a retractable roof system[cite: 13, 24].

## Features
* [cite_start]**Real-time Wind Monitoring:** Uses an anemometer with an Interrupt Service Routine (ISR) for high-precision pulse counting[cite: 59].
* [cite_start]**Rain Detection:** Dual-layer monitoring using digital signals for immediate response[cite: 47].
* [cite_start]**Automated Actuation:** Two high-torque servos deploy protective covers when thresholds are met (Wind > 2.0 m/s or Rain detected)[cite: 13].
* [cite_start]**Visual Status Updates:** 16x2 I2C LCD displays current wind speed and rain status for user convenience[cite: 47].
* [cite_start]**Data Integrity:** Implements interrupt management (`cli()` and `sei()`) to ensure sensor data isn't corrupted during processing[cite: 54].

## Hardware Requirements
* [cite_start]**Microcontroller:** ESP32 (NodeMCU) [cite: 10, 65]
* **Sensors:**
    * [cite_start]Rain Sensor Module (Digital/Analog) [cite: 65]
    * [cite_start]Anemometer (Wind Speed Sensor) [cite: 65]
* **Actuators:**
    * [cite_start]2x MG995 or SG90 Servo Motors [cite: 65]
* [cite_start]**Display:** 16x2 LCD with I2C Backpack [cite: 65]
* **Others:** Breadboard, Jumper Wires, 5V External Power Supply (for servos)

## Software & Libraries
* [cite_start]**Arduino IDE** [cite: 65]
* **Libraries:**
    * [cite_start]`ESP32Servo` [cite: 65]
    * [cite_start]`LiquidCrystal_I2C` [cite: 65]
    * [cite_start]`Wire.h` (Standard I2C) [cite: 65]

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

## How to Use
1. **Clone the repo:** `git clone [Your-GitHub-Link-Here]`
2. **Install Libraries:** Ensure the libraries listed above are installed via the Arduino Library Manager.
3. **Hardware Setup:** Connect the sensors and servos according to the Pin Mapping table.
4. **Upload:** Open the `.ino` file in Arduino IDE and upload it to your ESP32.
5. **Monitor:** Open the Serial Monitor (115200 baud) or look at the LCD for status updates.

## Team Contributions
* [cite_start]**Farrell Sevillen Arya:** System Architecture & Logic Development [cite: 36]
* [cite_start]**Teuku Agrianshah Pradipta:** Hardware Integration & Prototype Assembly [cite: 36]
* [cite_start]**Daniel Lim:** Documentation & Requirements Analysis [cite: 36]

## 🔗 Links
* **YouTube Demo:** https://youtube.com/shorts/k0SsQ3Ksuuk?si=gW7kUHc6kqfy8HlW
* **GitHub Repository:** [Insert Your GitHub Link Here]
