# Water Depth Sensor

![Physical picture](picture/water_depth_sensor.png)

## Overview

The water depth sensor is designed for water quality detection and can be widely used to sense rainfall, water level, and even liquid leaks. The working principle of this sensor is to connect a series of exposed traces to ground and interleave between the ground traces, which are the sensing traces. The sensor trace has a weak pull-up resistor of 1MΩ. The resistor pulls the sensor trace value high until a drop of water shorts the sensor trace to the ground trace. It can be used with an analog pin to detect the amount of water contact between the ground and sensor traces.

## Schematic

<a href="en/ph2.0_sensors/sensors/water_depth_sensor/water_depth_sensor_schematic.pdf" target="_blank">View Schematic</a> ![Schematic](picture/water_depth_sensor_schematic.png)

## Module parameters

| Pin Name | describe                                                  |
| -------- | --------------------------------------------------------- |
| G        | GND                                                       |
| V        | VCC                                                       |
| S        | The larger the simulation value, the deeper the water is. |

- Power supply voltage: 3v3/5V
- Connection method: 3PIN anti-reverse connection DuPont line
- Module size: 56 x 22mm
- Installation method: M3 screw fixation

## Mechanical Dimensions

![Mechanical Dimensions](picture/water_depth_sensor_assembly.png)

## Arduino Example Program

<a href="en/ph2.0_sensors/sensors/water_depth_sensor/water_depth_sensor.zip" download>Download the sample program</a>

```c++
void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(A3, INPUT);  // Set the water depth sensor pin to input
}

void loop() {
  Serial.print(analogRead(A3));  // Print water depth sensor analog value
  delay(200);                    // Delay 200 milliseconds
}
```

## MicroPython Example Program

### Esp32 MicroPython Example Program

```python
from machine import ADC, Pin
import time

analog_pin = 15 # Define the analog interface pin of the water depth sensor

p1 = ADC(analog_pin)

while True:
    analog_value = p1.read_u16() # Read the analog value of the water depth sensor
    print("Analog Data:", analog_value) # Print the analog value of the water depth sensor
    time.sleep_ms(200)
```

### Micro:bit MicroPython Example Program

```python
from microbit import *

analog_pin = pin1 # Define the analog interface pin of the water depth sensor

while True:
    analog_value = analog_pin.read_analog() # Read the analog value of the water depth sensor
    print(analog_value) # Print the analog value of the water depth sensor
    sleep(0.2)
```

## MakeCode Example Programs

[Try it yourself](https://makecode.microbit.org/_e1XeY08vy2kx)
