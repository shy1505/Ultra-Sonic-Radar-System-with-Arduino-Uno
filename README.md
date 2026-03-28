# 📡 Ultrasonic Radar System using Arduino & Processing

## 📌 Overview

This project simulates a radar system using an ultrasonic sensor (HC-SR04), a servo motor (SG90), and Arduino Uno.
The system scans the surroundings by rotating the sensor and visualizes detected objects in real-time using Processing IDE.


## ⚙️ Components Used

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* SG90 Servo Motor
* Jumper Wires
* Breadboard

---

## 🧠 Working Principle

* The servo motor rotates the ultrasonic sensor from 0° to 180°
* At each angle, the sensor measures the distance to nearby objects
* Arduino sends angle + distance data via serial communication
* Processing IDE reads this data and displays it as a radar visualization


## 💻 Code Structure

* `/arduino_code` → Handles sensor + servo + data transmission
* `/processing_code` → Handles radar visualization

---

## 📊 Output

* Real-time object detection
* Radar-style graphical display
* Angle vs distance mapping

---

## 🚀 Features

* Real-time scanning
* Visual radar interface
* Low-cost implementation
* Interactive system

---

## 🚀 Future Improvements

* Increase detection range using better sensors
* Add object classification
* Integrate with camera module
* Convert into obstacle avoidance system

---

## 🧑‍💻 Author

Shyamali Kumari
Electronics Engineering Student, SLIET 2025

---

## ⭐ Star this repo if you like it!
