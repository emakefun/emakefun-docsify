
# 概述

|RUS-04(黑色款)|RUS-04蓝色款|
| :-: | :-: |
| ![RUS-04_Black](picture/rus_04_top.png) | ![RUS-04_Blue](picture/rus_04_blue.png) |

## 产品简介

​  RUS-04是一款内置rgb彩灯，单总线超声波测距模块。 每个探头内部集成3颗WS2812彩灯，可通程序控制 rgb彩灯，模块在测距的同时，探头也能显示各种颜色。特别应用于玩具超声测距，机器人等应用。 2CM 超小盲区，4M 典型最远测距。采用自研超声波测距解调芯片，单总线，外围更加简洁，芯片内置高精度振荡器，无需额外晶振。驱动采用扫频技术，减少探 头本身一致性对模块灵敏度的影响。

## 模块参数对比

|型号|HC-04|RUS-04（蓝色）|US-04|RUS-04（黑色）|
| :-: | :-: | :-: | :-: | --- |
|图片|![HC-04](./picture/HC-04.jpg)|![rus_04_blue](./picture/rus_04_blue.png)|![US-04](./picture/US-04.jpg)|![rus_04_top](./picture/rus_04_top.png)|
| 工作电压 | 3~5.5V | 4.5V~5.5V | 3.5V~5.5V |4.5V~5.5V|
| 功耗电流| 3mA | 不开灯珠15mA<br/>开灯珠65mA | 开灯珠65mA |不开灯珠15mA<br/>开灯珠65mA|
| RGB灯珠数量 | 0颗 | 6颗 | 6颗 |0颗|
| 谐振频率 | 40K | 40K | 40K |40K|
| 探测距离范围 | 3.5~6米 | 2cm～4米 | 2cm～4米 |2cm～4米|
| 探测精度 | 1cm±2% | 1cm±2% |        1cm±2%        |1cm±2%|
| 探测角度 | < ±15-20° | < ±15-20° | < ±15-20° |< ±15-20°|
| 测量周期时间 | 200ms | 50ms | 50ms |60ms|
| 工作温度范围 | -10℃~60℃ | -10℃~80℃ |       -10℃~80℃       |-10℃~80℃|
| 外形尺寸 | 45.2*20.4mm | 45.2*20.4mm | 48*24mm |一款与RUS-04一样<br>二款与RUS-04(黑色款)一样|
| 接口 | 4pin-2.54mm | PH2.0/Grove/插针接口 | PH2.0/Grove/RJ25接口 |PH2.0/Grove/RJ25接口|
| 通讯引脚 | VCC/Trig/Echo/GND | G/V/IO/RGB |        G/V/Trig/Echo         |G/V/IO/RGB|

## 接口定义

## 模块结构图

### RUS-04（蓝色款）和HC-04（普通款）尺寸图

​             ![RGB](picture/rus_04_blue_cad.png)

### RUS-04（黑色款、蓝色款）尺寸图

![RUS-04](picture/rus_04_cad.png)

# 模块原理介绍

## 超声波部分测量操作

![5](picture/5.png)

​  外部 MCU 初始设置为输出，给模块 I/O 脚一个大于 10uS 的高电平脉冲；输出脉冲信号后，MCU 设置 为输入模式，等待模块给出的一个与距离等比的高电平脉冲信号；测量结束后 MCU 设置为输出模式，进行下次测量。声速可根据脉宽时间“T”算出：

### 距离=T（从发送信号至接收到信号的时间）*340/2 （ 340m/s是声音在空气中的传播速度）

![6](picture/6.png)

# RGB灯珠介绍

## RGB LED灯介绍

​  RUS-04为了使用方便采用了直接集成了LED驱动控制芯片的WS2812B-2020RGB灯珠，控制芯片内部包含了智能数字接口，数据锁存信号，整形放大驱动电路，还包含有高精度的内部振荡器和15V高压可编程定电流输出驱动器。

​  RUS-04收发探头分别各集成了3个RGB灯珠。只需一条信号线来控制各个RGB灯发光
Arduino需要控制探头的发光，需要专门的RGB库支持。

### 详情可以看<a href="zh-cn/ph2.0_sensors/sensors/rus_04/WS2812B.PDF" download>WS2812B规格书</a>

### 应用注意

- 供电必须要要在4.5~5V之间否则 rgb灯控制不对
- 测量周期时间在60ms以上
- 在测量距离时，手或者其他金属物体不可接触探头，否则影响发射和接收波形从而导致距离测量错误

### Arduino Uno示例程序

<a href="zh-cn/ph2.0_sensors/sensors/rus_04/RGBUltrasonicModule.zip" download>点击下载</a>

### Mixly

![rus_04_mixly](picture/rus_04_mixly.png)

<a href="zh-cn/ph2.0_sensors/sensors/rus_04/rus_04_mixly.zip" download>点击下载Mixly程序</a>

### ESP8266/ESP32示例程序

<a href="zh-cn/ph2.0_sensors/sensors/rus_04/ESP32_RGBUltrasonicModule.zip" download>点击下载</a>

### MicroPython示例程序

<a href="zh-cn/ph2.0_sensors/sensors/rus_04/rgb_ultrasonic_esp32_micropython.zip" download>点击下载ESP32 MicroPython示例程序</a>

## micro:bit MakeCode示例程序

<a href="https://makecode.microbit.org/_PtqVy7dDj4PJ" target="_blank">动手试一试</a>
