# LED模块



![led_mudule](picture/led_mudule.png)

## 概述

​	LED是发光二极管（Light Emitting Diode）的缩写， 是一种会发光的半导体组件且具备二极管的电子特性；所以，LED首先是一只二极管（结构），其次它会发光（功能） 。这种半导体是由混合化合物制成，即镓（Ga），砷（AS），磷（P）。 颜色由化合物半导体材料决定，砷化镓二极管发红光，磷化镓二极管发绿光，氮化镓二极管发蓝光，碳化硅二极管发黄光。

​                   ![led](picture/led.jpg)                           ![led_symbol](./picture/led_symbol.png)    

​	发光二极管的反向击穿电压为5v。 其正伏安特性曲线太陡，必须与限流电阻串联，以便在使用时控制流过管道的电流。 限流电阻R可通过以下公式获得:  R= (E- Vf) / I

在公式中，E代表电源电压，Vf是LED的正向压降，I表示LED的一般工作电流。 发光二极管的工作电压一般为1.5 V至2.0 V，工作电流通常为10~20 mA。 因此在5v的数字逻辑电路中，我们可以使用220Ω - 1K电阻作为限流电阻。

## 原理图

![原理图](picture/led_sch.png)

​	本模块已经板载1K限流电阻，S为控制信号引脚，本模块里面S为高电平，LED点亮，S为低电平时LED熄灭

## 模块参数

| 引脚名称 | 描述                         |
| -------- | ---------------------------- |
| V        | 电源输入，实际未使用到       |
| G        | GND地线                      |
| S        | 信号引脚，高电平亮，低电平灭 |

## 模块尺寸

![size_mark](picture/size_mark.png)

  <a href="zh-cn/ph2.0_sensors/displayers/led_module/led_structure.zip" download>下载LED模块2D和3D设计文件</a>  

## Arduino IDE点灯示例程序

```
int ledPin = 13;
void setup() {
  pinMode(ledPin, OUTPUT);    //设置LED为输出模式
}
void loop() {
  digitalWrite(ledPin, HIGH); // 高电平 点亮LED灯
  delay(1000);                // 延时1秒
  digitalWrite(ledPin, LOW);  // 低电平 熄灭LED灯
  delay(1000);
}
```

接入Arduino Uno主板上的13号引脚将控制LED灯 1S亮起 ，1S熄灭。


