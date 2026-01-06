# 🎮 ESP32 Tetris (VGA Compatible)

This project is a **playable Tetris game implemented on the ESP32 microcontroller with VGA output**.  
It demonstrates real-time graphics generation, input handling, collision detection, and game logic optimized for embedded systems.

The project was developed using the **Arduino IDE** and leverages the ESP32’s processing capabilities to deliver smooth gameplay on a VGA display.

---

## 🧠 Project Overview

- VGA-based graphics output using ESP32
- Button-controlled gameplay
- Real-time collision detection
- Line clearing logic
- Score management
- Optimized for embedded constraints

This project blends **gaming logic with low-level embedded programming**, showcasing the ESP32 as a capable platform for real-time graphics applications.

---

## 🛠️ Tech Stack

- **Microcontroller:** ESP32  
- **Programming Language:** C++ (Arduino)  
- **IDE:** Arduino IDE  
- **Graphics:** VGA (FabGL library)  
- **Input:** Physical push buttons  

---

## 🎮 Game Features

- Classic Tetris gameplay
- Falling tetrominoes
- Rotation, movement, and soft drop
- Collision detection with board & pieces
- Line clear detection
- Score increment per cleared line
- VGA rendering at 640×480 resolution

---

## 🔌 Hardware Requirements

- ESP32 Dev Board
- VGA DAC resistor network (RGB + HSync + VSync)
- VGA monitor
- Push buttons:
  - Left
  - Right
  - Rotate
  - Down
- Breadboard & jumper wires

---

## 📂 Project Structure

```text
esp32-tetris-vga/
├── esp32_tetris_vga.ino
└── README.md
