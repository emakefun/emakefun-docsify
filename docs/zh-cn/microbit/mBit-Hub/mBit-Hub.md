# mBit-Hub 多功能扩展板

![mBit-Hub侧视图](picture/mbit-hub-face.jpg)

## mBit-Hub 简介

mBit-Hub 是一款为 micro:bit 量身打造的多功能扩展板，集 IO 引脚引出、PH2.0 接口、两路电机驱动于一体。一块板即可满足传感器接入、电机控制、外部供电等多种需求，无需额外搭配扩展板，让 micro:bit 项目开发更加简洁高效。

mBit-Hub 将 micro:bit 全部 19 路 PIN 引脚通过 PH2.0 接口和排针引出，板载两路电机驱动（M0/M1），提供 Type-C、USB、PH2.0、DC 头四种供电方式，适用于机器人、智能小车、创客项目等多种场景。

## mBit-Hub 参数介绍

- PCB 板厚度：1.6mm
- 圆孔直径：4.2mm
- 产品尺寸：70mm × 54mm
- 安装孔距：64mm × 48mm
- DC 输入电压：3.7~12V
- USB 输入电压：5V
- 电机驱动电压：5V
- 电机驱动电流：单路最大 350mA
- 电机控制方式：I2C 通信（地址 0x15）

## 机械尺寸图

![mBit-Hub尺寸图](picture/mbit-hub_drawing.png)

- 圆孔直径：4.2mm

## 原理图

![mBit-Hub原理图](picture/mbit-hub_Schematic.jpg)

<a href="mBit-Hub_Schematic.pdf" target="_blank">点击下载原理图</a>

## 硬件接口介绍

![硬件接口总览](picture/mbit-hub.jpg)

### 电源部分

![电源区域标注](picture/mbit-hub_power.JPG)

mBit-Hub 提供四种供电方式，板载电源升降压电路，可根据输入电压自动调节输出。

| 供电方式 | 接口类型 | 电压范围 |
|---------|---------|---------|
| Type-C 供电 | USB Type-C | 5V |
| USB 供电 | Micro-USB | 5V |
| PH2.0 供电 | PH2.0 2-pin | 3.7~12V |
| DC 供电 | DC 圆头 | 3.7~12V |

- **拨码开关**：板载 ON/OFF 拨码开关，控制整板电源通断
- **电源指示灯**：接通电源后红色电源指示灯点亮

> **注意**：多种供电方式请勿同时使用，以免造成损坏。

### 电机部分

![电机区域标注](picture/mbit-hub_motor.JPG)

mBit-Hub 集成两路电机驱动，可独立控制电机 M0 与 M1 。

#### 电机驱动参数

mBit-Hub 的电机驱动通过 I2C 协议（地址 0x15）接收指令输出 4 路 PWM 波，驱动两路电机。

- 适用电机类型：小型马达、微型水泵、TT 马达、N20 电机、积木马达等
- 单路最大驱动电流：350mA
- 最高驱动电压：5V

[点击查看电机驱动详情](../../ph2.0_sensors/actuators/dm11/dm11.md)

### 接口部分

![接口区域标注](picture/mbit-hub_E.JPG)

#### 金手指插槽

板载 micro:bit 金手指插槽，将 micro:bit 主板插入即可使用。插槽位于板子中央，插入时注意方向标识（箭头方向）。

#### PH2.0 接口

mBit-Hub 提供多种规格的 PH2.0 接口，将 micro:bit 全部 19 路 PIN 引脚引出：

| 接口类型 | 数量 | 说明 |
|---------|------|------|
| 5pin 接口 | 3个 |  多引脚组合引出（P0/P1/P8 等） |
| 4pin 接口 | 6个 |  双引脚引出，含两个 I2C 接口 |
| 3pin 接口 | 8个 |  单引脚引出 |

> 注意：涉及I2C引脚 (P19、P20) 的接口供电为5V，其余则为3.3V

#### 19路 pin 引脚

板载彩色排针（蓝色=IO引脚、红色=3.3V、黑色=GND），标注 P0~P20 全部引脚，可通过杜邦线灵活连接外部模块。

#### I2C 引脚

板载两路 I2C 专用引脚，包含 5V、SCL、SDA、GND 四个引脚，方便连接 I2C 通信模块。


