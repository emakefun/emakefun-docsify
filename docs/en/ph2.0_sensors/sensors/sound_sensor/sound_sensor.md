# Sound Sensor

## Physical picture



![Physical picture](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/sound_sensor/picture/sound_sensor.png)



## Overview

The function of the sound sensor module is equivalent to a microphone. It is used to receive sound waves and display the vibration image of the sound, but it cannot measure the intensity of the noise. The sensor has a built-in capacitive electret microphone that is sensitive to sound. The sound wave causes the electret film in the microphone to vibrate, resulting in a change in capacitance, which generates a small voltage corresponding to the change. This voltage is then converted into a 0-5V voltage, which is received by the data acquisition device after A/D conversion and transmitted to the main control chip.

## Schematic

[View Schematic](en/ph2.0_sensors/sensors/sound_sensor/sound_sensor_schematic.pdf) ![Schematic](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/sound_sensor/picture/sound_sensor_schematic.png)

## Module parameters

| Pin Name | describe            |
| -------- | ------------------- |
| G        | GND                 |
| In       | VCC                 |
| A        | Analog signal pins  |
| D        | Digital signal pins |

- Supply voltage: 5V
- Connection method: 3PIN anti-reverse connection DuPont line
- Module size: 40 x 22.5 mm
- Installation method: M4 screw compatible with Lego socket

## Mechanical Dimensions

![Mechanical Dimensions](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/sound_sensor/picture/sound_sensor_assembly.png)

## Arduino Example Program

[Download the sample program](en/ph2.0_sensors/sensors/sound_sensor/sound_sensor.zip)

```c++
#define AnalogPin 15//Define the analog interface pin of the sound sensor
#define DigitalPin 14//Define the digital interface pin of the sound sensor
int AnalogValue=0;
byte DigitalValue=0;

void setup()
{
Serial.begin(9600);//Set the serial port baud rate
pinMode(AnalogPin, INPUT);//Set the analog interface pin of the sound sensor to input
pinMode(DigitalPin, INPUT);//Set the digital interface pin of the sound sensor to input
}

void loop() {
AnalogValue= analogRead(AnalogPin);//Read the analog value of the sound sensor
DigitalValue=digitalRead(DigitalPin);//Read the digital value of the sound sensor
Serial.print("Analog Data:");
Serial.println(AnalogValue);//Print the analog value of the sound sensor
Serial.print("Digital Data:");
Serial.println(DigitalValue);//Print the digital value of the sound sensor
delay(200);
}Click Copymistakecopy
```

The sensor threshold can be adjusted by adjusting the resistance value on the sound sensor.

## MicroPython Example Program

### Esp32 MicroPython Example Program

```python
from machine import ADC,Pin
import time

AnalogPin = 15 # Define the analog interface pin of the sound sensor
DigitalPin = 14 # Define the digital interface pin of the sound sensor

p1 = ADC(AnalogPin)
p2 = Pin(DigitalPin, Pin.IN) # create input pin on GPIO2

while True:
AnalogValue = p1.read_u16() # Read the analog value of the sound sensor
print("Analog Data:", AnalogValue) # Print the analog value of the sound sensor
print("Digital Data:", p2.value()) # Print the digital value of the sound sensor
time.sleep_ms(200)
Click Copymistakecopy
```

### Micro:bit MicroPython Example Program

```python
from microbit import *

while True:
p1 = pin1.read_analog() # Read the analog value of the sound sensor
p2 = pin2.read_digital() # Read the digital value of the sound sensor
print("Analog Data:", p1) # Print the analog value of the sound sensor
print("Digital Data:", p2) # Print the digital value of the sound sensor
sleep(1000)Click Copymistakecopy
```

## MakeCode Example Programs

[Try it yourself](https://makecode.microbit.org/_FaF5Xx1C2Tvb)