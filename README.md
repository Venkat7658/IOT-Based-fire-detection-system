# 🔥 IoT-Based Fire and Smoke Detection System

An IoT-based Fire and Smoke Detection System using Arduino, MQ2 smoke sensor, flame sensor, buzzer, and LCD display. It alerts users through visual and sound signals when dangerous levels of smoke or fire are detected.

## 🛠️ Components Used
- Arduino UNO
- MQ2 Smoke Sensor
- Flame Sensor (IR)
- Buzzer
- I2C 16x2 LCD Display
- Jumper Wires & Breadboard

## 🚀 Features
- Real-time monitoring of smoke and fire
- LCD displays smoke level (LOW / MEDIUM / HIGH)
- Buzzer alerts in case of high smoke or fire detection
- Serial monitor logs values

## 🔌 Circuit Connections

| Component     | Arduino Pin |
|---------------|-------------|
| MQ2 Sensor    | A0          |
| Flame Sensor  | D8          |
| Buzzer        | D9          |
| I2C LCD       | SDA/SCL     |

> NOTE: Connect I2C LCD SDA to A4 and SCL to A5 for Arduino UNO.

## 📄 How to Use
1. Clone or download this repository.
2. Open `fire_detection.ino` in Arduino IDE.
3. Upload it to your Arduino board.
4. Observe smoke/fire detection and alerts.

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
