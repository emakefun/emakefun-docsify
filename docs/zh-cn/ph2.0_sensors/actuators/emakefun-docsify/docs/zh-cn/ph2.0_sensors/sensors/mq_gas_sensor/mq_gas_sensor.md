# MQ-4气体传感器规格书

## 实物图

![实物图](picture/mq_gas_sensor.png)

## 概述

MQ-4天然气传感器所使用的气敏材料是在清洁空气中电导率较低的二氧化锡(SnO2)。当传感器所处环境中存在可燃气体时，传感器的电导率随空气中可燃气体浓度的增加而增大。使用简单的电路即可将电导率的变化转换为与该气体浓度相对应的输出信号。MQ-4天然气检测传感器对甲烷的灵敏度高，对丙烷、丁烷也有较好的灵敏度。这种传感器可检测多种可燃性气体，特别是天然气，是一款适合多种应用的低成本传感器。

## 原理图

<a href="zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor_schematic.pdf" target="_blank">查看原理图</a>

![原理图](picture/mq_gas_sensor_schematic.png)

## 模块参数

| 引脚名称 |     描述     |
| :------: | :----------: |
|    G     |     GND      |
|    V     |     VCC      |
|    A     | 模拟信号引脚 |
|    D     | 数字信号引脚 |

- 供电电压:3v3/5V

- 连接方式:4PIN防反接杜邦线

- 模块尺寸:40 x 22.5 mm

- 安装方式:M4螺钉兼容乐高插孔固定

## 机械尺寸图

![机械尺寸图](picture/mq_gas_sensor_assembly.png)

## Arduino示例程序

<a href="zh-cn/ph2.0_sensors/sensors/mq_gas_sensor/mq_gas_sensor.zip" download>下载示例程序</a>

```c++
#define GAS_DIGITAL_PIN 7  // 定义气体传感器数字引脚
#define GAS_ANALOG_PIN A0   // 定义气体传感器模拟引脚

int gas_analog_value = 0;   // 定义数字变量,读取模拟值
int gas_digital_value = 0;  // 定义数字变量,读取数字值

void setup() {
  Serial.begin(9600);             // 设置串口波特率为9600
  pinMode(GAS_DIGITAL_PIN, INPUT);  // 设置气体传感器数字引脚为输入
  pinMode(GAS_ANALOG_PIN, INPUT);   // 设置气体传感器模拟引脚为输入
}

void loop() {
  gas_analog_value = analogRead(GAS_ANALOG_PIN);
  gas_digital_value = digitalRead(GAS_DIGITAL_PIN); 
  Serial.print("GasAnalog Data:  ");
  Serial.print(gas_analog_value);  // 打印气体传感器模拟值
  Serial.print("GasDigital Data:  ");
  Serial.println(gas_digital_value);  // 打印气体传感器数字值
  delay(200);
}
```

## MicroPython示例程序

### Esp32 MicroPython示例程序

```python
from machine import ADC,Pin
import time

analog_pin = 15  # 定义气体传感器模拟接口引脚
digital_pin = 14  # 定义气体传感器数字接口引脚

p1 = ADC(analog_pin)
p2 = Pin(digital_pin, Pin.IN)  
        
while True:
    analog_value = p1.read_u16()  # 读取气体传感器模拟值
    print("Analog Data:", analog_value)  # 打印气体传感器模拟值
    print("Digital Data:", p2.value())  # 打印气体传感器数字值
    time.sleep_ms(200)
```

### micro:bit MicroPython示例程序

```python
from microbit import *

analog_pin = pin1  # 定义气体传感器模拟接口引脚
digital_pin = pin0  # 定义气体传感器数字接口引脚

while True:
    analog_value = analog_pin.read_analog()  # 读取气体传感器模拟值
    print("Analog Data:", analog_value)  # 打印气体传感器模拟值
    print("Digital Data:", digital_pin.read_digital())  # 打印气体传感器数字值
    sleep(0.2)
```

## MakeCode示例程序

<a href="https://makecode.microbit.org/_3pK634Mhu7bV" target="_blank">动手试一试</a>
