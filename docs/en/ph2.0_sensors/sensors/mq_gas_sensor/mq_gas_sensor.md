# MQ-4 Gas Sensor

## Physical picture

![Physical picture](picture/mq_gas_sensor.png)

## Overview

The gas-sensitive material used in the MQ-4 natural gas sensor is tin dioxide (SnO2) with low conductivity in clean air. When there is combustible gas in the environment where the sensor is located, the conductivity of the sensor increases with the increase of the concentration of combustible gas in the air. A simple circuit can be used to convert the change in conductivity into an output signal corresponding to the gas concentration. The MQ-4 natural gas detection sensor has high sensitivity to methane and also has good sensitivity to propane and butane. This sensor can detect a variety of combustible gases, especially natural gas, and is a low-cost sensor suitable for a variety of applications.

## Schematic

<a href="en/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor_schematic.pdf" target="_blank">View Schematic</a> ![Schematic](picture/mq_gas_sensor_schematic.png)

## Module parameters

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

## Mechanical Dimensions

![Mechanical Dimensions](picture/mq_gas_sensor_assembly.png)

## Arduino Example Program

<a href="en/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor.zip" download>Download the sample program</a>

```c++
#define GAS_DIGITAL_PIN 7  // define the digital pin of the gas sensor
#define GAS_ANALOG_PIN A0   // define the analog pin of the gas sensor

int gas_analog_value = 0;  // define digital variables and read analog values
int gas_digital_value = 0;  // define digital variables and read digital values

void setup() {
  Serial.begin(9600);             // Set the serial port baud rate to 9600
  pinMode(GAS_DIGITAL_PIN, INPUT);  // Set the digital pin of the gas sensor as input
  pinMode(GAS_ANALOG_PIN, INPUT);   // Set the analog pin of the gas sensor as input
}

void loop() {
  gas_analog_value = analogRead(GAS_ANALOG_PIN);
  gas_digital_value = digitalRead(GAS_DIGITAL_PIN);
  Serial.print("GasAnalog Data: ");
  Serial.print(gas_analog_value);  // Print the analog value of the gas sensor
  Serial.print("GasDigital Data: ");
  Serial.println(gas_digital_value);  // Print gas sensor digital value
  delay(200);
}
```

## MicroPython Example Program

### Esp32 MicroPython Example Program

```python
from machine import ADC, Pin
import time

analog_pin = 15 # Define gas sensor analog interface pin
digital_pin = 14 # Define gas sensor digital interface pin

p1 = ADC(analog_pin)
p2 = Pin(digital_pin, Pin.IN)

while True:
    analog_value = p1.read_u16() # Read gas sensor analog value
    print("Analog Data:", analog_value) # Print gas sensor analog value
    print("Digital Data:", p2.value()) # Print gas sensor digital value
    time.sleep_ms(200)
```

### Micro:bit MicroPython Example Program

```python
from microbit import *

analog_pin = pin1 # Define gas sensor analog interface pin
digital_pin = pin0 # Define gas sensor digital interface pin

while True:
    analog_value = analog_pin.read_analog() # Read gas sensor analog value
    print("Analog Data:", analog_value) # Print gas sensor analog value
    print("Digital Data:", digital_pin.read_digital()) # Print gas sensor digital value
    sleep(0.2)
```

## MakeCode Example Programs

[Try it yourself](https://makecode.microbit.org/_3pK634Mhu7bV)
