# Tilt Switch Sensor

## Physical picture



![Physical picture](http://localhost:3000/en/ph2.0_sensors/sensors/tilt_switch_sensor/picture/tilt_switch_sensor.png)



## Overview

The tilt switch module is also called a bead switch, steel ball switch, and is actually a vibration switch. It has different names, but the working principle remains the same. The ball controls the connection or disconnection of the circuit by contacting or not contacting the metal plate. Simply put, it is like turning a light on or off, if the switch touches the metal plate inside, the light will be on, and when the switch is off, the light will go out. Contact with the metal terminal or changing the path of light with a small bead in the switch will be able to produce a conduction effect.

## Schematic

[View Schematic](en/ph2.0_sensors/sensors/tilt_switch_sensor/tilt_switch_sensor_schematic.pdf) ![Schematic](http://localhost:3000/en/ph2.0_sensors/sensors/tilt_switch_sensor/picture/tilt_switch_sensor_schematic.png)

## Module parameters

| Pin Name | describe            |
| -------- | ------------------- |
| G        | GND                 |
| V        | VCC                 |
| A        | Analog signal pins  |
| D        | Digital signal pins |

- Power supply voltage: 3v3/5V
- Connection method: 4PIN anti-reverse connection DuPont line
- Module size: 40 x 22.5 mm
- Installation method: M4 screw compatible with Lego socket

## Mechanical Dimensions

![Mechanical Dimensions](http://localhost:3000/en/ph2.0_sensors/sensors/tilt_switch_sensor/picture/tilt_switch_sensor_assembly.png)



## Arduino Example Program

[Download the sample program](en/ph2.0_sensors/sensors/tilt_switch_sensor/tilt_switch_sensor.zip)

```c++
#define DigitalPin 7 // Define the digital pin of the tilt sensor
#define AnalogPin A0 // Define the analog pin of the tilt sensor

int AnalogValue = 0 ; // Define a digital variable to read the analog value of the tilt sensor

int DigitalValue = 0 ; // Define a digital variable to read the digital value of the tilt sensor

void setup()
{
Serial.begin(9600); // Set the serial port baud rate
pinMode(DigitalPin, INPUT); // Set the digital pin of the tilt sensor as input
pinMode(AnalogPin, INPUT); // Set the analog pin of the tilt sensor as input
}
void loop()
{
FlamelAnalogValue = analogRead(AnalogPin); // Read the analog value of the tilt sensor
FlamelDigitalValue = digitalRead(DigitalPin); // Read the digital value of the tilt sensor
Serial.print("Analog Data: ");
Serial.print(AnalogValue); // Print the analog value of the tilt sensor
Serial.print("Digital Data: ");
Serial.println(DigitalValue);//Print the digital value of the tilt sensor
delay(200);
}Copy to clipboardErrorCopied
```

## MicroPython Example Program

### Esp32 MicroPython Example Program

```python
from machine import ADC, Pin
import time

AnalogPin = 15 # Define analog pin
DigitalPin = 14 # Define digital pin

p1 = ADC(AnalogPin)
p2 = Pin(DigitalPin, Pin.IN)

while True:
AnalogValue = p1.read_u16()
print("Analog Data:", AnalogValue) # Print analog value
print("Digital Data:", p2.value()) # Print digital value
time.sleep_ms(200)Copy to clipboardErrorCopied
```

### Micro:bit MicroPython Example Program

```python
from microbit import *

while True:
p1 = pin1.read_analog()
p2 = pin2.read_digital()
print("Analog Data:", p1) # Print analog data
print("Digital Data:", p2) # Print digital data
sleep(1000)Copy to clipboardErrorCopied
```

## MakeCode Example Programs

[Try it yourself](https://makecode.microbit.org/_5Roamecfp27z)