# Communication-PROTOCOLS-
“Comprehensive Arduino communication protocol experiments: UART, SPI, I²C, 1-Wire, and parallel interfaces, plus networking with TCP/IP and UDP. Covers hardware connections, sample code, and practical applications for embedded and IoT systems.”
# 📡 Embedded Communication Protocols Experiment
_Send DHT22 + Ultrasonic data over UART, I²C, SPI, 1-Wire, Parallel, CAN/LIN (theory), and TCP/UDP/IP. Compare speed, reliability, code/complexity, and wiring._

![status](https://img.shields.io/badge/status-active-brightgreen) 
# 📡 Embedded Communication Protocols Experiment  
_Experimenting with transmitting sensor data (DHT22 + Ultrasonic) using multiple communication techniques between microcontrollers._

---

## ✨ Overview  
This project demonstrates **sending DHT22 temperature & humidity and ultrasonic distance readings** over various communication protocols between two microcontrollers (e.g., Arduino boards or ESP32), and comparing performance, complexity, and scalability.

### Protocols Tested:
- ✅ **UART**
- ✅ **I²C** (MCU-to-MCU)
- ✅ **SPI**
- ✅ **Custom 1-Wire**
- ✅ **Parallel 8-bit with Handshake**
- ✅ **Wi-Fi (UDP/TCP for ESP32)**  
Additional study: **CAN, LIN, TCP/IP layers**

---

## 📂 Repository Layout  


## ✨ Highlights
- Read sensors: **DHT22 (temp/humidity over I²C)** and **HC-SR04 (ultrasonic distance)**
- Transport the readings between microcontrollers using multiple **wired** and **network** protocols
- **Benchmark** throughput, latency, CPU usage, code complexity, and wiring cost
- Reusable **Arduino/ESP** examples for each protocol

---

## 📁 Repo Structure


---

## 🛠 Requirements
- **Microcontrollers**: Arduino Uno/Nano/ESP32
- **Sensors**: DHT22 + HC-SR04
- **Libraries**:
  - `Adafruit AHTX0` (for DHT22)
  - `OneWire` (for custom 1-Wire demo)
  - `WiFi` & `WiFiUDP` (ESP32 networking)

Install via Arduino Library Manager:
Adafruit AHTX0 by Adafruit
OneWire by Paul Stoffregen


---

## please find the attached filea and photos in the file section ##



