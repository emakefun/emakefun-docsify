# 水深传感器

![实物图](picture/water_depth_sensor.png)

## 概述

水深传感器专为水质检测而设计，可广泛用于感应降雨，水位，甚至液体泄漏。该传感器的工作原理是将一系列暴露的走线连接到地，并在接地走线之间交错，即感应走线。传感器走线具有1MΩ的弱上拉电阻。电阻器将传感器迹线值拉高，直到一滴水使传感器走线短路到接地走线。可以将它与模拟引脚配合使用，以检测接地和传感器走线之间的水接触量。

## 原理图

[查看原理图](zh-cn\ph2.0_sensors\sensors\water_depth_sensor\water_depth_sensor_schematic.pdf ':ignore') 
![原理图](picture/water_depth_sensor_schematic.png)

## 模块参数

| 引脚名称| 描述 |
|:--: |:--:|
| G | GND |
| V | VCC |
| S | 当模拟值越大，水的深度越深。 |

- 供电电压：3v3/5V

- 连接方式：3PIN防反接杜邦线

- 模块尺寸：56 x 22mm

- 安装方式： M3螺钉固定 


## 机械尺寸图

![机械尺寸图](picture/water_depth_sensor_assembly.png)

## Arduino示例程序

[下载示例程序](zh-cn\ph2.0_sensors\sensors\water_depth_sensor\water_depth_sensor.zip ':ignore')

```c++
#define DepthPin A3  // 定义水深传感器模拟接口引脚
#define BuzzerPin 3  // 定义水蜂鸣器引脚

int DepthValue;
Buzzer buzzer(BuzzerPin);

void setup() {
    Serial.begin(9600);  // 初始化串口通信
    pinMode(DepthPin, INPUT);  // 设置水深传感器引脚为输入
}

void loop() {
    buzzer.noTone();  // 停止蜂鸣器音调
    DepthValue = analogRead(DepthPin);
    if (DepthValue > 500) {		//如果水深大于500
        for (int i = 200; i <= 800; i++) {
            buzzer.tone(i, 10);  // 播放升调音调
        }
        for (int i = 800; i >= 200; i--) {
            buzzer.tone(i, 10);  // 播放降调音调
        }
    } 
    delay(200);  // 延时200毫秒
}
```

## Micropython示例程序

### Esp32 Micropython示例程序

```python
from machine import ADC,Pin
import time

AnalogPin = 15  # 定义水深传感器模拟接口引脚

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
    AnalogValue = p1.read_u16()  # 读取水深传感器模拟值
    print("Analog Data:", AnalogValue)  # 打印水深传感器模拟值
    if p2.value() > 500:	#如果水深大于500
        alarm()
    else:
        buzzer_pin.off()
    time.sleep_ms(200)


```

### micro:bit示例程序

```python
from microbit import *

AnalogPin = pin1  # 定义水深传感器模拟接口引脚
DigitalPin = pin0  # 定义水深传感器数字接口引脚

buzzer_pin = pin2  # # 定义蜂鸣器引脚

def alarm():
    for i in range(100):
        # 设置频率声音
        buzzer_pin.write_digital(1)
        sleep(1)
        buzzer_pin.write_digital(0)
        sleep(1)

while True:
    AnalogValue = AnalogPin.read_analog()  # 读取水深传感器模拟值
    print("Analog Data:", AnalogValue)  # 打印水深传感器模拟值
    print("Digital Data:", DigitalPin.read_digital())  # 打印水深传感器数字值
    if DigitalPin.read_digital() == 0:
        alarm()  # 如果水深传感器值为低电平则调用警报函数
    else:
        buzzer_pin.write_digital(0)  # 如果水深传感器值为高电平则蜂鸣器输出低电平
    sleep(0.2)
```

## Makecode示例程序

<a href="https://makecode.microbit.org/_i1ALFJiz18yE" target="_blank">动手试一试</a>

![](picture/01.jpg)