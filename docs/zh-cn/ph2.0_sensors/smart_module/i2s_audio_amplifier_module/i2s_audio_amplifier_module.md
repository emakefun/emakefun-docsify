# I2S音频放大器模块

## 实物图

![实物图](picture/01.jpg)

## 概述

本模块是以MAX98375为主控芯片，是一款高效、低噪声、高集成度的 D 类音频功放模块，特别适合对功耗和抗干扰要求高的便携式音频设备。其 I2S 数字输入、防失真功能和丰富的保护机制使其在消费类电子产品中具有广泛的应用前景。

## 主要特性

- I2S串行数字音频输入接口
- 支持宽范围采样速率：8kHz~96kHz
- 自动采样率检测，自适应功能
- 内置数字高通滤波器，一线脉冲设置其转折点
- 左右声道可选，通过CTRL管脚电平设置
- 防失真NCN功能，  
- 无需滤波器的Class D放大器
- 输出功率：2.5W(VDD=5V, RL=4Ω)
- 工作电压范围：3.0V～5.5V
- 0.2%THD（VDD=5V, RL=4Ω, Po=1W）
- 80%的效率(VDD=5V, RL=4Ω, Po=2.5W)
- 优异的“上电，掉电”噪声抑制
- 过流保护、过热保护、欠压保护
- eSOP8封装

## 原理图

![原理图原理图](schematic_diagram.png)

[点击此处查看原理图](zh-cn/ph2.0_sensors/smart_module/i2s_audio_amplifier_module/MAX98375_i2s_dac_amp.pdf ':ignore')

## 芯片规格书

[点击此处查看芯片规格书](http://www.szczkjgs.com/UploadFiles/fujian/3725/NS4168.pdf)

## 使用示例

本模块可搭配I2S麦克风模块使用。

[点击查看使用示例](zh-cn/ph2.0_sensors/smart_module/i2s_mems_mic/i2s_mems_mic.md#Arduino使用示例)

## 蓝牙音响实验

示例接线图：

| ESP32 | MAX98375 |
| ----- | -------- |
| 3.3V  | VCC      |
| GND   | GND      |
| IO14  | BCLK      |
| IO15  | LRCK      |
| IO22  | DIN      |

<a href="zh-cn/ph2.0_sensors/smart_module/i2s_audio_amplifier_module/ESP32-A2DP.zip" download>点击出下载示例代码以及zip库文件</a>

在本次实验中，我们在Arduino IDE中运行。

在编写程序之前，先选择相应主板型号。

![up_esp32](picture/up_esp32.png)

在上传此程序之前，需要先导入相关库文件，步骤如下：

![导入库文件](picture/add_lib_1.png)

![导入库文件](picture/add_lib_2.png)

更新库文件后，打开示例程序'bt_music_receiver_arduino_i2s',如下图所示：

![i2s_music_receiver](picture/example.jpg)

再按如下选择内存选项以免编译时报内存溢出错误。

![选择内存](picture/option.jpg)

编译成功后，烧写到开发板上。

### 实验结果

上传示例程序后，打开手机蓝牙设置（电脑蓝牙设置），搜索周围蓝牙设备，例如本实验中设备名称为“MyMusic”，点击连接配对，配对成功后，即可外放音频，达到蓝牙音响的效果。

| ![s1](picture/s1.jpg) | ![s2](picture/s2.jpg) | ![s3](picture/s3.jpg) |
| ---------------------- | ---------------------- | ---------------------- |
|                        |                        |                        |
