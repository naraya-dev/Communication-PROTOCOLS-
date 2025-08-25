# Communication-PROTOCOLS-
“Comprehensive Arduino communication protocol experiments: UART, SPI, I²C, 1-Wire, and parallel interfaces, plus networking with TCP/IP and UDP. Covers hardware connections, sample code, and practical applications for embedded and IoT systems.”
# 📡 Embedded Communication Protocols Experiment
_Send DHT20 + Ultrasonic data over UART, I²C, SPI, 1-Wire, Parallel, CAN/LIN (theory), and TCP/UDP/IP. Compare speed, reliability, code/complexity, and wiring._

![status](https://img.shields.io/badge/status-active-brightgreen) 

## ✨ Highlights
- Read sensors: **DHT20 (temp/humidity over I²C)** and **HC-SR04 (ultrasonic distance)**
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

## ⚙️ Sensor Setup
### DHT20 Reading (I²C)
```cpp
#include <Wire.h>
#include <Adafruit_AHTX0.h>
Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  if (!aht.begin()) {
    Serial.println("DHT20/AHT20 not found!");
    while (1);
  }
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);
  Serial.print("Temp: "); Serial.print(temp.temperature, 2);
  Serial.print("°C, Hum: "); Serial.print(humidity.relative_humidity, 2);
  Serial.println("%");
  delay(1000);
}



