# [MQ-4 Gas Sensor](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor?id=mq-4气体传感器规格书)

## [Physical picture](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor?id=实物图)



![Physical picture](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/picture/mq_gas_sensor.png)



## [Overview](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor?id=概述)

The gas-sensitive material used in the MQ-4 natural gas sensor is tin dioxide (SnO2) with low conductivity in clean air. When there is combustible gas in the environment where the sensor is located, the conductivity of the sensor increases with the increase of the concentration of combustible gas in the air. A simple circuit can be used to convert the change in conductivity into an output signal corresponding to the gas concentration. The MQ-4 natural gas detection sensor has high sensitivity to methane and also has good sensitivity to propane and butane. This sensor can detect a variety of combustible gases, especially natural gas, and is a low-cost sensor suitable for a variety of applications.

## [Schematic](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor?id=原理图)

[View Schematic](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor_schematic.pdf) ![Schematic](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/picture/mq_gas_sensor_schematic.png)

## [Module parameters](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor?id=模块参数)

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

## [Mechanical Dimensions](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor?id=机械尺寸图)



![Mechanical Dimensions](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/picture/mq_gas_sensor_assembly.png)



## [Arduino Example Program](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor?id=arduino示例程序)

[Download the sample program](http://localhost:3000/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor.zip)

```c++
#define GaslDigitalPin 7 //define the digital pin of the gas sensor
#define GasAnalogPin A0 //define the analog pin of the gas sensor

int GasAnalogValue = 0 ; //define digital variables and read analog values

int GasDigitalValue = 0 ; //define digital variables and read digital values

void setup()
{
Serial.begin(9600); //Set the serial port baud rate to 9600
pinMode(GasDigitalPin, INPUT); //Set the digital pin of the gas sensor as input
pinMode(GasAnalogPin, INPUT); //Set the analog pin of the gas sensor as input
}

void loop()
{
GasAnalogValue = analogRead(GasAnalogPin);
GasDigitalValue = digitalRead(GaslDigitalPin)
Serial.print("GasAnalog Data: ");
Serial.print(GasAnalogValue); //Print the analog value of the gas sensor
Serial.print("GasDigital Data: ");
Serial.println(GasDigitalValue);//Print gas sensor digital value
delay(200);
}Click Copymistakecopy
```

## [MicroPython Example Program](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor?id=micropython示例程序)

### [Esp32 MicroPython Example Program](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor?id=esp32-micropython示例程序)



```python
from machine import ADC,Pin
import time

AnalogPin = 15 # Define gas sensor analog interface pin
DigitalPin = 14 # Define gas sensor digital interface pin

p1 = ADC(AnalogPin)
p2 = Pin(DigitalPin, Pin.IN)

while True:
AnalogValue = p1.read_u16() # Read gas sensor analog value
print("Analog Data:", AnalogValue) # Print gas sensor analog value
print("Digital Data:", p2.value()) # Print gas sensor digital value
time.sleep_ms(200)Click Copymistakecopy
```

### [Micro:bit MicroPython Example Program](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor?id=microbit-micropython示例程序)



```python
from microbit import *

AnalogPin = pin1 # Define gas sensor analog interface pin
DigitalPin = pin0 # Define gas sensor digital interface pin

while True:
AnalogValue = AnalogPin.read_analog() # Read gas sensor analog value
print("Analog Data:", AnalogValue) # Print gas sensor analog value
print("Digital Data:", DigitalPin.read_digital()) # Print gas sensor digital value
sleep(0.2)Click Copymistakecopy
```

## [MakeCode Example Programs](http://localhost:3000/#/zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor?id=makecode示例程序)

[Try it yourself](https://makecode.microbit.org/_3pK634Mhu7bV)