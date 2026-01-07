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
---

## 🔌 Hardware Connections

### 1. Button Controls (GPIO Wiring)
Connect one side of the button to the GPIO pin and the other side to **GND**. The code uses internal pull-up resistors.

| Function | ESP32 Pin | Logic |
| :--- | :--- | :--- |
| **Move Left** | GPIO 32 | Active Low (GND) |
| **Move Right** | GPIO 33 | Active Low (GND) |
| **Rotate** | GPIO 25 | Active Low (GND) |
| **Soft Drop** | GPIO 26 | Active Low (GND) |

### 2. VGA Wiring
*Requires a standard R-2R resistor ladder or a FabGL-compatible VGA breakout board.*

| VGA Signal | Standard FabGL Pin |
| :--- | :--- |
| **Red** | GPIO 22, 21 |
| **Green** | GPIO 19, 18 |
| **Blue** | GPIO 5, 4 |
| **HSync** | GPIO 23 |
| **VSync** | GPIO 15 |

---
## ▶️ How to Run

1.  **Install Arduino IDE:** Download from [arduino.cc](https://www.arduino.cc/).
2.  **Setup ESP32:** Install "ESP32 by Espressif Systems" in the Boards Manager.
3.  **Install Library:** Search for and install **FabGL** by Fabrizio Di Vittorio in the Library Manager.
4.  **Upload Code:** Copy the source code below into a new sketch (`esp32_tetris_vga.ino`) and upload it to your board.

## 📂 Project Structure

```text
esp32-tetris-vga/
├── esp32_tetris_vga.ino
└── README.md
