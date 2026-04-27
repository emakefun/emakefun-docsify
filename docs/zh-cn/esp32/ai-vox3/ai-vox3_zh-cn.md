# AI-VOX3主板介绍

## 概述

AI-VOX3是一款专为AI语音交互应用设计的高性能嵌入式开发板。其核心采用ESP32-S3-R8芯片，并板载16MB Flash存储器。集成了麦克风和功放喇叭、sdcard、电源管理等硬件资源，支持快速开发与灵活扩展。支持本地语音唤醒、指令识别和语音合成，可广泛应用于智能家居、教育设备和物联网终端等领域。同时配套AI-VOX3扩展板与MD40电机驱动板，助力开发者基于板载资源快速构建语音产品原型，并通过丰富接口实现个性化功能扩展，大幅缩短开发周期。

## 产品图

| 正面                                   | 反面 |
| -------------------------------------- | ---- |
| ![alt text](picture/AI-VOX3-Front.png) | ![alt text](picture/AI-VOX3-Back.png) |

## 功能标注图

![alt text](picture/AI-VOX3-Marked.png)

## 开发板特点

- 搭载 ESP32-S3R8 高性能 Xtensa 32 位 LX7 双核处理器，主频高达240MHz
- 支持 2.4 GHz Wi-Fi (802.11 b/g/n) 和 Bluetooth 5 (LE)，板载天线
- ESP32-S3R8芯片内置 512 KB SRAM 和 384 KB ROM以及8MB PSRAM，板载16 MB Flash 存储芯片
- 采用 Type-C 接口，支持程序下载、板载供电及锂电池充电，兼容主流开发环境，简化开发与电源管理流程
- 采用电源复位按键二合一，将系统复位和开关机集成到Power按键中，短按开机或系统复位，长按关机，简化操作
- 可接1.54寸240×240分辨率SPI接口LCD（ST7789），提供直观图形化交互界面
- 预留LCD排线和OLED插口，可以选择OLED或者LCD彩屏显示
- 板载ES8311音频编码解码器与3W音频放大器（NS4150B），支持高保真音频输入/输出，需外接喇叭
- 双麦克风设计，板载模拟麦克风，还预留MX1.25外挂模拟麦克风接口，支持单麦打断
- 板载SD Card接口，支持大容量存储扩展
- 板载BOOT按键、2个按键（IO46/45）及WS2812B（IO41） RGB灯，便于交互调试与状态指示
- 引出一组8个GPIO排针接口（IO43/44/42/48/4/3/2/1），支持多种外设接入
- 预留一个4pin PH2.0接口，可以方便通过PH2.0供电，也可以和其他主控通讯
- 配套外接AI-VOX3扩展板，可通过其扩展板的排针接口扩展更多功能
- 配套外接MD40电机驱动板，可通过其驱动板运行多个电机
- 板载充电升压5V 1.2A输出一体电路，支持外接锂电池供电，并通过IO18 ADC实时检测电量

## 充电说明

- USB TypeC接口 5V 最高1.2A；
- 充电升压转换效率95%；
- 黄绿色LED(chare)闪烁表示正在充电，常亮表示电池已经充满。

## 供电说明

- 可以通过TypeC接口供电（5V）；
- 可以通过ZH1.5锂电池充电（3.7~4.2V）；
- 可以通过PH2.0-4pin接口供电(5V)；
- 不管哪种方式供电，都需要短按PWR按键进行开机。

## PWR按键和LED灯说明

- 短按PWR按键开机，红色P灯亮起，长按PWR按键则关机，红色P灯熄灭；
- 短按PWR按键开机后，再次短按PWR按键是复位主控板。

## 原理图

<a href="zh-cn/esp32/ai-vox3/AI-VOX3_V1.1.pdf" target="_blank">点击查看AI-VOX3原理图</a>

## Arduino测试示例

Arduino IDE上传方法请参考：[ESP32系列上传程序方法](zh-cn/esp32/esp32_software_instructions/esp32_software_instructions.md)

安装完成后即可选择对应的开发板：

![ide_downloard_config](./picture/ide_downloard_config.png)

<a href="zh-cn/esp32/ai-vox3/ai-vox3_arduino_test_demo.zip" target="_blank">点击下载示例程序</a>

| 文件名             | 依赖库                                                       | 功能                                 |
| ------------------ | ------------------------------------------------------------ | ------------------------------------ |
| ai_vox3_lcd        | Arduino_GFX                                                  | 测试LCD显示屏                        |
| es8311_test        |                                                              | 麦克风和功放喇叭回环测试             |
| esp8311_sdmmc_test | [ESP32-audioI2S](https://github.com/schreibfaul1/ESP32-audioI2S) | 播放sdcard根目录下的test.mp3格式音乐 |

## AI-VOX3结构

<a href="zh-cn/esp32/ai-vox3/ai-vox3_3d.zip" target="_blank">点击下载AI-VOX3的3D模型</a>

## AI-VOX3做小智

AI-VO3可以用于制作小智AI，详细教程请见链接：https://dcnmu33qx4fc.feishu.cn/docx/VXHzdBYH0ohpNAxw2ifc3P2InBe