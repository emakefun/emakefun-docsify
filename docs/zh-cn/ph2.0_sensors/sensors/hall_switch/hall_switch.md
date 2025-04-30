# 霍尔开关传感器

## 实物图

## 概述

霍尔开关传感器是基于霍尔效应原理工作的磁控器件，通过磁场变化触发开关信号。其核心优势在于非接触式工作模式，避免了机械磨损，具备长寿命、高可靠性及毫秒级响应速度，可在-40℃至150℃的严苛环境中稳定运行。该传感器主要分为数字型（输出开关信号，用于位置检测）和模拟型（输出连续信号，测量磁场强度）两类，广泛应用于汽车电子（转速检测）、工业自动化（限位控制）、智能家居（门窗感应）等领域，是实现精准磁感检测的关键元件。

## 原理图

## 尺寸图

## Arduino示例程序

```c++
#define DigitalPin  7//定义模块数字引脚

int  DigitalValue = 0 ;//定义数字变量,读取红外避障模块数字值

void setup()
{
  Serial.begin(9600);//设置串口波特率
  pinMode(DigitalPin, INPUT);//设置模块数字引脚为输入
}
void loop()
{
  DigitalValue = digitalRead(DigitalPin);//读取模块数字值
  Serial.print("InfraredObstacleAvoidanceModuleDigital Data:");
  Serial.println(DigitalValue);//打印模块数字值
  delay(200);
}
```

## MicroPython示例程序

### Esp32 MicroPython示例程序

```python
from machine import Pin
import time

DigitalPin = 14  # 定义模块数字接口引脚

p2 = Pin(DigitalPin, Pin.IN)  
        
while True:
    AnalogValue = p1.read_u16()  # 读取模块模拟值
    print("InfraredObstacleAvoidanceModuleDigital Data:", p2.value())  # 打印模块数字值
    time.sleep_ms(200)
```

### micro:bit MicroPython示例程序

```python
from microbit import *

DigitalPin = pin0  # 定义模块数字接口引脚

while True:
    AnalogValue = AnalogPin.read_analog()  # 读取模块模拟值
    print("Digital Data:", DigitalPin.read_digital())  # 打印模块数字值
    sleep(0.2)
```

## micro:bit示例程序

<a href="https://makecode.microbit.org/S65722-49364-86942-21338" target="_blank">动手试一试</a>
