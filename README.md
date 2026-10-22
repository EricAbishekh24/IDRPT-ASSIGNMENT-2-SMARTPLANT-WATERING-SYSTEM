# IDRPT ASSIGNMENT 2 - SMART PLANT WATERING SYSTEM

An automated IoT-based plant watering system built with ESP32 that monitors soil moisture levels and controls a DC water pump via a relay module.

---

## 📌 Project Overview

This project automatically detects soil dryness and activates water delivery to keep plants healthy without manual intervention. It includes real-time serial monitoring of sensor values and moisture percentages.

### Key Features
- **Automatic Watering**: Compares soil moisture against a calibrated threshold.
- **Relay Controlled Pump**: Active-LOW relay switching for the DC water pump.
- **Pump Safety Timer**: Automatic cutoff after `5000 ms` to avoid overwatering or pump burn-out.
- **Hysteresis Control**: Shuts off pump once moisture exceeds threshold by +5% to prevent rapid on/off cycling.
- **ESP32 Microcontroller**: Fast analog reading and IoT-ready architecture (compatible with Blynk & ThingSpeak).

---

## 🛠️ Hardware Components

| Component | Description |
|---|---|
| **ESP32 Dev Board** | Main microcontroller running the control logic |
| **Soil Moisture Sensor** | Soil moisture probe (Analog output) |
| **Relay Module** | Single-channel relay (Active LOW) to switch the pump |
| **DC Water Pump** | Submersible water pump |
| **Power Supply** | 5V / 12V DC power source |
| **Tubing & Jumper Wires** | Silicon water pipe and wiring |

---

## 🔌 Pin Connections

| Device Pin | ESP32 GPIO | Description |
|---|---|---|
| **Soil Moisture Sensor (A0)** | `GPIO 34` | Analog input (reads ESP32 ADC) |
| **Relay Module (IN)** | `GPIO 26` | Digital output (LOW = Pump ON, HIGH = Pump OFF) |
| **Sensor VCC / GND** | `3.3V` / `GND` | Power connection for moisture sensor |
| **Relay VCC / GND** | `5V` / `GND` | Power connection for relay coil |

---

## 📂 Repository Contents

- [`Smart_Plant_Watering_System.ino`](./Smart_Plant_Watering_System.ino) — Arduino source code for ESP32.
- [`Circuit diagram.jpg`](./Circuit%20diagram.jpg) — Wiring and circuit schematic.
- [`components.png`](./components.png) — Visual component breakdown, wiring guide, and workflow diagram.
- [`IDRPT ASSIGNMENT 2 - SMART PLANT WATERING SYSTEM (REPORT) .pdf`](./IDRPT%20ASSIGNMENT%202%20-%20SMART%20PLANT%20WATERING%20SYSTEM%20(REPORT)%20.pdf) — Project documentation and assignment report.
- [`Smart_Plant_Watering_System_Demo (1).mp4`](./Smart_Plant_Watering_System_Demo%20(1).mp4) — Demonstration video showing system operation.

---

## 🚀 How to Run

1. Open [`Smart_Plant_Watering_System.ino`](./Smart_Plant_Watering_System.ino) in **Arduino IDE**.
2. Select your board: `Tools` > `Board` > `esp32` > `ESP32 Dev Module`.
3. Select your serial port under `Tools` > `Port`.
4. Calibrate `dryValue` and `wetValue` in the code based on your sensor readings.
5. Click **Upload** and open the **Serial Monitor** at `115200` baud.
