# ESP32-Uno 使用说明书

## 实物图

![实物图](picture\634fbf46abc9f8ceb363f8ce6ab26d4.jpg)

## 概述

ESP32-Uno是基于乐鑫科技的ESP32-DOWD-V3 芯片基础上开发的一款尺寸兼容Uno尺寸适用于创客的产品，Flash 大小 4MB，集成 2.4 G Wi-Fi 和蓝牙双模的单芯片方案。板载两4路编码电机与两路直流电机，最大驱动电流 1.2A。板子还把多余的IO全部引出来，板子丝印标注为ESP32官方定义的IO顺序。

## ESP32芯片参数

* 448 KB ROM,520 KB SRAM,16 KB RTC SRAM
* QSPI 支持多个 flash/SRAM
* 内置 8 MHz 振荡器
* 支持自校准
* 内置 RC 振荡器，支持自校准
* 支持外置 2 MHz 至 60 MHz 的主晶振（如果使用 Wi-Fi/蓝牙功能，则目前仅支持 40 MHz 晶振）
* 支持外置 32 kHz 晶振，用于 RTC，支持自校准
* 2 个定时器群组，每组包括 2 个 64-bit 通用定时器和 1 个主系统看门狗
* 1 个 RTC 定时器
* RTC 看门狗
* 34 个 GPIO 口 • 12-bit SAR ADC，多达 18 个通道
* 带有专用 DMA 的以太网 MAC 接口，支持 IEEE 1588
* 双线汽车接口（TWAI®，兼容 ISO11898-1） • IR (TX/RX)

## 原理图

![原理图](picture\86512d3c5e12ad7351a493dcddfb0961.png)

[点击查看原理图](zh-cn/esp32/esp32-uno/esp32-uno.pdf ':ignore')

## 开发板参数

* TypeC接口，支持C2C数据线
* 串口芯片为CH340G芯片
* 2个直流电机端口（M0、M1）电流最大达到1.2A，端口可以通过板子上拨动开关进行电机驱动和IO口切换。
* 2个编码电机端口（E0、E1）和直流电机端口驱动引脚是复用；其中E0(A:19 B:18 +:27 -:13)，E1(A:23 B:5 +:4 -:2)
* 22个IO引脚(0、2、4、5、12、13、14、15、16、17、18、19、23、25、26、27、32、33、34、35、36、39)
* 5.5-2.1mm DC头接口 6-16V输入电压
* 产品尺寸： 68.6 x 53.4mm 兼容 Arduino Uno主板的尺寸
* 软件支持Arduino IDE、Mixly、Mind+、MicroPython

## 引脚说明

![引脚说明图](picture\Esp32_UNO_标注图.png)

## 在Arduino IDE中驱动编码电机和直流电机

[点击查看编码电机和直流电机驱动方法](zh-cn/esp32/maker_esp32_pro/maker_esp32_pro.md#驱动编码电机与直流电机)
