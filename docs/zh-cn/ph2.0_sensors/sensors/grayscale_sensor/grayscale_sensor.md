# 灰度传感器

## 实物图

![实物图](picture/grayscale_sensor.png)

## 概述

灰度传感器是模拟传感器，有一个发光二极管和一个光敏电阻，安装在同一面上。灰度传感器利用不同颜色的检测面对光的反射程度不同，光敏电阻对不同检测面返回的光的阻值也不同的原理进行颜色深浅检测。在有效的检测距离内，发光二极管发出白光，照射在检测面上，检测面反射部分光线，光敏电阻检测此光线的强度并将其转换为可以识别的信号。它输出的是连续的模拟信号。可以作为巡线小车的巡线传感器或者足球机器人的场地灰度识别。

## 原理图

<a href="zh-cn/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor_schematic.pdf" target="_blank">查看原理图</a>

![原理图](picture/grayscale_sensor_schematic.png)

## 模块参数

| 引脚名称 |     描述     |
| :------: | :----------: |
|    G     |     GND      |
|    V     |     VCC      |
|    S     | 模拟信号引脚 |

- 供电电压:3v3/5V

- 连接方式:3PIN防反接杜邦线

- 模块尺寸:40 x 22.5 mm

- 安装方式:M4螺钉兼容乐高插孔固定

## 机械尺寸图

![机械尺寸图](picture/grayscale_sensor_assembly.png)

## Arduino示例程序

<a href="zh-cn/ph2.0_sensors/sensors/grayscale_sensor/grayscale_sensor.zip" download>下载示例程序</a>

```c
void setup() {
  Serial.begin(9600);  // 将串口波特率设置为9600
  pinMode(A3, INPUT);  // 将A3设置为输入引脚
}

void loop() {
  Serial.println(analogRead(A3));  // 打印A3引脚获取的数据
  delay(200);                      // 延迟200ms
}
```

## MicroPython示例程序

### Esp32 MicroPython示例程序

```python
from machine import ADC,Pin
import time

analog_pin = 2  # 定义灰度传感器模拟接口引脚

p = ADC(analog_pin)

while True:
    analog_value = p.read_u16()  # 读取灰度传感器模拟值
    print( analog_value)  # 打印灰度传感器模拟值
    time.sleep_ms(200)
```

### micro:bit MicroPython示例程序

```python
from microbit import *

while True:
    p = pin1.read_analog() # 读取灰度传感器模拟值
    print( p)  # 打印灰度传感器模拟值
    sleep(200)
```

## MakeCode示例程序

<a href="https://makecode.microbit.org/_fakY8cFmMMch" target="_blank">动手试一试</a>
