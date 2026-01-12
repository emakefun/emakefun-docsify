# 矩阵键盘模块V3.0

![矩阵键盘](picture/matrix_keyboard.png)

## 概述

触摸键盘模块是通过 <a href="zh-cn/ph2.0_sensors/base_input_module/matrix_keyboard_module_v3.0/VK36N16I_datasheet.pdf" target="_blank">VK36N16I</a> 芯片驱动，共16个触摸键。VK36N16I芯片是一款使用电容感应式原理设计的触摸芯片，可用来检测外部触摸按键上人手的触摸动作。该系列的芯片具有较高的集成度，仅需极少的外部组件便可实现触摸按键的检测。模块使用IIC通讯，可方便与外部 MCU 之间的通讯，实现检测触摸引脚是否被触摸的目的。

## 原理图

![keypboard_v3.0_sch](picture/keypboard_v3.0_sch.png)

## 模块参数

- 供电电压：3.3V ~ 5V

- 接 口：I2C接口和PH2.0间距接口

- 连接方式：PH2.0 4PIN防反接线

- 通信方式：I2C通信，地址0x65

- 模块尺寸：56*70mm

- 安装方式：M4螺钉兼容乐高插孔固定

| 引脚名称  | 描述        |
| -------- | ----------- |
| G        | GND地线      |
| V        | 电源引脚     |
| SDA      | I2C数据引脚  |
| SCL      | I2C时钟引脚  |

## 机械尺寸图

![机械尺寸图](picture/keyboard_cad.png)

## Arduino 应用

<a href="https://gh-proxy.com/https://github.com/emakefun-arduino-library/emakefun_matrix_keyboard_v3/archive/refs/tags/v1.0.1.zip" download>点击此处下载Arduino示例程序</a>

### Arduino 库API使用文档

<a href="https://emakefun-arduino-library.github.io/emakefun_matrix_keyboard_v3/html/zh-CN/classemakefun_1_1_matrix_keyboard.html" target="_blank">点击此处查看API说明文档</a>

### Arduino 库示例程序

<a href="https://emakefun-arduino-library.github.io/emakefun_matrix_keyboard_v3/html/zh-CN/get_current_pressed_key_8ino-example.html" target="_blank">获取当前按下的按键值</a>

<a href="https://emakefun-arduino-library.github.io/emakefun_matrix_keyboard_v3/html/zh-CN/print_key_state_8ino-example.html" target="_blank">循环判断每个按键的状态</a>

## MicroPython 示例程序

### ESP32 MicroPython示例程序

<a href="https://gh-proxy.com/https://github.com/emakefun-micropython-lib/em_mpy_matrix_keyboard/archive/refs/tags/v1.0.1.zip" download>点击下载ESP32 MicroPython示例程序</a>

## Mixly示例程序

 [Mixly2.0云端导入PH2.0 Sensors库](/zh-cn/software/mixly/mixly)，导入成功后，点击EmakefunSensors库，选择基础输入模块，找到

矩阵键盘V3.0块，如下图：

![mixly](picture/matrix_keyboard_v3.0_mixly.png)

矩阵键盘Mixly案例

![mixly_example](picture/matrix_keyboard_v3.0_mixly_example.png)

通过连接线连接矩阵键盘的I2C接口，将程序下载到Arduino主板，触摸键盘Arduino串口打印相对应的键盘值。

<a href="zh-cn/ph2.0_sensors/base_input_module/matrix_keyboard_module_v3.0/matrix_keyboard_v3_mixly_example.zip" download>点击下载mixly uno/ep32案例</a>

## mind+示例程序

mind+ 软件arduino uno、esp32库为同一个， <a href="zh-cn/ph2.0_sensors/base_input_module/matrix_keyboard_module_v3.0/matrix_keyboard_v3_mind_plus.zip" download>点击下载mind+案例</a>

## micro:bit MakeCode示例程序

扩展包地址: <https://github.com/emakefun-makecode-extensions/emakefun_matrix_keyboard_v3>

<a href="https://makecode.microbit.org/_E4Rdk21MdCzL" target="_blank">点击此处查看示例程序</a>

示例程序说明：将矩阵键盘和板子I2C接口进行连接，示例程序成功编译运行后，按下键盘上的按键，microbit点阵屏上会显示按键按下的值，如按下"1"，点阵屏会显示"1"，再按下"A"会显示"A"。

**请注意，由于该示例程序中有使用点阵屏显示块，然而Microbit的点阵屏显示块会有500毫秒的阻塞，所以在显示过程中按下新的按键不会马上显示新的值，会有不太灵敏的效果，但是这并不是由矩阵键盘硬件或者软件引起的**

如果将点阵屏显示换成串口输出显示，效果会好很多，<a href="https://makecode.microbit.org/_54m4wjYdUX6e" target="_blank">点击查看串口打印矩阵键盘值程序</a>
