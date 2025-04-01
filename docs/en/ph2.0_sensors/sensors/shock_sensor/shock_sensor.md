# Shock Sensor

## Physical picture



![Physical picture](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/shock_sensor/picture/shock_sensor.png)



## Overview

The shock sensor module is essentially a switch, which contains a metal sheet and a spring. When the product is not vibrating, the vibration switch is in the off state, and the output end outputs a high level. When the product is vibrating, the vibration switch is instantly turned on due to the spring and the metal sheet, and the output end outputs a low level. The output end can be directly connected to the microcontroller, and the high and low levels can be detected by the microcontroller to detect whether the environment is vibrating, thereby serving as an alarm.

## Schematic

[View Schematic](en/ph2.0_sensors/sensors/shock_sensor/shock_sensor_schematic.pdf) ![Schematic](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/shock_sensor/picture/shock_sensor_schematic.png)

## Module parameters

| Pin Name | describe           |
| -------- | ------------------ |
| G        | GND                |
| In       | VCC                |
| A        | Analog signal pins |
| D        | Digital signal pin |

- Power supply voltage: 3v3/5V
- Connection method: 4PIN anti-reverse connection DuPont line
- Module size: 40 x 22.5 mm
- Installation method: M4 screw compatible with Lego socket

## Mechanical Dimensions

![Mechanical Dimensions](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/shock_sensor/picture/shock_sensor_schematic_assembly.png)



## Arduino Example Program

[Download the sample program](en/ph2.0_sensors/sensors/shock_sensor/shock_sensor.rar)

```c++
#define ShockAnalogPin A0 // Define shock sensor analog pin
#define ShockDigitalPin 7 // Define shock sensor digital pin

void setup()
{
Serial.begin(9600); // Initialize serial communication
pinMode(ShockAnalogPin, INPUT); // Set shock sensor analog pin as input
pinMode(ShockDigitalPin, INPUT); // Set shock sensor digital pin as input
}

void loop()
{
Serial.println("Shock Analog Data: ");
Serial.println(analogRead(ShockAnalogPin)); // Print shock sensor analog data
Serial.println(digitalRead(ShockDigitalPin)); // Print shock sensor digital data
delay(1000); // Delay 1 second
}Click Copymistakecopy
```

## MicroPython Example Program

### Esp32 MicroPython Example Program

```python
from machine import ADC,Pin
import time

AnalogPin = 15 # Define the analog interface pin of the vibration sensor
DigitalPin = 14 # Define the digital interface pin of the vibration sensor

p1 = ADC(AnalogPin)
p2 = Pin(DigitalPin, Pin.IN)

while True:
AnalogValue = p1.read_u16() # Read the analog value of the vibration sensor
print("Analog Data:", AnalogValue) # Print the analog value of the vibration sensor
print("Digital Data:", p2.value()) # Print the digital value of the vibration sensor
time.sleep_ms(200)
Click Copymistakecopy
```

### Micro:bit MicroPython Example Program

```python
from microbit import *

AnalogPin = pin1 # Define the analog interface pin of the vibration sensor
DigitalPin = pin0 # Define the digital interface pin of the vibration sensor

while True:
AnalogValue = AnalogPin.read_analog() # Read the analog value of the vibration sensor
print("Analog Data:", AnalogValue) # Print the analog value of the vibration sensor
print("Digital Data:", DigitalPin.read_digital()) # Print the digital value of the vibration sensor
sleep(0.2)Click Copymistakecopy
```

## MakeCode Example Programs

[Try it yourself](https://makecode.microbit.org/_0Jy1249E9U4K)