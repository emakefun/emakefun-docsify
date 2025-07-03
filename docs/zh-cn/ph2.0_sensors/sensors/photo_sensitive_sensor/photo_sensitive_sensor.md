# 光敏传感器模块规格书

## 实物图

![实物图](picture/photo_sensitive_sensor.png)

## 概述

众所周知，走廊中的语音控制灯除了语音控制外还有一个传感器，即光敏传感器。光电传感器也称为光敏电阻。它（光敏电阻，缩写为LDR）通常由硫化镉制成。当入射光上升时，电阻阻值会降低; 入射光减弱，阻值会增加。光敏电阻常用于光测量，控制和转换（光与电之间的变化）会发生变化（光变为电），它也可广泛应用于各种光控电路，比如控制 和调节灯以及光开关。 光敏电阻模块对环境光线最敏感，一般用来检测周围环境的光线的亮度，触发单片机或继电器模块等  。

## 原理图

 [查看原理图](zh-cn\ph2.0_sensors\sensors\photo_sensitive_sensor\photo_sensitive_sensor_schematic.pdf ':ignore')
![原理图](picture/photo_sensitive_sensor_schematic.png)

## 模块参数

| 引脚名称 |            描述             |
| :------: | :-------------------------: |
|    G     |             GND             |
|    V     |             VCC             |
|    S     | 光线强时,读取的模拟值则越大 |

- 供电电压:3v3/5V
- 连接方式:3PIN防反接杜邦线
- 模块尺寸:40 x 22.5 mm
- 安装方式:M4螺钉兼容乐高插孔固定

## 机械尺寸图

![机械尺寸图](picture/photo_sensitive_sensor_assembly.png)

## Arduino示例程序

<a href="zh-cn\ph2.0_sensors\sensors\photo_sensitive_sensor\photo_sensitive_sensor.zip" download>下载示例程序</a>

```c++
#define PhotosensitivePin  A3//定义光敏传感器模块引脚
int  PhotosensitiveValue = 0 ;//定义变量,读取光敏值

void setup()
{
  Serial.begin(9600);//设置串口波特率
  pinMode(PhotosensitivePin, INPUT);//设置光敏传感器模块引脚为输入
}
void loop()
{
  PhotosensitiveValue = analogRead(PhotosensitivePin);//读取光敏值
  Serial.print("Photosensitive Data:  ");
  Serial.println(PhotosensitiveValue);//打印光敏值
}
```

## MicroPython示例程序

### Esp32 MicroPython示例程序

```python
from machine import ADC,Pin
import time

AnalogPin = 2  # 定义光敏传感器模拟接口引脚

p = ADC(AnalogPin)

while True:
    AnalogValue = p.read_u16()  # 读取光敏传感器模拟值
    print("Photosensitive Data:", AnalogValue)  # 打印光敏传感器模拟值
    time.sleep_ms(200)
```

### micro:bit MicroPython示例程序

```python
from microbit import *

while True:
    p = pin1.read_analog() # 读取光敏传感器模拟值
    print("Photosensitive Data:", p)  # 打印光敏传感器模拟值
    sleep(1000)
```

## MakeCode示例程序

<a href="https://makecode.microbit.org/_ePdgoM28qVgV">动手试一试</a>
