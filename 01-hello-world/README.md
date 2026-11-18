# 01 - ESP32 Hello World & Chip Information

**Framework:** ESP-IDF  
**Language:** C  
**Build System:** CMake  
**Category:** Embedded Systems Fundamentals  
**Status:** Migrated from original repository

## 1. Objective

Understand the basic structure of an ESP-IDF application and explore how to retrieve hardware information from an ESP32 microcontroller.

This experiment introduces firmware execution, chip identification, flash memory information, heap memory monitoring and restart functionality.

## 2. Hardware Requirements

- ESP32 development board
- USB data cable
- Computer

## 3. Software Requirements

- Visual Studio Code
- ESP-IDF Extension
- ESP-IDF toolchain
- CMake
- Serial Monitor

## 4. Concepts Learned

| Concept | Purpose |
|---|---|
| `app_main()` | Entry point of an ESP-IDF application |
| `printf()` | Prints information to the console |
| `esp_chip_info()` | Retrieves ESP32 chip information |
| `esp_flash_get_size()` | Reads flash memory capacity |
| `esp_get_minimum_free_heap_size()` | Retrieves minimum free heap memory |
| `vTaskDelay()` | Delays task execution using FreeRTOS |
| `esp_restart()` | Restarts the ESP32 |

## 5. Working Principle

When the ESP32 starts executing the firmware:

1. The application prints a Hello World message.
2. It retrieves the chip information.
3. It displays the chip target and CPU core count.
4. It checks supported connectivity features such as Wi-Fi and Bluetooth.
5. It retrieves the flash memory size.
6. It displays the minimum free heap memory.
7. It performs a countdown from 10 to 0.
8. The ESP32 restarts.

## 6. Project Structure

```text
01-hello-world/
│
├── CMakeLists.txt
├── main/
│   ├── CMakeLists.txt
│   └── hello_world_main.c
│
├── pytest_hello_world.py
├── sdkconfig.ci
└── README.md
```

## 7. Expected Serial Monitor Output

The output will contain information similar to:

```text
Hello world!
This is ESP32 chip with 2 CPU core(s)...
silicon revision v...
4MB external flash
Minimum free heap size: ... bytes

Restarting in 10 seconds...
Restarting in 9 seconds...
...
Restarting now.
```

Actual values depend on the ESP32 model and its configuration.

## 8. Testing and Validation

| Test | Expected Behaviour |
|---|---|
| Application startup | Hello World message appears |
| Chip information | Chip details are displayed |
| Flash detection | Flash capacity is displayed |
| Heap monitoring | Minimum free heap value is displayed |
| Countdown | Countdown from 10 to 0 |
| Restart | ESP32 restarts automatically |

## 9. Key Learning Outcomes

- Understood the basic ESP-IDF application structure.
- Explored hardware information APIs.
- Learned about flash and heap memory.
- Observed FreeRTOS task delays.
- Understood software-triggered microcontroller restart.

## 10. Future Improvements

- Display chip information on an OLED.
- Monitor free heap memory continuously.
- Add uptime measurement.
- Explore FreeRTOS task creation.
- Monitor system information through a web dashboard.

---

**Learning Note:** This experiment introduces the relationship between firmware and the underlying microcontroller hardware.