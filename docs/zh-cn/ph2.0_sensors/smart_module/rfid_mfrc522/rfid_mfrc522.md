# RFID-I2C模块

## 模块实物图

![实物图](picture/1714957948740.png)

## 概述

  本RFID模块使用最常见的非接触式读写卡芯片RC522。 底层采用I2C协议时序，可以应用于校园一卡通、水卡充值消费、公交卡充值消费设计、门禁卡等。接触性IC卡与读卡器之间通过无线电波来完成读写操作。二者之间的通讯频率为13.56MHZ。非接触性IC卡本身是无源卡，当读写器对卡进行读写操作时，读写器发出的信号由两部分叠加组成:一部分是电源信号，该信号由卡接收后，与本身的L/C产生一个瞬间能量来供给芯片工作。另一部分则是指令和数据信号，指挥芯片完成数据的读取、修改、储存等，并返回信号给读写器,完成一次读写操作。

## 芯片规格书

[芯片规格书点击此处查看](zh-cn/ph2.0_sensors/smart_module/rfid_mfrc522/mfrc522_chip_manual.PDF ':ignore')

## 尺寸图

![尺寸图](picture/8.png)

## 模块参数

| 工作电压5V       | 工作电流：13-100mA/DC 5V               |
| -------------------- | -------------------------------------- |
| 空闲电流：10-13mA/5V | 休眠电流：<80uA                        |
| 峰值电流：<100mA     | 工作频率：13.56MHz                     |
| 通讯协议：I2C        | 功率：<0.5W                            |
| 长宽尺寸：56*40mm    | 重量：7.6g                             |
| 支持多种卡片读写：mifare1 S50、mifare1 S70、mifare Ult等 | RFID电子标签，钥匙扣，钱币卡，IC白卡等 |
| 通信地址：0x28       |                                        |

## 模块测试

### 接线

| Arduino Uno | RFID模块 |
| ----------- | ------ |
| VCC           | VCC      |
| GND           | GND      |
| A5          | SCL    |
| A4          | SDA    |

RFID模块接在拓展板I2C端口上即可。

![接线图](picture/all.png)

### 测试

1.将[资料](#jump)中的Arduino 示例代码解压至相应目录。

2.打开RFID_test.ino文件。

![打开文件](picture/1.png)

3.选择开发板型号，并将开发板连接到电脑。（以Arduino Uno为例）

![选择开发板](picture/2.png)

4.选择相应COM口然后点击上传。

![上传程序](picture/3.png)

5.上传成功后，打开串口，波特率设置为115200。

![打开串口](picture/4.png)

6.将卡片放置在RFID模块上，串口会输出卡片的ID信息。

![输出卡片ID](picture/7.png)

## 开发板

| 支持开发板系列 |
| :------------- |
| Arduino UNO R3 |
| Arduino Nano   |
| ESP32          |
| Micro:Bit      |

## 资料下载

| 资料目录                                                     |
| ------------------------------------------------------------ |
| 芯片规格书                                                   |
| 机械结构图                                                   |
| Arduino库和示例程序（C/C++）                                 |
| ESP32库和示例程序（C/C++，MicroPython）                      |
| Micro:Bit库和示例程序（MicroPython,MakeCode）[MakeCode示例程序点击此处查看](https://makecode.microbit.org/S24813-08297-06583-21878) |
| Mixly示例程序                                  |
| Mind+库和示例程序                                                      |

<span id="jump"><a href="zh-cn/ph2.0_sensors/smart_module/rfid_mfrc522/data_collection.zip" download>上述资料点击此处下载</a></span>
