# ESP32-Uno 使用说明书

## 实物图

![实物图](picture\634fbf46abc9f8ceb363f8ce6ab26d4.jpg)

## 概述

ESP32-Uno是基于乐鑫科技的 ESP32-DOWD-V3 模组基础上开发的一款适用于创客教育的标志性产品，采用Uno模型，Flash 大小 4MB，集成 2.4 GHz、Wi-Fi 和蓝牙双模的单芯片方案。板载俩路编码电机与俩路直流电机，最大驱动电流 3A。

## ESP32模组参数

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

## 产品参数

* 2个编码电机端口（E0、E1）；2个直流电机端口（M0、M1）端口与编码电机复用；电流最大达到3A
* 其中E0(A:19 B:18 +:27 -:13)，E1(A:23 B:5 +:4 -:2)
* 22个IO引脚(0、2、4、5、12、13、14、15、16、17、18、19、23、25、26、27、32、33、34、35、36、39)
* 输入电压： 6-16V
* 产品尺寸：80mm×57mm；PCB厚度：1.6mm；净重：35g
* M4定位孔直径：4.6mm，兼容乐高
* 软件支持Mixly、Arduino IDE、Python

## 引脚说明

待补充

## 在Arduino IDE中驱动编码电机和直流电机

[点击查看编码电机和直流电机驱动方法](zh-cn/esp32/maker_esp32_pro/maker_esp32_pro.md#驱动编码电机与直流电机)
