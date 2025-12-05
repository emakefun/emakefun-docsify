# ESP32S3-CAM

## 模块实物图

![产品实物图](picture/esp32s3-cam.png)

## 概述

​	ESP32S3-CAM是一款基于乐鑫[ESP32-S3R8芯片](https://documentation.espressif.com/esp32-s3_datasheet_cn.pdf )而开发的一款小尺寸的无线摄像头模块，该模块可以单独通过电池供电作为最小系统独立工作，尺寸仅为 `20.4*38.4*4.5mm`。本产品基于市面上已存在的ESP32S3-CAM优化而开发，主要解决市面上，下载程序需要外接下载底部，发热巨大，不稳定等问题。使用方法兼容现有的ESP32S3-CAM，网上有大量使用教程，可以直接参考使用。


## 引脚标注

![尺寸标注](picture/esp32s3_cam_pin.png)


## 主板参数

- 采用乐鑫原装ESP32-S3R8芯片，板载天线和IPEX天线座；
- 芯片内置384 KB ROM，520 KB SRAM，内置8M SPIRAM，外挂8M SPI FLASH；
- Type-C接口，usb直通ESP32S3芯片；
- 输入电压：typeC 5V 1A，背面预留3.7V电池焊点，板载充电电路；
- 背面预留PH2.0接口可以作为外设通信接口或者供电；
- 板载复位按键，和boot按键；
- 板载micro-SD卡插槽，MMC模式；
- 支持OV2640/OV3660摄像头， 内置2个 LED 闪光灯；
- 尺寸30.4mmx38.4mmx4.5mm；
- 2x8pin 2.54间距排针

## 板子尺寸标注

<a href="zh-cn/esp32/esp32s3-cam/esp32s3_cam.zip" target="_blank">下载3D文件</a>

![尺寸标注](picture/esp32s3_cam_size_mark.png)



### 板载陶瓷天线和IPEX天线切换

### ![antenna_switch](./picture/antenna_switch.png)

### <a href="zh-cn/esp32/esp32s3-cam/esp32s3_cam_sch.pdf" target="_blank">下载原理图</a>

![esp32s3-cam原理图](./picture/esp32s3_cam_sch.png)

### 安装驱动

win10以上或者mac系统都自动安装驱动无需安装驱动，如遇到特殊系统显示不出端口号请参考如下方法：

[安装驱动方法点击此处查看](/zh-cn/driver/esp32_driver/esp32_driver.md)

### 配置Arduino中的开发板

Arduino IDE上传方法请参考：[ESP32系列上传程序方法](zh-cn/esp32/esp32_software_instructions/esp32_software_instructions.md)

安装完成后即可选择对应的开发板：

![选择开发板](picture/esp32s3-cam_downloard.png)

### 上传示例程序

<a href="zh-cn/esp32/esp32s3-cam/CameraWebServer.zip" target="_blank">下载CameraWebServer程序</a>

### 测试效果

打开串口监视器，打开网页输入以下链接进入相机调试页面。

![调试页面](./picture/01.png)

串口显示以上信息，说明程序植入正确，若未出现以上信息，需要按上面的步骤逐一对照。

![串口显示](./picture/02.png)

点击Start Stream即可打开摄像头调参

![调参](./picture/03.png)

拖动LED Intensity滑动条，可以调节摄像头闪光灯的亮度。

## micropython应用

<a href="zh-cn/esp32/esp32s3-cam/esp32s3-cam_micropython_demo.zip" target="_blank">下载ESP32S3-CAM micropython固件</a>

```
系统终端输入如下烧录命令
.\esptool.exe --chip esp32S3  -b 460800 write_flash  0 "firmware.bin"  --erase-all
```

或者使用esptool烧录工具