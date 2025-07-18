# RaspberryPi-Sensor-Board V4.0

[English](README.md) 中文版
 [深圳市易创空间科技有限公司](https://www.emakefun.com)出品
![picture0.jpg](./picture/picture0.jpg)

## 特点

- 支持8路ADC检测
- 内置10bit ADC MCU, ADC值范围为0 ~ 1023
- 支持树莓派 2B/3B/3B+/4/zero
- 5.5x2.1DC头与接线端子供电
- 外接传感器电压3V3与5V自由切换
- 板载DC-DC降压芯片 宽电压输入：5~36V 电压输出：5V 最大电流输出: 3A

## MCU规格

- 工作电压：3.3V和5V 根据跳线帽选择 ADC检查电压
- IO: 8路ADC检测
- 与树莓派通信方式: I2C
- I2C地址： 0x24

## 硬件概述

![pic_1.jpg](./picture/pic_1.jpg)

## 寄存器

&ensp;&ensp;&ensp;&ensp;扩展板MCU I2C地址为0x24，寄存地址说明如下：

![picture9.png](./picture/picture10.png)

- 0x10 ~ 0x17: 读取ADC原始数据

- 0x20 ~ 0x27: 读取输入电压，单位是mv

- 0x30 ~ 0x37: 读取输入电压与输出电压的比,输入电压/输出电压(0~100)

## 树莓派I2C库安装

&ensp;&ensp;&ensp;&ensp;打开树莓派终端输入"sudo raspi-config"命令，然后按照下图顺序依次操作即可。

![本地图片](./picture/picture1.png)

![本地图片](./picture/picture2.png)

![本地图片](./picture/picture3.png)

![本地图片](./picture/picture4.png)

&ensp;&ensp;&ensp;&ensp;以上就是开启树莓派I2C，接下来我们安装树莓I2C库在终端输入“sudo apt-get install i2c-tools”，输入完成后就可以看到正在下载I2C库，安装完成之后可以在终端输入“sudo i2cdetect -l”检测是否安装正确，若出现类似于下面的信息就说明安装正常。

![本地图片](./picture/picture5.png)

&ensp;&ensp;&ensp;&ensp;在终端输入“sudo i2cdetect -y 1”命令即可扫描接在I2C总线上的所有I2C设备，并打印出该设备的I2C总线地址，且我们的扩展板的I2C地址为0x24。

![本地图片](./picture/picture6.png)

!!! 编辑config.txt文件设置树莓派IIC总线速度

    sudo nano /boot/config.txt

查找包含“dtparam=i2c_arm=on”的行，添加“，i2c_arm_baudrate=100000”，其中100000是新设置的速度(100kbit /s)，注意i2c前面的逗号。完整代码如下：

    dtparam=i2c_arm=on,i2c_arm_baudrate=100000

这样可以启用I2C总线的同时，也完成了新波特率的设置。编辑完成后，使用CTRL-X，然后选择Y，再按下回车键，保存文件并退出。

![本地图片](./picture/picture7.png)

重新启动树莓派，使新的设置生效:

    sudo reboot

## 读取ADC模拟值

&ensp;&ensp;&ensp;&ensp;众所周知，Raspberry Pi中没有ADC，因此不能直接读取传感器的模拟值。在扩展板内置的MCU STM32的帮助下可以读取10位ADC这就意味着可以在树莓派上使用模拟传感器，且一共有8个可用的接口。

&ensp;&ensp;&ensp;&ensp;模拟传感器将模拟电压输入10位模数转换器。模数转换器将模拟数据转换成数字数据后，通过I2C将数字数据输入到树莓派中。

### Python 代码

<a href="https://gitee.com/jiexinjx/sensor_expansion_board/repository/archive/master.zip" download>Python 代码</a>

### Python 示例

```python
from sensor_expansion_board_i2c import IoExpansionBoardI2c
from smbus2 import SMBus
import time

# 初始化I2C总线
i2c_bus = 1  # 树莓派上的I2C总线号，通常是1
i2c_address = 0x24  # I2C设备地址

# 创建IoExpansionBoardI2c对象
io_expansion_board_i2c = IoExpansionBoardI2c(i2c_bus, i2c_address)

# 设置引脚7为ADC模式
io_expansion_board_i2c[7].mode = IoExpansionBoardI2c.ADC_MODE

# 循环读取ADC值
try:
    while True:
        adc_value = io_expansion_board_i2c[7].adc_value
        print(adc_value)
        time.sleep(1)  # 延时1秒
except KeyboardInterrupt:
    # print("程序已停止")
    pass
```

### C++ 代码

<a href="https://gitee.com/jiexinjx/sensor_board/repository/archive/master.zip" download>C++ 代码</a>

### C++ 示例

```c++
#include <chrono>
#include <iostream>
#include <thread>

#include "gpio_expansion_board.h"

// 创建 GpioExpansionBoard 实例
GpioExpansionBoard gpio_expansion_board;

int main() {
  std::cout << "Setup" << std::endl;

  // 配置E0为ADC模式
  if (!gpio_expansion_board.SetGpioMode(GpioExpansionBoard::kGpioPinE0, GpioExpansionBoard::kAdc)) {
    std::cerr << "Failed to set GPIO mode for E0" << std::endl;
    return -1;
  }

  while (true) {
    // 读取E0的ADC值并打印
    uint16_t adc_value = gpio_expansion_board.GetGpioAdcValue(GpioExpansionBoard::kGpioPinE0);
    std::cout << "ADC value: " << adc_value << std::endl;

    // 延时100毫秒
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}
```

&ensp;&ensp;&ensp;&ensp;如果在生成当前文件时出现以下错误：

![本地图片](./picture/picture8.png)

&ensp;&ensp;&ensp;&ensp;如果出现这种问题时请修改生成命令入下图设置：

&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;Compile&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;gcc -Wall -c "%f"

&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;Build&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;gcc -Wall -o "%e" -lwiringPi "%f"

&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;Lint&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;cppcheck --language=c --enable=warning,style --template=gcc "%f"

![本地图片](./picture/picture9.png)
