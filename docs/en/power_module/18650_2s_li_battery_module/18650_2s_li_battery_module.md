# [Two 18650 Lithium Battery Modules](http://localhost:3000/#/zh-cn/power_module/18650_2s_li_battery_module/18650_2s_li_battery_module?id=两节18650锂电池锂电池模块)

## [Physical picture](http://localhost:3000/#/zh-cn/power_module/18650_2s_li_battery_module/18650_2s_li_battery_module?id=实物图)



![Physical picture](http://localhost:3000/zh-cn/power_module/18650_2s_li_battery_module/picture/18650_2s_li_battery_module.png)



## [Overview](http://localhost:3000/#/zh-cn/power_module/18650_2s_li_battery_module/18650_2s_li_battery_module?id=概述)

 8.4V lithium battery charging module, with 2 18650 battery boxes on board. Directly charge with 5V voltage through the USB interface, the maximum charging current reaches 1.2A, the TypeC interface supports PD fast charging, the maximum charging current is 15W, two 2000mA lithium batteries are charged, and the fastest time is 1 hour. Directly output the lithium battery voltage through the PH2.0 interface.

## [Module parameters](http://localhost:3000/#/zh-cn/power_module/18650_2s_li_battery_module/18650_2s_li_battery_module?id=模块参数)

- Micro-USB interface charging input voltage: 5V 1.2A
- TypeC interface supports fast charging: maximum 15W input charging
- Boost charging efficiency 94%
- Battery type: 18650 lithium battery (full voltage 8.4V)
- Module size: 86*42mm
- Installation method: M3 screw fixation
- Integrated output overcurrent, input undervoltage, overvoltage, overtemperature, battery reverse connection and other protection functions, supports balanced charging

## [Charging process](http://localhost:3000/#/zh-cn/power_module/18650_2s_li_battery_module/18650_2s_li_battery_module?id=充电过程)

When the battery voltage is less than 3.7V, the battery is charged at a current of 50mA. When the battery voltage is greater than 3.7V and less than 6V, the battery is charged at a current of 100mA. When the battery voltage is greater than 6V, it is charged at a set constant current of 1.2A; When the battery voltage is close to 8.4V, it enters the constant voltage charging mode. After the battery is fully charged and the input continues to exist, if the battery voltage is less than 8V, the charging will start again

## [Fast charging process](http://localhost:3000/#/zh-cn/power_module/18650_2s_li_battery_module/18650_2s_li_battery_module?id=快充过程)

When the battery voltage VBAT<6.2V, do not apply for fast charging, just charge with 5V input; When the battery voltage is 6.2V<=VBAT<6.8V, try to apply for 5.4V input fast charging; When the battery voltage is 6.8V<=VBAT<7.8V, try to apply for 6V input fast charging; When the battery voltage VBAT>=7.8V, try to apply for 7V input fast charging

## [LED Status Description](http://localhost:3000/#/zh-cn/power_module/18650_2s_li_battery_module/18650_2s_li_battery_module?id=led状态说明)

| led                         | describe                                                     |
| --------------------------- | ------------------------------------------------------------ |
| Power blue indicator light  | When the toggle switch is turned to ON, the blue power light will turn on. |
| REV BAT Red indicator light | When the batteries in the 18650 battery box are connected reversely, the corresponding red light will light up. |
| CHG Green indicator         | The green light is always on when charging. The light goes out when fully charged. |

## [Mechanical Dimensions](http://localhost:3000/#/zh-cn/power_module/18650_2s_li_battery_module/18650_2s_li_battery_module?id=机械尺寸图)



![Mechanical Dimensions](http://localhost:3000/zh-cn/power_module/18650_2s_li_battery_module/picture/18650_2s_li_battery_module_cad.png)