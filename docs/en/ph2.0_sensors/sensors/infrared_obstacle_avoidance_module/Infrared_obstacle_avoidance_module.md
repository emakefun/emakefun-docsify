# [Infrared Obstacle Avoidance Sensor](http://localhost:3000/#/en/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/infrared_obstacle_avoidance_module?id=红外避障传感器模块)

## [Physical picture](http://localhost:3000/#/en/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/infrared_obstacle_avoidance_module?id=实物图)



![Obstacle Avoidance](http://localhost:3000/en/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/picture/infrared_obstacle_avoidance_module.png)



## [Overview](http://localhost:3000/#/en/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/infrared_obstacle_avoidance_module?id=概述)

The infrared obstacle avoidance sensor is a sensor device that is widely used in robot obstacle avoidance, obstacle avoidance vehicles, assembly line counting and many other occasions. The sensor module has a strong adaptability to ambient light. It has a bunch of infrared transmitting and receiving tubes. The transmitting tube emits infrared rays of a certain frequency. When the detection direction encounters an obstacle (reflective surface), the infrared rays are reflected back and received by the receiving tube. After being processed by the comparator circuit, the blue indicator light will light up, and the signal output interface will output a digital signal (a low-level signal). The detection distance can be adjusted by the potentiometer knob. The effective distance range is 2 to 30cm, and the working voltage is 3.3V-5V. The detection distance of the sensor can be adjusted by the potentiometer, and it has the characteristics of low interference, easy assembly, and easy use.

## [Schematic](http://localhost:3000/#/en/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/infrared_obstacle_avoidance_module?id=原理图)

[View Schematic](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/InfraredObstacleAvoidance_schematic.pdf) ![1](http://localhost:3000/en/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/picture/infrared_obstacle_avoidance_module_schematic.png)

## [Module parameters](http://localhost:3000/#/en/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/infrared_obstacle_avoidance_module?id=模块参数)

| Pin Name | describe            |
| -------- | ------------------- |
| G        | GND                 |
| In       | VCC                 |
| A        | Analog signal pins  |
| D        | Digital signal pins |

- Power supply voltage: 3v3/5V
- Connection method: 4PIN anti-reverse connection DuPont line
- Module size: 40 x 22.5 mm
- Installation method: M4 screw compatible with Lego socket

## [Mechanical Dimensions](http://localhost:3000/#/en/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/infrared_obstacle_avoidance_module?id=机械尺寸)



![2](http://localhost:3000/en/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/picture/infrared_obstacle_avoidance_module_assembly.png)



## [Arduino Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/infrared_obstacle_avoidance_module?id=arduino示例程序)

[Download the sample program](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/InfraredObstacleAvoidanceModule.zip)

```c++
#define DigitalPin 7 // Define the digital pin of the infrared obstacle avoidance module
#define AnalogPin A0 // Define the analog pin of the infrared obstacle avoidance module

int AnalogValue = 0 ; // Define digital variables, read the analog value of the infrared obstacle avoidance module

int DigitalValue = 0 ; // Define digital variables, read the digital value of the infrared obstacle avoidance module

void setup()
{
Serial.begin(9600); // Set the serial port baud rate
pinMode(DigitalPin, INPUT); // Set the digital pin of the infrared obstacle avoidance module as input
pinMode(AnalogPin, INPUT); // Set the analog pin of the infrared obstacle avoidance module as input
}
void loop()
{
AnalogValue = analogRead(AnalogPin); // Read the analog value of the infrared obstacle avoidance module
DigitalValue = digitalRead(DigitalPin); // Read the digital value of the infrared obstacle avoidance module
Serial.print("InfraredObstacleAvoidanceModuleAnalog Data:");
Serial.print(AnalogValue);//Print infrared obstacle avoidance module analog value
Serial.print("InfraredObstacleAvoidanceModuleDigital Data:");
Serial.println(DigitalValue);//Print infrared obstacle avoidance module digital value
delay(200);
}Copy to clipboardErrorCopied
```

## [MicroPython Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/infrared_obstacle_avoidance_module?id=micropython示例程序)

### [Esp32 MicroPython Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/infrared_obstacle_avoidance_module?id=esp32-micropython示例程序)



```python
from machine import ADC,Pin
import time

AnalogPin = 15 # Define infrared obstacle avoidance module analog interface pin
DigitalPin = 14 # Define infrared obstacle avoidance module digital interface pin

p1 = ADC(AnalogPin)
p2 = Pin(DigitalPin, Pin.IN)

while True:
AnalogValue = p1.read_u16() # Read infrared obstacle avoidance module analog value
print("InfraredObstacleAvoidanceModuleAnalog Data:", AnalogValue) # Print infrared obstacle avoidance module analog value
print("InfraredObstacleAvoidanceModuleDigital Data:", p2.value()) # Print infrared obstacle avoidance module digital value
time.sleep_ms(200)Copy to clipboardErrorCopied
```

### [Micro:bit MicroPython Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/infrared_obstacle_avoidance_module?id=microbit-micropython示例程序)



```python
from microbit import *

AnalogPin = pin1 # Define the infrared obstacle avoidance module analog interface pin
DigitalPin = pin0 # Define the infrared obstacle avoidance module digital interface pin

while True:
AnalogValue = AnalogPin.read_analog() # Read the infrared obstacle avoidance module analog value
print("Analog Data:", AnalogValue) # Print the infrared obstacle avoidance module analog value
print("Digital Data:", DigitalPin.read_digital()) # Print the infrared obstacle avoidance module digital value
sleep(0.2)Copy to clipboardErrorCopied
```

## [MakeCode Example Programs](http://localhost:3000/#/en/ph2.0_sensors/sensors/infrared_obstacle_avoidance_module/infrared_obstacle_avoidance_module?id=makecode示例程序)

[Try it yourself](https://makecode.microbit.org/_9zWVg7hvCJHy)