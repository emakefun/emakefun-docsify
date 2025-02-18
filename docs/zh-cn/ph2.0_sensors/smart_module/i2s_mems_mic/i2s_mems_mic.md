# I2S麦克风模块使用说明

## 实物图

![实物图](picture\fe4db4fa6d60ad4f65a781c77422d75.jpg)

## 概述

该款MEMS数字I2S麦克风模块以ICS43434位主控芯片，凭借其小巧的体积、高灵敏度和低噪音特性，非常适合用于各种需要高质量音频输入的应用场景。结合ESP32等主控设备的强大处理能力，用户可以轻松实现语音识别、录音、AI学习等功能。

## 原理图

![原理图](picture/企业微信截图_17397591702741.png)

## 芯片规格书

[点击查看I2S麦克风模块规格书](zh-cn/ph2.0_sensors/smart_module/i2s_mems_mic/ICS-43434.pdf ':ignore')

## 模块参数

- 工作电压：DC 3.3V
- 麦克风封装工艺：MEMS
- 方向性：全向
- 数据接口：I2S
- 声压等级：140dB
- 信噪比：59dB

## ESP32 Arduino 使用示例

### 接线图

[I2S音频放大模块使用说明点击此处查看](zh-cn/ph2.0_sensors/smart_module/i2s_audio_amplifier_module/i2s_audio_amplifier_module.md)

|       名称        | 数量 |
| :---------------: | :--: |
|  ESP32-IOT_BOARD  |  1   |
| I2S音频放大器模块 |  1   |
|   I2S麦克风模块   |  1   |
|     喇叭模块      |  1   |
|  5PinPH2.0杜邦线  |  2   |
|    TypeC数据线    |  1   |

| 麦克风模块 | ESP32 |
| ---------- | ----- |
| SD         | 27    |
| WS         | 26    |
| SCK        | 25    |

| 音频放大器模块 | ESP32 |
| -------------- | ----- |
| BCLK           | 33    |
| LRLCK          | 32    |
| DIN            | 23    |

![接线图](picture\0d78779d3037b02b210861fc6a63f5b.jpg)

### Arduino使用示例

[点击下载Arduino示例代码](zh-cn/ph2.0_sensors/smart_module/i2s_mems_mic/esp32_i2s_rw.zip ':ignore')

将上述代码下载后解压打开test.ino文件，直接烧录至单片机即可运行。

![alt text](picture/1739764056471.jpg)

上传后，对着麦克风说话，即可在喇叭模块上听到声音。
