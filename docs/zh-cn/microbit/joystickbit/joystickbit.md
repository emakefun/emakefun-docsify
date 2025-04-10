# Joystick:Bit

Joystick:Bit为**深圳市易创空间科技有限公司**出品的针对micro:bit开发的无线可编程手柄，支持micro:Bit V1、 V2;

 **MakeCode扩展链接为**: **<https://github.com/emakefun/pxt-joystickbit>**

#### **[淘宝链接](https://item.taobao.com/item.htm?spm=a1z10.5-c.w4002-21556097795.24.720864faiazDSE&id=650591965479)**

![image](picture/joystickbit.jpg)

## 特点

- 左右双摇杆

- 手柄扩展Micro:Bit A，B按键

- 左右可独立编程按键

- 板子蜂鸣器和震动电机

- 2节7号电池供电

- 1个PH2.0-4Pin i2c接口

## 图像化编程块说明

- 《游戏手柄摇杆获取 左/右侧 x/y轴 的值》:该模块用于获取手柄左或者右摇杆x轴或者y轴方向的坐标值，其获取的值为数值类型，其值可以通过‘显示数字’模块显示在Micro:Bit板上
- 《游戏手柄震动频率()》 :该模块用于调试游戏手柄上震动电机的震动频率，其值为0时震动电机停止震动。
- 《按键 L/R/左摇杆按键/右摇杆按键 是否是 按下/释放 状态》 :该模块用于判断游戏手柄左右按键和摇杆中心按键是否按下或者释放，是返回ture,否返回false，作用于判断模块（如果...则执行...）
- 《游戏手柄按键 L/R/左摇杆按键/右摇杆按键 是否被按下》 :该模块用于判断手柄上按钮是否按下，是返回ture,否返回false。
- 《游戏手柄按键 L/R/左摇杆按键/右摇杆按键 是否被释放》 :该模块用于判断手柄按键是否未按住，是返回ture,否返回false。

   ![image](picture/1.jpg)

- 下面的组合模块的含义:
  - 模块代码成功下载到Micro:Bit上后，Micro:Bit的LED显示屏显示数字爱心，之后持续获取并显示左侧摇杆的x轴坐标。当按下L键时，振动电机以500HZ的频率开始震动，当释放按钮L时，振动电机停止震动。当按下R键时，板载蜂鸣器以500HZ的频率开始工作，当释放按钮R时，板载蜂鸣器停止工作。

   ![image](picture/000.jpg)

### 摇杆图形化块

- 获取游戏手柄摇杆x/y轴值（获取左/右侧x/y轴的值并将其数值通过LED显示屏显示出来）

   ![image](picture/11.jpg)

   ![image](picture/12.jpg)

### 独立按键编程图形块

- 按键 L/R/左摇杆按键/右摇杆按键 是否是 按下/释放 状态
- 下面模块是对按键状态进行一个判断：当你按了按键L，则显示字符串"Hello!"

   ![image](picture/21.jpg)

   ![image](picture/22.jpg)

- 同理，下面两个模块也是对按键的按下或者未按进行一个判断，为真则显示字符串"Hello!"

   ![image](picture/23.jpg)

   ![image](picture/24.jpg)

### 震动电机编程图形块

- 游戏手柄震动频率模块可以调试震动电机的震动频率

   ![image](picture/31.jpg)

- 配合按键使用: 当你按下L键时，震动电机开始工作，频率为137HZ。当你释放按键L时，震动电机停止工作。

   ![image](picture/32.jpg)

### 板载蜂鸣器编程图形块

- 游戏手柄板载蜂鸣器振动频率模块可以调试板载蜂鸣器的振动频率

   ![image](picture/41.jpg)

- 配合按键使用: 当你按下L键时，板载蜂鸣器开始工作，频率为516HZ，当你释放按键L时，板载蜂鸣器频率为0停止工作。

  ![image](picture/43.jpg)

### micro:bit MicroPython扩展库

[点击下载micro:bit MicroPython扩展库以及示例程序](zh-cn/microbit/joystickbit/microbit_joystick_controller.zip ':ignore')

### ESP32 MicroPython扩展库

[点击下载ESP32 MicroPython扩展库以及示例程序](zh-cn/microbit/joystickbit/esp32_joystick_controller.zip ':ignore')

### MicroPython API详细说明

#### 1.read_joystick_left_x(self)

这是JoystickController类下的成员函数，用于接收手柄左摇杆x轴的模拟值。

```python
read_joystick_left_x(self)

参数:无
返回值：返回0~255的模拟值

```

#### 2.read_joystick_left_y(self)

这是JoystickController类下的成员函数，用于接收手柄左摇杆y轴的模拟值。

```python
read_joystick_left_y(self)

参数:无
返回值：返回0~255的模拟值

```

#### 3.read_joystick_right_x(self)

这是JoystickController类下的成员函数，用于接收手柄右摇杆x轴的模拟值。

```python
read_joystick_right_x(self)

参数:无
返回值：返回0~255的模拟值

```

#### 4.read_joystick_right_y(self)

这是JoystickController类下的成员函数，用于接收手柄右摇杆y轴的模拟值。

```python
read_joystick_right_y(self)

参数:无
返回值：返回0~255的模拟值

```

#### 5.read_button_status(self, button)

这是JoystickController类下的成员函数，用于接收手柄按钮的按下状态。

```python
read_button_status(self, button)

参数:
button: 按钮类型，取值范围为BUTTON_LEFT_REG、BUTTON_RIGHT_REG、JOYSTICK_BUTTON_RIGHT、JOYSTICK_BUTTON_LEFT，分别表示左侧按键、右侧按键、左摇杆按键、右摇杆按键。
返回值：返回Button_Status类成员变量，表示按钮的按下状态，取值范围为JOYSTICK_PRESS_DOWN、JOYSTICK_PRESS_UP、JOYSTICK_SINGLE_CLICK、JOYSTICK_DOUBLE_CLICK、JOYSTICK_LONG_PRESS。分别表示按下、释放、单击、双击、长按。

```
