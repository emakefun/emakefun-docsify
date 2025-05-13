# PM2.5 粉尘传感器

## 实物图

## 概述

PM2.5粉尘传感器是一种用于检测空气中直径小于或等于2.5微米的颗粒物浓度的设备。它广泛应用于环境监测、空气质量检测等领域，能够帮助用户了解空气污染状况，及时采取防护措施。该传感器具有高精度、响应速度快等特点，适用于各种环境条件。

## 原理图

## 尺寸图

## 模块参数

| 引脚名称| 描述 |
|:--: |:--:|
| G | GND |
| V | VCC |
| S | 信号线 |

- 供电电压：3v3/5V

- 连接方式：3PIN防反接杜邦线

- 模块尺寸：56 x 22mm

- 安装方式： M3螺钉固定

## Arduino示例程序

```c++
void setup() {
    Serial.begin(9600);  // 初始化串口通信
    pinMode(A3, INPUT);  // 设置传感器引脚为输入
}

void loop() {
  Serial.print(analogRead(A3));//打印传感器模拟值
    delay(200);  // 延时200毫秒
}
```

## MicroPython示例程序

### Esp32 MicroPython示例程序

```python
from machine import ADC,Pin
import time

AnalogPin = 15  # 定义传感器模拟接口引脚

p1 = ADC(AnalogPin)
      
while True:
    AnalogValue = p1.read_u16()  # 读取传感器模拟值
    print("Analog Data:", AnalogValue)  # 打印传感器模拟值
    time.sleep_ms(200)
```

### micro:bit MicroPython示例程序

```python
from microbit import *

AnalogPin = pin1  # 定义传感器模拟接口引脚

while True:
    AnalogValue = AnalogPin.read_analog()  # 读取传感器模拟值
    print( AnalogValue)  # 打印传感器模拟值
    sleep(0.2)
```

## MakeCode示例程序

<a href="https://makecode.microbit.org/_e1XeY08vy2kx">动手试一试</a>
