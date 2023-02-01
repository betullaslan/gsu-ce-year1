# Smart Trash Bin (Arduino Project)

This project demonstrates a simple contactless smart trash bin system using an Arduino, an ultrasonic sensor, and a servo motor.

When a hand is detected within 12 centimeters, the trash bin lid opens automatically using a servo motor, and closes again after 3 seconds — allowing the user to throw away waste without touching the bin.

---

## Project Info

- **Project Name:** Smart Trash Bin  
- **Language:** Arduino (C++)
- **Author:** Betul Aslan

---

## Academic Info

- **Course:** Introduction to Programming
- **Institution:** Galatasaray University  
- **Department:** Computer Engineering  
- **Academic Year:** 2022–2023 Fall 
- **Assignment:** Term Project

---

## Components Used

- Arduino Uno
- Ultrasonic Distance Sensor (HC-SR04)
- Servo Motor (SG90)
- Jumper wires and breadboard
- (Optional) Plastic lid attached to servo arm

---

## How It Works

1. The ultrasonic sensor continuously measures distance to detect a hand.
2. If a hand is detected closer than 12 cm:
   - The servo motor rotates to open the bin lid (90 degrees).
   - A message is printed via serial: "La poubelle est ouverte"
   - After 3 seconds, the servo rotates back to 0 degrees to close the lid.
   - Message printed: "La poubelle est fermee"

---

## Circuit Connections

| Component         | Arduino Pin |
|------------------|-------------|
| Ultrasonic Trig  | D7          |
| Ultrasonic Echo  | D6          |
| Servo Signal     | D9          |

---

## Files

- `smart_trash_bin.ino` — Contains the full Arduino sketch. Original comments are in French.

## Notes

Original code comments are written in French for academic documentation purposes.  
This README is in English for accessibility and clarity on GitHub.
