# ESP32 AI小智聊天机器人模块使用说明

## 概述

ESP32 AI小智聊天机器人模块是一款基于ESP32芯片的AI聊天机器人，具备语音识别、语音合成、语音对话、语音唤醒等功能。

## 已实现功能

- Wi-Fi / ML307 Cat.1 4G
- BOOT 键唤醒和打断，支持点击和长按两种触发方式
- 离线语音唤醒 ESP-SR
- 流式语音对话（WebSocket 或 UDP 协议）
- 支持国语、粤语、英语、日语、韩语 5 种语言识别 SenseVoice
- 声纹识别，识别是谁在喊 AI 的名字 3D Speaker
- 大模型 TTS（火山引擎 或 CosyVoice）
- 大模型 LLM（Qwen, DeepSeek, Doubao）
- 可配置的提示词和音色（自定义角色）
- 短期记忆，每轮对话后自我总结
- OLED / LCD 显示屏，显示信号强弱或对话内容
- 支持 LCD 显示图片表情
- 支持多语言（中文、英文）

## 使用方法

### 硬件准备

[视频教程链接](https://www.bilibili.com/video/BV1XnmFYLEJN/?vd_source=ebdd12013edf6ee0e6759b8884b4e1eb)

| ESP32 引脚编号 | 连接外设                            |
| -------------- | ----------------------------------- |
| 25             | 麦克风（MIC）的 SCK 引脚            |
| 26             | 麦克风（MIC）的 WS 引脚             |
| 27             | 麦克风（MIC）的 DIN (DO) 引脚       |
| 23             | 扬声器（SPAKER）的 DOUT 引脚        |
| 33             | 扬声器（SPAKER）的 BCLK 引脚        |
| 32             | 扬声器（SPAKER）的 LRCK 引脚        |
| 21             | OLED 显示屏的 SDA 引脚              |
| 22             | OLED 显示屏的 SCL 引脚              |
| 34             | 启动按钮（BOOT BUTTON）             |
| 35             | 触摸按钮（TOUCH BUTTON）            |
| 36             | 语音识别按钮（ASR BUTTON）          |
| 4              | 内置 LED 按钮（BUILTIN LED BUTTON） |

按下图所示接线，将 ESP32 AI小智聊天机器人模块连接到您的主板上。

![接线图](picture/1.jpg)

### 烧录固件

[点击下载ESP32 Flash下载工具](zh-cn/ph2.0_sensors/smart_module/esp32_ai_xiaozhi/flash_download_tool.zip ':ignore')

将下载后的文件进行解压后打开'flash_download_tool_3.9.8_6.exe'文件.

![打开flash下载工具](picture/2.jpg)

chip type选择ESP32，点击OK。

![选择chip type](picture/3.jpg)

下载[ESP32 AI小智聊天机器人模块固件](zh-cn/ph2.0_sensors/smart_module/esp32_ai_xiaozhi/nulllab_esp32_xiaozhi.bin ':ignore')

选择刚刚下载的固件文件。

![选择固件](picture/4.jpg)

![选择固件](picture/5.jpg)

配置相关信息后勾选。

![配置相关信息](picture/6.jpg)

选择快速烧录模式。

![选择快速烧录模式](picture/8.jpg)

将主板通过type-C数据线连接电脑，选择相应COM口。

![烧录固件](picture/7.jpg)

等待烧录完成。

![烧录完成](picture/9.jpg)

### 网络配置

固件烧录完成后，按下esp32主板的Reset按键，进入配置模式。

![进入配置模式](picture/10.jpg)

打开手机wifi,连接对应WiFi后，配置要连接的WIFI名称和密码。

![配置WIFI](picture/11.jpg)

![配置WIFI](picture/12.jpg)

![配置WIFI](picture/13.jpg)

网络配置好后，去[小智AI平台](https://xiaozhi.me)进行激活

![小智AI平台](picture/14.jpg)

![小智AI平台](picture/15.jpg)

添加设备后，按下ESP32主板的Reset按键，进入语音交互模式。

### 语音交互

打开语音交互模式，按下语音按钮即GPIO口34处的按键，即可进行语音交互。

[更多信息可以参考小智 AI 聊天机器人百科全书](https://ccnphfhqs21z.feishu.cn/wiki/F5krwD16viZoF0kKkvDcrZNYnhb)

## 源码

本项目为开源项目，你可以[点击此处查看源码](https://github.com/nulllab-org/xiaozhi-esp32/tree/nulllab_esp32)
