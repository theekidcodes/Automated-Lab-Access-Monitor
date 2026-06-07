# Smart Gate System — Automated Lab Access & Environment Monitor

An Arduino-based automated access control and environment monitoring system designed for laboratory entrances. Built as an intermediate-level embedded systems examination project at BotHub Community, University of Lagos.

---

## What It Does

- Detects a person approaching the lab entrance using an ultrasonic sensor
- Automatically opens the gate via a servo motor when presence is detected
- Monitors real-time temperature and humidity using a DHT11 sensor
- Displays LED status indicators — green for safe conditions, red for critical thermal thresholds
- Logs distance, temperature, and door status to the Serial Monitor for debugging

---

## Components

| Component | Purpose |
|---|---|
| Arduino Uno | Microcontroller |
| HC-SR04 Ultrasonic Sensor | Proximity / presence detection |
| SG90 Servo Motor | Gate actuation |
| DHT11 Sensor | Temperature & humidity monitoring |
| LEDs (Red/Green) | Environment status indicators |

---

## How It Works

1. The HC-SR04 continuously measures distance to detect approaching individuals
2. When distance drops below a set threshold, the servo rotates to open the gate
3. The DHT11 reads temperature and humidity every cycle
4. If temperature exceeds the critical threshold, the red LED activates to warn that conditions are unsafe for equipment
5. All readings are streamed to the Serial Monitor as a live telemetry log

---

## Simulation

Circuit designed and simulated using **Tinkercad Education** before physical deployment.

---

## Technologies

- **Platform:** Arduino Uno
- **Language:** C++ (Arduino IDE)
- **Simulation:** Tinkercad Education
- **Sensors:** HC-SR04, DHT11
- **Actuator:** SG90 Servo Motor

---

## Project Context

Developed as part of the BotHub Community Embedded Systems programme at the University of Lagos. Submitted as an intermediate-level examination project under time-constrained team conditions.
