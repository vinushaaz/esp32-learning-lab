# 02 - ESP32 LED Blink

**Framework:** PlatformIO  
**Platform:** Espressif 32  
**Language:** C++  
**Arduino Framework:** Yes  
**Category:** GPIO Fundamentals  
**Status:** Migrated from original repository

## 1. Objective

Understand how to configure and control a General Purpose Input/Output (GPIO) pin using an ESP32.

The experiment makes an LED blink continuously by switching a GPIO pin between HIGH and LOW states.

## 2. Hardware Requirements

- ESP32 development board
- USB data cable
- Onboard LED or external LED
- 220Ω resistor (if using an external LED)
- Breadboard and jumper wires (if required)

## 3. Software Requirements

- Visual Studio Code
- PlatformIO IDE Extension
- Arduino Framework
- Git

## 4. Hardware Configuration

| Parameter | Value |
|---|---|
| GPIO pin | GPIO 2 |
| Pin mode | OUTPUT |
| ON duration | 250 ms |
| OFF duration | 250 ms |
| Total cycle | 500 ms |
| Blink frequency | 2 Hz |
| Duty cycle | 50% |

**Note:** GPIO 2 is the pin configured in this experiment. Check your development board's onboard LED connection before assuming that GPIO 2 controls it.

## 5. Working Principle

The ESP32 configures GPIO 2 as an output.

The firmware continuously performs the following sequence:

1. Set GPIO 2 HIGH.
2. Wait 250 milliseconds.
3. Set GPIO 2 LOW.
4. Wait 250 milliseconds.
5. Repeat the sequence.

This produces a continuous blinking effect.

## 6. Code Explanation

### Pin Configuration

```cpp
#define LED_PIN 2

void setup()
{
    pinMode(LED_PIN, OUTPUT);
}
```

- `LED_PIN` defines the GPIO pin number.
- `setup()` executes once when the Arduino application starts.
- `pinMode()` configures the pin as an output.

### LED Control

```cpp
void loop()
{
    digitalWrite(LED_PIN, HIGH);
    delay(250);

    digitalWrite(LED_PIN, LOW);
    delay(250);
}
```

- `loop()` executes repeatedly.
- `digitalWrite(HIGH)` sets the output HIGH.
- `delay(250)` pauses execution for 250 milliseconds.
- `digitalWrite(LOW)` sets the output LOW.

## 7. Understanding the Timing

One complete blink cycle consists of:

- ON time = 250 ms
- OFF time = 250 ms

Total period:

```text
T = 250 + 250
T = 500 ms
T = 0.5 seconds
```

Frequency:

```text
f = 1 / T

f = 1 / 0.5

f = 2 Hz
```

Therefore, the LED completes two full ON-OFF cycles per second.

Duty cycle:

```text
Duty Cycle = (ON Time / Total Period) × 100

           = (250 / 500) × 100

           = 50%
```

## 8. Project Structure

```text
02-led-blink/
│
├── platformio.ini
├── src/
│   └── main.cpp
├── include/
├── lib/
├── test/
└── README.md
```

## 9. Testing and Validation

| Test | Expected Result |
|---|---|
| Firmware upload | Successful upload |
| GPIO initialization | GPIO 2 configured as output |
| HIGH state | LED turns ON |
| LOW state | LED turns OFF |
| Timing | 250 ms ON and 250 ms OFF |
| Continuous operation | Blinking repeats continuously |

## 10. Key Learning Outcomes

- Understood GPIO fundamentals.
- Learned digital output control.
- Understood HIGH and LOW logic states.
- Learned pin configuration using `pinMode()`.
- Explored timing using `delay()`.
- Calculated frequency and duty cycle.

## 11. Future Improvements

- Control multiple LEDs.
- Introduce push-button control.
- Implement different blinking patterns.
- Use `millis()` instead of blocking `delay()`.
- Implement LED blinking using FreeRTOS tasks.
- Explore PWM-based LED brightness control.

---

**Learning Note:** GPIO is one of the fundamental building blocks of embedded systems. The same principles are used when controlling relays, motors, indicators and other hardware interfaces.