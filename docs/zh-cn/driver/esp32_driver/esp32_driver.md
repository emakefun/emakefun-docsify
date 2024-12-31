# ESP32 USB驱动安装

安装USB驱动是使用外部设备时的关键步骤。从网站中下载驱动文件后，根据用户计算机系统选择安装步骤：

## Windows10/11

系统自带驱动不需要额外安装。

## macOS

系统自带驱动不需要额外安装。

## Windows 7

1.识别设备 :  连接USB转串口适配器到计算机的USB端口，系统会尝试自动检测并安装驱动。如果未能成功，可以通过设备管理器，右键选择”扫描检测硬件改动“。查看未识别或带有黄色惊叹号的设备。

![](picture\1.png)

2.下载驱动 :  由于Windows  7的内置驱动可能不支持所有USB转串口设备，因此需要[下载驱动程序](https://dl.espressif.com/dl/idf-driver/idf-driver-esp32-usb-jtag-2021-07-15.zip)。文件名可能是“USB驱动适合win7系统”这样的表述，这表明它是专为Windows 7优化的驱动。

3.安装驱动 : 下载完成后，找到下载的驱动文件，一般为.exe或.zip格式。如果是.exe可执行文件，双击运行并按照提示操作；如果是.zip压缩包，需要先解压，然后找到setup.exe或其他安装文件进行安装。

4.手动安装 : 如果自动安装失败，可以尝试在设备管理器中手动更新驱动，选择“浏览我的电脑以查找驱动程序软件”， 然后指向解压后的驱动文件夹路径。

<img src="picture\2.png" style="zoom: 50%;" /><img src="picture\3.png" style="zoom: 50%;" />

点击“从磁盘安装“”浏览”

![](picture\4.png)

找到解压得到的.inf文件—

![](picture\5.png)

点击”确定“”下一步“后等待安装完成。

5.验证安装 : 安装完成后，重新检查设备管理器，确保USB转串口设备已正确识别并显示为COM端口。此时，应该可以使用串口通信软件（如HyperTerminal或RealTerm)与连接的设备进行通讯了。

如果安装不成功就需要用 [Zadig](https://zadig.akeo.ie/) 先给usb安装一个驱动：

 [Zadig安装usb驱动](https://blog.csdn.net/qq_62078117/article/details/135510767) 