# [Flame Sensor](http://localhost:3000/#/en/ph2.0_sensors/sensors/flame_sensor/flame_sensor?id=火焰传感器)

## [Physical picture](http://localhost:3000/#/en/ph2.0_sensors/sensors/flame_sensor/flame_sensor?id=实物图)



![Physical picture](http://localhost:3000/en/ph2.0_sensors/sensors/flame_sensor/picture/flame_sensor.png)



## [Overview](http://localhost:3000/#/en/ph2.0_sensors/sensors/flame_sensor/flame_sensor?id=概述)

In public places, such as hotels, buildings and other places, fire alarms are equipped. How do they sense fires? As we all know, when a fire breaks out, there will be particularly strong infrared rays. This device can detect fires through infrared rays. The flame sensor is a sensor that the robot uses to search for fire sources. Of course, the flame sensor can also be used to detect the brightness of light, but this sensor is particularly sensitive to flames. The flame sensor uses the characteristics of infrared rays being very sensitive to flames, uses a special infrared receiving tube to detect flames, and then converts the brightness of the flame into a high and low level signal, which is input into the central processing unit. The central processing unit makes corresponding program processing according to the changes in the signal.

## [Schematic](http://localhost:3000/#/en/ph2.0_sensors/sensors/flame_sensor/flame_sensor?id=原理图)

[View Schematic](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/flame_sensor/flame_sensor_schematic.pdf)



![Schematic](http://localhost:3000/en/ph2.0_sensors/sensors/flame_sensor/picture/flame_sensor_schematic.png)



## [Module parameters](http://localhost:3000/#/en/ph2.0_sensors/sensors/flame_sensor/flame_sensor?id=模块参数)

| Pin Name | describe            |
| -------- | ------------------- |
| G        | GND                 |
| In       | VCC                 |
| A        | Analog signal pins  |
| D        | Digital signal pins |

- Supply voltage: 3V3/5V
- Connection method: 4PIN anti-reverse connection DuPont line
- Module size: 40 x 22.5 mm
- Installation method: M4 screw compatible with Lego socket

## [Mechanical Dimensions](http://localhost:3000/#/en/ph2.0_sensors/sensors/flame_sensor/flame_sensor?id=机械尺寸图)



![Mechanical Dimensions](http://localhost:3000/en/ph2.0_sensors/sensors/flame_sensor/picture/flame_sensor_assembly.png)



## [Arduino Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/flame_sensor/flame_sensor?id=arduino示例程序)

[Download the sample program](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/flame_sensor/flame_sensor.rar)

```c
#define FlamelDigitalPin 7 // Define the digital pin of the flame sensor
#define FlamelAnalogPin A0 // Define the analog pin of the flame sensor

int FlamelAnalogValue = 0 ; // Define digital variables, read the flame analog value
int FlamelDigitalValue = 0 ; // Define digital variables, read the flame digital value

void setup()
{
Serial.begin(9600); // Set the serial port baud rate
pinMode(FlamelDigitalPin, INPUT); // Set the flame sensor digital pin as input
pinMode(FlamelAnalogPin, INPUT); // Set the flame sensor analog pin as input
}
void loop()
{
FlamelAnalogValue = analogRead(FlamelAnalogPin); // Read the flame sensor analog value
FlamelDigitalValue = digitalRead(FlamelDigitalPin); // Read the flame sensor digital value
Serial.print("FlamelAnalog Data: ");
Serial.print(FlamelAnalogValue);//Print the flame sensor analog value
Serial.print("FlamelDigital Data: ");
Serial.println(FlamelDigitalValue);//Print the flame sensor digital value
delay(200);
}Copy to clipboardErrorCopied
```

## [MicroPython Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/flame_sensor/flame_sensor?id=micropython示例程序)

### [Esp32 MicroPython Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/flame_sensor/flame_sensor?id=esp32-micropython示例程序)



```python
from machine import ADC,Pin
import time

AnalogPin = 15 # Define the flame sensor analog interface pin
DigitalPin = 14 # Define the flame sensor digital interface pin

p1 = ADC(AnalogPin)
p2 = Pin(DigitalPin, Pin.IN)

while True:
AnalogValue = p1.read_u16() # Read the flame sensor analog value
print("Analog Data:", AnalogValue) # Print the flame sensor analog value
print("Digital Data:", p2.value()) # Print the flame sensor digital value
time.sleep_ms(200)Copy to clipboardErrorCopied
```

### [Micro:bit MicroPython Example Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/flame_sensor/flame_sensor?id=microbit-micropython示例程序)



```python
from microbit import *

AnalogPin = pin1 # Define the flame sensor analog interface pin
DigitalPin = pin0 # Define the flame sensor digital interface pin

while True:
AnalogValue = AnalogPin.read_analog() # Read the flame sensor analog value
print("Analog Data:", AnalogValue) # Print the flame sensor analog value
print("Digital Data:", DigitalPin.read_digital()) # Print the flame sensor digital value
sleep(0.2)Copy to clipboardErrorCopied
```

## [MakeCode Example Programs](http://localhost:3000/#/en/ph2.0_sensors/sensors/flame_sensor/flame_sensor?id=makecode示例程序)

[Try it yourself](https://makecode.microbit.org/_FoqM4TLuUdzW)