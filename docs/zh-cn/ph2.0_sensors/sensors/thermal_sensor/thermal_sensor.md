# 热敏传感器

## 实物图

![实物图](picture/thermal_sensor.png)

## 概述

热敏电阻器是敏感元件的一类，按照温度系数不同分为正温度系数热敏电阻器(PTC)和负温度系数热敏电阻器(NTC)。热敏电阻器的典型特点是对温度敏感，不同的温度下表现出不同的电阻值。正温度系数热敏电阻器(PTC)在温度越高时电阻值越大，负温度系数热敏电阻器(NTC)在温度越高时电阻值越低，它们同属于半导体器件。  

## 原理图
[查看原理图](zh-cn\ph2.0_sensors\sensors\thermal_sensor\thermal_sensor_schematic.pdf ':ignore') 
![原理图](picture/thermal_sensor_schematic.png)

## 模块参数

| 引脚名称 |             描述              |
| :------: | :---------------------------: |
|    G     |              GND              |
|    V     |              VCC              |
|    S     | 温度越高时,读取的模拟值则越大 |

- 供电电压:3v3/5V

- 连接方式:3PIN防反接杜邦线

- 模块尺寸:40 x 22.5 mm

- 安装方式:M4螺钉兼容乐高插孔固定


## 机械尺寸图

![机械尺寸图](picture/thermal_sensor_assembly.png)

## Arduino示例程序

 [下载示例程序](zh-cn\ph2.0_sensors\sensors\thermal_sensor\thermal_sensor.zip ':ignore') 

```c++
#include "Buzzer.h"

#define ThermalePin  A3//定义热敏传感器模块引脚
#define buzzerPin 3//蜂鸣器模块引脚
Buzzer buzzer(BuzzerPin) ;

int  ThermalValue = 0 ;//定义数字变量,读取热敏值
void setup()
{
  Serial.begin(9600);//设置串口波特率
  pinMode(ThermalePin, INPUT);//设置热敏传感器模块引脚为输入
  pinMode(buzzerPin, OUTPUT);//设置LED模块引脚为输出
}
void loop()
{
buzzer.noTone();//蜂鸣器停止
  ThermalValue = analogRead(ThermalePin);//读取热敏值，并赋值给ThermalValue
  Serial.print("Thermal Data:  ");
  Serial.println(ThermalValue);//打印热敏值
  if (ThermalValue > 100) {//判断热敏值是否小于300
     for(int i = 200; i <= 800; i++)
     {
       buzzer.tone(i, 10);
     }
     for(int i= 800; i >= 200; i--)
     {
        buzzer.tone(i, 10);
     }
  } 
  delay(200);
}
```

## Micropython示例程序

### Esp32 Micropython示例程序

```python
热敏from machine import ADC,Pin
import time

AnalogPin = 15  # 定义热敏传感器模拟接口引脚

p1 = ADC(AnalogPin)
buzzer_pin = Pin(2, Pin.OUT)  # 定义蜂鸣器引脚

def alarm():
    for i in range(100):
        # 设置频率声音
        buzzer_pin.on()
        time.sleep_ms(1)
        buzzer_pin.off()
        time.sleep_ms(1)
        
while True:
    AnalogValue = p1.read_u16()  # 读取热敏传感器模拟值
    print(AnalogValue)  # 打印热敏传感器模拟值
    if AnalogValue > 100:
        alarm()
    else:
        buzzer_pin.off()
    time.sleep_ms(200)

```

### micro:bit示例程序

```python
from microbit import *

AnalogPin = pin1  # 定义热敏传感器模拟接口引脚
buzzer_pin = pin2  # # 定义蜂鸣器引脚

def alarm():
    for i in range(100):
        # 设置频率声音
        buzzer_pin.write_digital(1)
        sleep(1)
        buzzer_pin.write_digital(0)
        sleep(1)

while True:
    AnalogValue = AnalogPin.read_analog()  # 读取热敏传感器模拟值
    print("Analog Data:", AnalogValue)  # 打印热敏传感器模拟值
    if AnalogValue > 100:
        alarm()
    else:
        buzzer_pin.write_digital(0)
    sleep(0.2)
```

## Makecode示例程序

<a href="https://makecode.microbit.org/_56L5cVTJ5hU4" target="_blank">动手试一试</a>

![](picture/02.jpg)