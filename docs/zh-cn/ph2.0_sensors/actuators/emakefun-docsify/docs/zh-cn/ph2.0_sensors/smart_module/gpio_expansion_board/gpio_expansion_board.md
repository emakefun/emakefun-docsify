# ADC/I2C/IO/PWM 四合一口扩展板

## 模块实物图

![实物图](picture/gpio_expansion_board.png)

## 概述

该模块是易创空间为了解决创客在使用中，主板的ADC/IO/I2C/PWM 不够用的场景而开发的一块扩展板，可以扩展出4路I2C接口，8路GPIO口；8路GPIO口可以通过软件分别配置成ADC、输入、输出或者PWM输出模式(1 ~ 10kHz)，其中PWM模式可以驱动**舵机**。配置接口为I2C接口，地址为0x24，背面有电阻焊接位可以修改I2C从机地址。

### 扩展引脚

| 扩展引脚类型 | 数量 |
| --- | --- |
| I2C | 4 |
| GPIO | 8 |

### GPIO引脚对应的功能

| GPIO引脚 | 可配置功能 |
| --- | --- |
| E0 | 可配置为ADC输入、数字电平输入、数字电平输出 |
| E1 | 可配置为ADC输入、数字电平输入、数字电平输出、PWM输出 |
| E2 | 可配置为ADC输入、数字电平输入、数字电平输出、PWM输出 |
| E3 | 可配置为ADC输入、数字电平输入、数字电平输出 |
| E4 | 可配置为ADC输入、数字电平输入、数字电平输出 |
| E5 | 可配置为ADC输入、数字电平输入、数字电平输出 |
| E6 | 可配置为ADC输入、数字电平输入、数字电平输出 |
| E7 | 可配置为ADC输入、数字电平输入、数字电平输出 |

### GPIO功能描述

| 功能 | 描述 |
| --- | --- |
| ADC输入 | 可把引脚配置为ADC模式，然后读取引脚的ADC值，精度10位，ADC值范围为0 ~ 1023 |
| 数字电平输入 | 可把引脚配置为默认上拉、下拉或者浮空输入，然后读取引脚高低电平值输入 |
| 数字电平输出 | 可把引脚配置为高低电平输出模式，然后使引脚输出高电平或者低电平 |
| PWM输出| 可配置扩展板的PWM输出频率（1 ~ 10000Hz），然后把引脚为PWM输出模式，再配置引脚PWM输出的占空比(12位精度：0 ~ 4095)，然后使引脚输出PWM，可用于驱动**舵机** |

## 模块参数

| 引脚名称 | 描述         |
| -------- | ------------ |
| G        | GND 地线     |
| V        | 3~5V电源引脚 |
| SDA      | I2C数据引脚  |
| SDL      | I2C时钟引脚  |

### Arduino 库和示例程序

[下载Arduino库](https://github.com/emakefun-arduino-library/emakefun_gpio_expansion_board/archive/refs/tags/release.zip)，包含Arduino库文件和[示例程序](https://github.com/emakefun-arduino-library/emakefun_gpio_expansion_board#%E7%A4%BA%E4%BE%8B%E7%A8%8B%E5%BA%8F)

### MicroBit库和示例程序

<a href="zh-cn/ph2.0_sensors/smart_module/gpio_expansion_board/io_expansion_board_i2c_microbit_micropython.zip" download>Micropython库和示例程序</a>

[Microbit MakeCode库链接](https://github.com/emakefun-makecode-extensions/emakefun_io_extension_board)

```
https://github.com/emakefun-makecode-extensions/emakefun_io_extension_board
```

### ESP32 MicroPython示例程序

<a href="zh-cn/ph2.0_sensors/smart_module/gpio_expansion_board/io_expansion_board_i2c_esp32_micropython.zip" download>库和示例程序</a>

### Mixly图形化库

![Mixly示例程序](picture/gpio_expansion_board_mixly.png)

![Mixly示例程序](picture/gpio_expansion_board_mixly.png)

<a href="zh-cn/ph2.0_sensors/smart_module/gpio_expansion_board/gpio_expansion_board_mixly.zip" download>下载mixly库和示例程序</a>

### Mind+图形化库

<a href="zh-cn/ph2.0_sensors/smart_module/gpio_expansion_board/emakefun-ext-i2c-expansion-thirdex-V2.0.0.mpext" download>下载Mind+库和示例程序</a>
