# LGT-Mini-Nano

![实物图](picture/1.png)

## 概述

LGT-Mini-Nano是一款基于LGT（国内唯一兼容Atemgea328P）LGT8F328P芯片采用TSSOP20封装的小型开发板。它支持锂电池/外接电源，设有一个电机接口，四个插针引脚，可直插舵机、传感器模块。直接支持Mixly / Arduino IDE / BlockCode等编程软件。它尺寸仅46x20.4mm，低廉的价格、小巧的体积、且兼容arduino完善的生态，非常方便应用在创客小作品，科学小实验。

## 原理图

![原理图](picture/2.png)

点击查看：[原理图](zh-cn/lgt-arduino/LGT-Mini-Nano/LGT-Mini-Nano_Schematic.pdf ':ignore :target=_blank')、[LGT8F328P芯片规格书](zh-cn/lgt_arduino/LGT-Mini-Nano/LGT-Mini-Nano_Datasheet（LGT8F328P）.pdf ':ignore :target=_blank')

## 尺寸图

![尺寸图](picture/3.png)

点击下载：[2D文件](zh-cn/lgt-arduino/LGT-Mini-Nano/LGT-Mini-Nano_2D.zip ':ignore')、[3D文件](zh-cn/lgt_arduino/LGT-Mini-Nano/LGT-Mini-Nano_3D.zip ':ignore')

## 功能图

![功能图](picture/4.png)

## 特点

- 国产LGT8F328P-TSSOP20封装；
- 采用[nulllab软件包](https://github.com/nulllaborg/arduino_nulllab)相对于其他所谓兼容arduino芯片，LGT芯片兼容arduino生态达到99%；
- 供电电压3 ~ 5V，(建议使用3.7V锂电池供电使用)；
- 预留3pin排针4个，所有IO口全部引出；
- 预留1个I2C PH2.0接口，1个PH2.0电机接口；
- 驱动电流支持200mA。

## Mixly示例测试

点击跳转：[Mixly说明文档](zh-cn/software/mixly/mixly)，示例使用Mixly2.0。  

步骤1：下载程序需要使用专用[CH552-LGT-ISP编程器](zh-cn/lgt-arduino/LGT-Maker-Nano/CH552-LGT-ISP.md)左图接法（无外设），为避免下载过程失败。运行程序时需要拔掉编程器（参考采用右图接法），使用时推荐用电池供电。

![Mixly步骤1](picture/5.png)

步骤2：按上面左图接法连接电脑，然后打开Mixly软件，点击云端导入 选择**Nulllab LGT8F328P**板卡。

![Mixly步骤2](picture/6.png)

步骤3：选择刚才安装的板卡，进入编程界面。

![Mixly步骤3](picture/7.png)

步骤4：选择**LGT Mini Nano**主板，然后搭建图形程序，最后点击上传，也可[点击下载示例程序](zh-cn/lgt-arduino/LGT-Mini-Nano/LGT-Mini-Nano_Mixly.zip ':ignore')，测试现象为LED会间隔1s循环闪烁。

![Mixly步骤4](picture/8.png)

## BlockCode示例测试

点击进入：[BlockCode在线编程主页](https://make.blockcode.fun/ ':target=_blank')  

步骤1：硬件连接参考Mixly示例，然后点击下图LGT8F328P系列板卡，进入编程界面。

![BlockCode步骤1](picture/9.png)

步骤2：选中**LGT-Mini-Nano**主板，然后搭建图形程序，最后点击上传，也可[点击下载示例程序](zh-cn/lgt-arduino/LGT-Mini-Nano/LGT-Mini-Nano_BlockCode.zip ':ignore')，测试现象为LED会间隔1s循环闪烁。

![BlockCode步骤2](picture/10.png)

## Arduino IDE示例测试

步骤1：在开发板管理器地址栏输入：<https://download.null-lab.com/package_nulllab_boards_index_zh.json>

![Arduino步骤1](picture/11.png)

步骤2：选择LGT Mini Nano开发板及对应的COM端口后，点击上传程序，也可[点击下载示例程序](zh-cn/lgt-arduino/LGT-Mini-Nano/LGT-Mini-Nano_Arduino.zip ':ignore')，测试现象为LED会间隔1s循环闪烁。

![Arduino步骤2](picture/12.png)
