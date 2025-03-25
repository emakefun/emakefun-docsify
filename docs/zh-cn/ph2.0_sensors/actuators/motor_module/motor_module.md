# 单路电机驱动模块

## 实物图

![实物图](picture/physical_drawing.jpg)

## 概述

该模块用于驱动一个直流电机，其工作原理是通过控制电机的转速来驱动电机转动。很大程度上方便了用户使用电机，不需要了解电机的工作原理，只需要通过PWM信号控制转速即可。

## 原理图

TIDO

## 模块参数

- 电压： 5V
- 接口： 俩种接线方式，接线柱或者PH2.0接口
- 电机： 直流电机
- 尺寸： 40 * 22.5 mm

接线方式： 将模块左侧接至单片机的PWM输出引脚，右侧接至电机的电源输入端即可。

## Arduino代码示例

```c++
#define INA 5   //定义电机A.B端口
#define INB 6   //
void setup() {
  pinMode(INB, OUTPUT);  //设置电机端口为输出模式
  pinMode(INA, OUTPUT);  //
}

void loop() {
  analogWrite(INA, 255);  //设置A端口为高电平
  analogWrite(INB, 0);    //设置B端口为低电平
  delay(2000);            // 2s之后电机反转
  analogWrite(INA, 0);    //设置A端口为低电平
  analogWrite(INB, 255);  //设置B端口为高电平
  delay(2000);            //电机反转2s然后正转
}
```
