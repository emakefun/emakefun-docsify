# [Grayscale Sensor](http://localhost:3000/#/en/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor?id=灰度传感器)

## [Physical picture](http://localhost:3000/#/en/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor?id=实物图)



![Physical picture](http://localhost:3000/en/ph2.0_sensors/sensors/grayscale_sensor/picture/grayscale_sensor.png)



## [Overview](http://localhost:3000/#/en/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor?id=概述)

Grayscale sensor is an analog sensor, which has a light-emitting diode and a photoresistor installed on the same surface. Grayscale sensor uses the principle that different colors of detection surfaces reflect light to different degrees, and the photoresistor has different resistance values to the light returned by different detection surfaces to detect the depth of color. Within the effective detection distance, the light-emitting diode emits white light, which shines on the detection surface. The detection surface reflects part of the light, and the photoresistor detects the intensity of this light and converts it into a recognizable signal. It outputs a continuous analog signal. It can be used as a line patrol sensor for a line patrol car or as a field grayscale recognition for a football robot.

## [Schematic](http://localhost:3000/#/en/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor?id=原理图)

[View Schematic](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor_schematic.pdf)



![Schematic](http://localhost:3000/en/ph2.0_sensors/sensors/grayscale_sensor/picture/grayscale_sensor_schematic.png)



## [Module parameters](http://localhost:3000/#/en/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor?id=模块参数)

| Pin Name | describe           |
| -------- | ------------------ |
| G        | GND                |
| In       | VCC                |
| S        | Analog signal pins |

- Power supply voltage: 3v3/5V
- Connection method: 4PIN anti-reverse connection DuPont line
- Module size: 40 x 22.5 mm
- Installation method: M4 screw compatible with Lego socket

## [Mechanical Dimensions](http://localhost:3000/#/en/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor?id=机械尺寸图)



![Mechanical Dimensions](http://localhost:3000/en/ph2.0_sensors/sensors/grayscale_sensor/picture/grayscale_sensor_assembly.png)



## [Arduino Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor?id=arduino示例程序)

[Download the sample program](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor.zip)

```c
void setup(){
Serial.begin(9600); // Set the serial port baud rate to 9600
pinMode(A3, INPUT); // Set A3 as an input pin
}

void loop(){
Serial.println(analogRead(A3)); // Print the data obtained by A3 pin
delay(200); // Delay 200ms
}Copy to clipboardErrorCopied
```

## [MicroPython Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor?id=micropython示例程序)

### [Esp32 MicroPython Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor?id=esp32-micropython示例程序)



```python
from machine import ADC,Pin
import time

AnalogPin = 2 # Define grayscale sensor analog interface pin

p = ADC(AnalogPin)

while True:
AnalogValue = p.read_u16() # Read grayscale sensor analog value
print(AnalogValue) # Print grayscale sensor analog value
time.sleep_ms(200)Copy to clipboardErrorCopied
```

### [Micro:bit MicroPython Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor?id=microbit-micropython示例程序)



```python
from microbit import *

while True:
p = pin1.read_analog() # Read grayscale sensor analog value
print( p) # Print grayscale sensor analog value
sleep(200)Copy to clipboardErrorCopied
```

## [MakeCode Example Programs](http://localhost:3000/#/en/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor?id=makecode示例程序)

[Try it yourself](https://makecode.microbit.org/_fakY8cFmMMch)