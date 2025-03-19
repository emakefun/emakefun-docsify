# [Water Depth Sensor](http://localhost:3000/#/en/ph2.0_sensors/sensors/water_depth_sensor/water_depth_sensor?id=水深传感器)



![Physical picture](http://localhost:3000/en/ph2.0_sensors/sensors/water_depth_sensor/picture/water_depth_sensor.png)



## [Overview](http://localhost:3000/#/en/ph2.0_sensors/sensors/water_depth_sensor/water_depth_sensor?id=概述)

The water depth sensor is designed for water quality detection and can be widely used to sense rainfall, water level, and even liquid leaks. The working principle of this sensor is to connect a series of exposed traces to ground and interleave between the ground traces, which are the sensing traces. The sensor trace has a weak pull-up resistor of 1MΩ. The resistor pulls the sensor trace value high until a drop of water shorts the sensor trace to the ground trace. It can be used with an analog pin to detect the amount of water contact between the ground and sensor traces.

## [Schematic](http://localhost:3000/#/en/ph2.0_sensors/sensors/water_depth_sensor/water_depth_sensor?id=原理图)

[View Schematic](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/water_depth_sensor/water_depth_sensor_schematic.pdf) ![Schematic](http://localhost:3000/en/ph2.0_sensors/sensors/water_depth_sensor/picture/water_depth_sensor_schematic.png)

## [Module parameters](http://localhost:3000/#/en/ph2.0_sensors/sensors/water_depth_sensor/water_depth_sensor?id=模块参数)

| Pin Name | describe                                                  |
| -------- | --------------------------------------------------------- |
| G        | GND                                                       |
| V        | VCC                                                       |
| S        | The larger the simulation value, the deeper the water is. |

- Power supply voltage: 3v3/5V
- Connection method: 3PIN anti-reverse connection DuPont line
- Module size: 56 x 22mm
- Installation method: M3 screw fixation

## [Mechanical Dimensions](http://localhost:3000/#/en/ph2.0_sensors/sensors/water_depth_sensor/water_depth_sensor?id=机械尺寸图)



![Mechanical Dimensions](http://localhost:3000/en/ph2.0_sensors/sensors/water_depth_sensor/picture/water_depth_sensor_assembly.png)



## [Arduino Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/water_depth_sensor/water_depth_sensor?id=arduino示例程序)

[Download the sample program](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/water_depth_sensor/water_depth_sensor.zip)



```c++
void setup() {
Serial.begin(9600); // Initialize serial communication
pinMode(A3, INPUT); // Set the water depth sensor pin to input
}

void loop() {
Serial.print(analogRead(A3));//Print water depth sensor analog value
delay(200); // Delay 200 milliseconds
}Copy to clipboardErrorCopied
```

## [MicroPython Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/water_depth_sensor/water_depth_sensor?id=micropython示例程序)

### [Esp32 MicroPython Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/water_depth_sensor/water_depth_sensor?id=esp32-micropython示例程序)



```python
from machine import ADC,Pin
import time

AnalogPin = 15 # Define the analog interface pin of the water depth sensor

p1 = ADC(AnalogPin)

while True:
AnalogValue = p1.read_u16() # Read the analog value of the water depth sensor
print("Analog Data:", AnalogValue) # Print the analog value of the water depth sensor
time.sleep_ms(200)Copy to clipboardErrorCopied
```

### [Micro:bit MicroPython Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/water_depth_sensor/water_depth_sensor?id=microbit-micropython示例程序)



```python
from microbit import *

AnalogPin = pin1 # Define the analog interface pin of the water depth sensor

while True:
AnalogValue = AnalogPin.read_analog() # Read the analog value of the water depth sensor
print(AnalogValue) # Print the analog value of the water depth sensor
sleep(0.2)Copy to clipboardErrorCopied
```

## [MakeCode Example Programs](http://localhost:3000/#/en/ph2.0_sensors/sensors/water_depth_sensor/water_depth_sensor?id=makecode示例程序)

[Try it yourself](https://makecode.microbit.org/_e1XeY08vy2kx)