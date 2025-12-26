# ESP32软件使用说明

此文档旨在介绍esp32主板在Arduino IDE2.0、Mixly、Mind+等平台的使用方法。

## 一丶通过Arduino IDE下载程序

请前往 [Arduino官网](https://www.arduino.cc/en/Main/Software) 下载最新IDE2.0版本

1. 打开Ardunio IDE2，点击Arduino IDE菜单栏：【文件】-->【首选项】

*将<https://jihulab.com/esp-mirror/espressif/arduino-esp32/-/raw/gh-pages/package_esp32_index_cn.json> 这个网址复制到附加管理器地址*

![add_esp](picture/add_esp.png)

2. 菜单栏点击 【工具】->【开发板】->【开发板管理器】搜索esp32，然后安装，如

![arduinoIDEESP32VersionInstall](picture/arduino_esp32_install.png)

安装完成后，打开IDE，先选择主板，如下图

![arduino_board_choice](picture/arduino_board_choice.png)

将写好程序点击上传按钮，等待程序上传成功，如下图。

![download](picture/download.png)

点击串口工具就可以看到串口的打印。如下图

**注意：**如果您程序无误，选择的主板也正确但是依然报错，请检查你电脑用户名字是否包含中文，如果包含中文请修改用户变量 “TEMP” “TMP”字段即可。修改方法请自行网上查资料。

![print](picture/print.png)

## 二丶Mixly使用(以Mixly2.0为例)

[Mixly2.0基础使用教程](/zh-cn/software/mixly/mixly.md) 请直接查看前面的介绍，这里只说明ESP32主板在mixly里面如何选择

1. 板卡选择
   a. 若是想用Arduino给ESP32编程则选择Arduino ESP32

![Mixly_Board](picture/Mixly_Board.png)

b. MicroPython则选择

![mixly_board](picture/mixly_board_micropython.png)

2. 主板选择，下图为使用Python ESP32板卡主板的选择， arduino esp32板卡主板选择ESP32 Dev  Module；

![esp32_main_board](picture/esp32_main_board.png)

3. 导入案例

![esp32_open_example](picture/esp32_open_example.png)

4. 下载；使用Python ESP32板卡时，上传程序前，需要先选择串口后，初始化固件(左上角初始化固件按钮)，再上传编写好的程序。

![esp32_mixly_download_success](picture/esp32_mixly_download_success.png)

## 三丶Mind+

[Mind+基础使用可以查看前面的介绍](/zh-cn/software/mind_plus/mindplus.zh-CN.md)这里只介绍，如何安装ESP32主板在Mind+里面如何选择

1、安装打开软件选择模式和语言，从扩展中进去选择主板![mind_plus_mode_select](picture/mind_plus_mode_select.png)

2、点击选择FireBeetle ESP32-E主板，如下图

![mindplusSelectMainBoard](picture/mindplusSelectMainBoard.png)

## 四丶MicroPython

MicroPython语法中文文档请参考[在 ESP32 上开始使用 MicroPython —MicroPython中文 1.17 文档](http://micropython.com.cn/en/latet/esp32/tutorial/intro.html)

固件请到[micropytho.org官网下载](https://micropython.org/download/ESP32_GENERIC/)

编程工具推荐[Thonny](/zh-cn/software/thonny/thonny.zh-CN.md)
