# Photo Sensitive Sensor

## Physical picture

![Physical picture](picture/photo_sensitive_sensor.png)

## Overview

As we all know, the voice-controlled lights in the corridor have a sensor in addition to voice control, namely a photosensitive sensor. Photoelectric sensors are also called photoresistors. It (photoresistor, abbreviated as LDR) is usually made of cadmium sulfide. When the incident light rises, the resistance value will decrease; when the incident light weakens, the resistance value will increase. Photoresistors are often used for light measurement, control and conversion (changes between light and electricity), which will change (light becomes electricity). It can also be widely used in various light-controlled circuits, such as controlling and adjusting lights and light switches. Photoresistor modules are most sensitive to ambient light and are generally used to detect the brightness of the light in the surrounding environment, trigger microcontrollers or relay modules, etc.

## Schematic

<a href="en/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor_schematic.pdf" target="_blank">View Schematic</a> ![Schematic](picture/photo_sensitive_sensor_schematic.png)

## Module parameters

| Pin Name | describe                                                  |
| -------- | --------------------------------------------------------- |
| G        | GND                                                       |
| In       | VCC                                                       |
| S        | When the light is strong, the analog value read is larger |

- Power supply voltage: 3v3/5V
- Connection method: 3PIN anti-reverse connection DuPont line
- Module size: 40 x 22.5 mm
- Installation method: M4 screw compatible with Lego socket

## Mechanical Dimensions

![Mechanical Dimensions](picture/photo_sensitive_sensor_assembly.png)

## Arduino Example Program

<a href="en/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor.zip" download>Download the sample program</a>

```c++
#define PHOTOSENSITIVE_PIN A3  // Define the pin of the photosensor module
int photosensitive_value = 0;  // Define variables, read photosensitivity value

void setup() {
  Serial.begin(9600);                 // Set the serial port baud rate
  pinMode(PHOTOSENSITIVE_PIN, INPUT);  // Set the pin of the photosensor module as input
}
void loop() {
  photosensitive_value = analogRead(PHOTOSENSITIVE_PIN);  // Read photosensitivity value
  Serial.print("Photosensitive Data: ");
  Serial.println(photosensitive_value);  // Print photosensitivity value
}
```

## MicroPython Example Program

### Esp32 MicroPython Example Program

```python
from machine import ADC, Pin
import time

analog_pin = 2 # Define the photosensitive sensor analog interface pin

p = ADC(analog_pin)

while True:
    analog_value = p.read_u16() # Read the photosensitive sensor analog value
    print("Photosensitive Data:", analog_value) # Print the photosensitive sensor analog value
    time.sleep_ms(200)
```

### Micro:bit MicroPython Example Program

```python
from microbit import *

while True:
    p = pin1.read_analog() # Read the analog value of the photosensitive sensor
    print("Photosensitive Data:", p) # Print the analog value of the photosensitive sensor
    sleep(1000)
```

## MakeCode Example Programs

[Try it yourself](https://makecode.microbit.org/_ePdgoM28qVgV)
