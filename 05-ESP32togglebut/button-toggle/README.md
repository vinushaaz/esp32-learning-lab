# ESP32 Button Toggle

## Project Overview

This project uses an ESP32 and a push button to control an onboard LED.

Each button press toggles LED blinking ON or OFF. The firmware is developed using ESP-IDF and FreeRTOS.

## Hardware Requirements

- ESP32 DevKit V1
- Push button
- Breadboard
- Jumper wires

## GPIO Connections

| Component | ESP32 GPIO |
|---|---|
| Onboard LED | GPIO 2 |
| Push button | GPIO 18 |
| Button other terminal | GND |

The button uses the ESP32's internal pull-up resistor.

## Working Principle

1. The LED starts in the OFF state.
2. Press the button once to start LED blinking.
3. Press the button again to stop blinking.
4. The firmware uses a 30 ms debounce interval to avoid false button detections.

## Firmware Configuration

| Parameter | Value |
|---|---|
| LED GPIO | GPIO 2 |
| Button GPIO | GPIO 18 |
| Blink interval | 500 ms |
| Debounce interval | 30 ms |

## Software Requirements

- ESP-IDF
- Visual Studio Code
- ESP-IDF VS Code Extension

## Build and Flash

1. Open the project folder in VS Code.
2. Select ESP32 as the target.
3. Build the project.
4. Connect the ESP32 through USB.
5. Select the correct serial port.
6. Flash the firmware.
7. Open the serial monitor.

## Testing

The firmware was built and flashed successfully on an ESP32 DevKit V1.

The push button was tested with the onboard LED:

- First press: LED blinking ON.
- Second press: LED blinking OFF.

Serial monitor output confirms the toggle state.

## Project Status

**Completed:** Button-controlled LED blinking using ESP-IDF and FreeRTOS.
