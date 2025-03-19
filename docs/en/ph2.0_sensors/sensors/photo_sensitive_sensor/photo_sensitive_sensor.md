# [Photo Sensitive Sensor](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor?id=光敏传感器模块规格书)

## [Physical picture](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor?id=实物图)



![Physical picture](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/picture/photo_sensitive_sensor.png)



## [Overview](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor?id=概述)

As we all know, the voice-controlled lights in the corridor have a sensor in addition to voice control, namely a photosensitive sensor. Photoelectric sensors are also called photoresistors. It (photoresistor, abbreviated as LDR) is usually made of cadmium sulfide. When the incident light rises, the resistance value will decrease; when the incident light weakens, the resistance value will increase. Photoresistors are often used for light measurement, control and conversion (changes between light and electricity), which will change (light becomes electricity). It can also be widely used in various light-controlled circuits, such as controlling and adjusting lights and light switches. Photoresistor modules are most sensitive to ambient light and are generally used to detect the brightness of the light in the surrounding environment, trigger microcontrollers or relay modules, etc.

## [Schematic](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor?id=原理图)

[View Schematic](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor_schematic.pdf) ![Schematic](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/picture/photo_sensitive_sensor_schematic.png)

## [Module parameters](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor?id=模块参数)

| Pin Name | describe                                                  |
| -------- | --------------------------------------------------------- |
| G        | GND                                                       |
| In       | VCC                                                       |
| S        | When the light is strong, the analog value read is larger |

- Power supply voltage: 3v3/5V
- Connection method: 3PIN anti-reverse connection DuPont line
- Module size: 40 x 22.5 mm
- Installation method: M4 screw compatible with Lego socket

## [Mechanical Dimensions](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor?id=机械尺寸图)



![Mechanical Dimensions](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/picture/photo_sensitive_sensor_assembly.png)



## [Arduino Example Program](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor?id=arduino示例程序)

[Download the sample program](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor.zip)

```c++
#define PhotosensitivePin A3 //Define the pin of the photosensor module
int PhotosensitiveValue = 0 ; //Define variables, read photosensitivity value

void setup()
{
Serial.begin(9600); //Set the serial port baud rate
pinMode(PhotosensitivePin, INPUT); //Set the pin of the photosensor module as input
}
void loop()
{
PhotosensitiveValue = analogRead(PhotosensitivePin); //Read photosensitivity value
Serial.print("Photosensitive Data: ");
Serial.println(PhotosensitiveValue); //Print photosensitivity value
}Click Copymistakecopy
```

## [MicroPython Example Program](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor?id=micropython示例程序)

### [Esp32 MicroPython Example Program](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor?id=esp32-micropython示例程序)



```python
from machine import ADC,Pin
import time

AnalogPin = 2 # Define the photosensitive sensor analog interface pin

p = ADC(AnalogPin)

while True:
AnalogValue = p.read_u16() # Read the photosensitive sensor analog value
print("Photosensitive Data:", AnalogValue) # Print the photosensitive sensor analog value
time.sleep_ms(200)Click Copymistakecopy
```

### [Micro:bit MicroPython Example Program](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor?id=microbit-micropython示例程序)



```python
from microbit import *

while True:
p = pin1.read_analog() # Read the analog value of the photosensitive sensor
print("Photosensitive Data:", p) # Print the analog value of the photosensitive sensor
sleep(1000)Click Copymistakecopy
```

## [MakeCode Example Programs](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/photo_sensitive_sensor/photo_sensitive_sensor?id=makecode示例程序)

[Try it yourself](https://makecode.microbit.org/_ePdgoM28qVgV)