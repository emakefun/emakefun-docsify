# Human Body Sensor

## Physical picture



![Physical picture](http://localhost:3000/en/ph2.0_sensors/sensors/human_body_sensor/picture/human_body_sensor.png)



## Overview

The human body sensing module is an automatic control product based on infrared technology, with high sensitivity, strong reliability, ultra-small size, and ultra-low voltage working mode. It is widely used in various automatic sensing electrical equipment, especially automatic control products powered by dry batteries. Fully automatic sensing, it outputs a high level when a person enters its sensing range, and automatically delays the high level to turn off the high level and outputs a low level when the person leaves the sensing range. Repeatable triggering mode: that is, after the sensing output is high, within the delay time period, if there is a human body moving within its sensing range, its output will remain high until the person leaves, and then delay the high level to a low level. After the sensing module detects each human activity, it will automatically extend a delay time period (5S), and the time of the last activity is the starting point of the delay time.

## Schematic

[View Schematic](en/ph2.0_sensors/sensors/human_body_sensor/human_body_sensor_schematic.pdf)



![Schematic](http://localhost:3000/en/ph2.0_sensors/sensors/human_body_sensor/picture/human_body_sensor_schematic.png)



## Module parameters

| Pin Name | describe                                                     |
| -------- | ------------------------------------------------------------ |
| G        | GND                                                          |
| In       | 5V                                                           |
| S        | When there is someone in front, it outputs a high level, and when there is no one in front, it outputs a low level |

- Supply voltage: 5V
- Connection method: 3PIN anti-reverse connection DuPont line
- Module size: 40 x 22.5 mm
- Installation method: M4 screw compatible with Lego socket

## Mechanical Dimensions



![Mechanical Dimensions](http://localhost:3000/en/ph2.0_sensors/sensors/human_body_sensor/picture/human_body_sensor_assembly.png)



## Arduino Example Program

[Download the sample program](en/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor.zip)

```c
void setup()
{
Serial.begin(9600);
pinMode(A3, INPUT);
}

void loop()
{
Serial.println(digitalRead(A3)); // Print the digital value of the human body pyroelectric sensor
delay(200);
}Copy to clipboardErrorCopied
```

## MicroPython Example Program

### Esp32 MicroPython Example Program



```python
from machine import ADC,Pin
import time

DigitalPin = 2 # Define the human body pyroelectric sensor digital value pin
p2 = Pin(DigitalPin, Pin.IN)

while True:
Value = p2.value() # Read the human body pyroelectric sensor digital value
print(Value) # Print the human body pyroelectric sensor digital value
time.sleep_ms(200)Copy to clipboardErrorCopied
```

### Micro:bit MicroPython Example Program

```python
from microbit import *

while True:
p = pin8.read_digital() # Read the digital value of the sensor
print(p) # Print the digital value of the sensor
sleep(1000)Copy to clipboardErrorCopied
```

## MakeCode Example Programs

[Try it yourself](https://makecode.microbit.org/_Vhka6M8PFXyh)