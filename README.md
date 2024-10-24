
# Bluetooth-Motor-Sensor Control System

This project implements a system that controls motors and sensors using an Arduino Uno with Bluetooth communication and an ultrasonic sensor for distance measurement. The system allows users to send commands via a mobile app to control motor actions and read sensor data in real-time.

## Features
- Bluetooth control for motor operation.
- Ultrasonic sensor for distance measurement.
- Real-time motor control via mobile app (LightBlue).

## Requirements
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- Adafruit Motor Shield V1
- Bluetooth Module AT-09
- Arduino IDE
- AFMotor Library
- NewPing Library

## Circuit Diagram
![Circuit Diagram](path/to/circuit-diagram.png)

## Getting Started

### Prerequisites
- [Arduino IDE](https://www.arduino.cc/en/software)
- Install the required libraries in the Arduino IDE:
  1. `AFMotor`: For motor control with Adafruit Motor Shield.
  2. `NewPing`: For ultrasonic sensor distance measurement.

### Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/MoustAhmed/Bluetooth-Motor-Sensor.git
