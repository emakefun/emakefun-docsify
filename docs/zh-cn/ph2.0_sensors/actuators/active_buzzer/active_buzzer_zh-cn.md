# 有源蜂鸣器



![active_buzzer](picture/active_buzzer.png)

## 概述

​	有源电磁式蜂鸣器是一种电子元件，用于产生声音信号。它由一个电磁线圈和一个振动片组成。当电流通过电磁线圈时，它产生一个磁场，使振动片受到吸引或推开的力，从而推动振膜振动发声振动。

​	有些电器在电气状态下经常会发出嗡嗡声，这实际上来自蜂鸣器，学校里铃声只是一个更大的蜂鸣器。 蜂鸣器有两种，一种是主动蜂鸣器，另一种是被动蜂鸣器。 “主动”和“被动”并不是指是否需要提供电源，而是指有或没有内部振荡器的蜂鸣器。有源蜂鸣器只要给它通电，就会发出嗡嗡声，但频率是固定的。 主要用于一些报警装置上，如烟雾报警器。

## 原理图

![buzzer_sch](picture/buzzer_sch.png)



## 模块参数

* 供电电压：3 ~ 5V；
* 连接方式：3pin PH2.0接口；
* 工作电流：30mA；
* 音压：85dB；
* 模块尺寸：38.4*22.4mm；
* 安装方式：M4螺钉兼容乐高插孔固定

| 引脚名称 | 描述                                       |
| -------- | ------------------------------------------ |
| V        | 3~5V电源输入                               |
| G        | GND地线                                    |
| S        | 信号引脚，高电平蜂鸣器响，低电平蜂鸣器不响 |

## 机械尺寸

![buzzer_size](./picture/buzzer_size.png)

<a href="zh-cn/ph2.0_sensors/actuators/active_buzzer/active_buzzer3D.zip" target="_blank">点击下载3D文件</a>

## Arduino IDE示例程序

```c++
#define BUZZER_PIN A3  // Set the buzzer port to A3

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);  // Set the buzzer port to output mode
}

void loop() {
  digitalWrite(BUZZER_PIN, HIGH);  // Set the buzzer port to high level
  delay(1);                        // Delay 1 ms
  digitalWrite(BUZZER_PIN, LOW);   // Set the buzzer port to low level
  delay(1);                        // Delay 1 ms
}
```

## microbit示例程序

<a href="https://makecode.microbit.org/_Fs1VH7MrtPAv" target="_blank">动手试一试</a>
