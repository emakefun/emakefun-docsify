# NLCS11颜色识别模块

## 模块实物图

![颜色识别传感器模块](color_sensor_nlcs11.jpg )

## 概述

NLCS11是一款基于颜色的光到数字的转换器，它结合了光电二极管、电流放大器、模拟电路和数字信号处理器。

为了提高精度，让颜色管理更加准确。板载自带一个高亮LED，可以让传感器在低环境光的情况下依然能够正常使用，实现“补光”的功能，可以通过LED Switch开关对它进行打开或关闭。颜色识别传感器模块采用I2C通信，拥有PH2.0防反插接口，使用便利。

NLCS11设备可进行色温测量、亮度传感。内部状态机提供了将设备置于色温测量之间的低功率状态的能力，非常低的平均功耗。

此设备可以应用于亮度传感器、彩色温度传感器、小笔记本、穿戴设备、工业及医疗等领域。

### 原理图

[点击下载NLCS11原理图](zh-cn/ph2.0_sensors/smart_module/color_sensor_nlcs11/color_sensor_sch.pdf ':ignore')

### 芯片规格书

[点击下载NLCS11规格书](zh-cn/ph2.0_sensors/smart_module/color_sensor_nlcs11/NLCS11.pdf ':ignore')

### 尺寸图

待补充

## 模块参数

- 工作电压：3.3-5V
- 工作电流：65uA
- 检测距离：3-10mm
- 时钟频率：0-400KHZ
- 接 口：IIC接口和2.54间距接口
- 温度范围：-30℃ ~ +70℃
- 通信方式:  IIC通信，地址0x43
- 尺 寸：22.4*38.4mm，兼容乐高积木和M4螺丝固定孔

## 引脚定义

| 引脚名称 | 描述        |
| -------- | ----------- |
| G        | GND     |
| V        | VCC  |
| SDA      | SDA |
| SCL      | SDL |

## Arduino示例程序（C/C++）

| 支持开发板系列    |
| :---------------- |
| Arduino UNO R3    |
| Arduino Nano      |
| Arduino Mega 2560 |
| ESP32             |

[点击下载Arduino库以及示例程序](zh-cn/ph2.0_sensors/smart_module/color_sensor_nlcs11/emakefun_color_sensor_nlcs11.zip ':ignore')

## Micropython示例程序

[点击下载Micropython库和示例程序](zh-cn/ph2.0_sensors/smart_module/color_sensor_nlcs11/read_rgb_py.zip ':ignore')

## Mixly图形化示例

待补充

## Mind+图形化示例

待补充
