
# MotorDriverBoard V5.2

### [淘宝购买链接](https://item.taobao.com/item.htm?spm=a1z10.1-c.w4004-22376313182.2.6330bc63YWvWxB&id=591988262536)

MotorDriverBoard是由 [深圳市易创空间科技有限公司](https://www.emakefun.com/)，专门针对Arduino Uno(兼容Mega2560)机器人，电机驱动，多路舵机控制而研发的一款多功能电机驱动扩展板。本驱动板采用I2C方式控制<a href="zh-cn/arduino_products/uno/motor_driver_board/PCA9685.pdf" target="_blank">PCA9685</a>(16路PWM输出芯片)。所以本驱动板电机或者舵机和arduino主板IO口不存在对应关系，是通过I2C扩展PWM控制，详情请见<a href="zh-cn/arduino_products/uno/motor_driver_board/MotorDriverBoard_V5.2.pdf" target="_blank">**驱动板原理图**</a>
。

**MotorDriverBoard for Arduino  Uno(Arduino Mega2560)**

![MotorDriverBoard_0](picture/MotorDriverBoard_show0.jpg)

### 快速链接

[**常见问题**](#faq)

[**Arduino ide库文件下载**](https://github.com/emakefun/MotorDriverBoard/releases/download/v1.0/MotorDriverBoard.zip)

[**Mixly库下载**](https://github.com/emakefun/MotorDriverBoard/releases/download/v1.0/MotorDriverBoard_Mixly.zip)

[**Mblock5库下载**](https://github.com/emakefun/MotorDriverBoard/releases/download/v1.0/MotorDriverBoard_Mblock5.zip)

[**Mind+库下载**](https://github.com/emakefun/MotorDriverBoard/releases/download/v1.0/MotorDriverBoard_mindplus-V1.0.0.zip)

[MagicBlock下载(敬请期待)]()

## 特点

- 支持4路直流电机，最大驱动电流3A
- 支持驱动8路舵机，带自恢复保险丝，防止舵机堵转
- 支持驱动2路4线步进电机
- 支持4路编码电机
- 板载无源蜂鸣器(**A0**)
- 板载1个RGB全彩灯(**A1**)
- 1个 i2c接口 、1个PS2X接口、1个Uart(蓝牙/wifi模块)接口 、1个NRF24L01无线模块接口
- 1个超声波模块接口
- 舵机电源可切换到外部供电
- 软件支持Arduino IDE，Mixly，Mind+，Mblock5，MagicBlock(基于Scratch3.0可定制)

![MotorDriverBoard_1](picture/MotorDriverBoard_show1.png)

## 硬件功能介绍

### 正面

![hardware_introduction](picture/hardwareIntroduction.png)

### 供电说明

为了将本驱动板做到使用更加灵活，适应不同电机，舵机驱动要求，以及整个板子能够稳定运行

我们设计了如下几种供电方案，**注意驱动板必须通过锂电池或者8.4V 3A以上的UPS电源供电，不能只Uno主板usb供电或者干电池供电**

#### 1、只通过Uno的DC（7~12V）头单一电源给Uno主板，驱动板，舵机同时供电

  应用场景:

  a、**驱动9V以下得直流电机比如TT马达积木电机灯，外加sg90/mg90这种舵机**；

  b、**PS2控制9V~12V的电机时，为了确保PS2不断连，建议使用航模电池或者大电流21700锂电池，两节18650供电不稳定**。

  c、电源切换开关达到**IN(DC)**位置，跳线帽**短接5V位置**

![MotorDriverBoard_dc_power_supply](picture/dc_power_supply.png)

#### 2、只通过接线柱供单一电源给驱动板，Uno主板和舵机供电。将驱动板的5V电源输出到Uno主板

  适应场景

  a、驱动4路12V以上的电机时比如370电机，520电机，此时舵机为sg90/mg90这种小功率舵机;

  b、供电超过Uno DC头12V电压，所以我们需要用接线柱供电，供电范围6~25V;

  c、电源切换开关打到**EX**，跳线帽短接到**5V位置**，需要短接背面**R24电阻位**。

![MotorDriverBoard_terminal_power_supply](picture/terminal_power_supply.png)

#### 3、Uno主板通过DC头供电，舵机通过接线柱独立供电

  a、外部使用MG995/MG996/DS3235/DS3238等大力矩舵机时，数量超过2个时（需要根据实际情况测试），我们需要给舵机独立供电

  b、舵机供电电压电流根据舵机参数提供

  c、电源切换开关达到**IN(DC)**位置，跳线帽**短接EX位置**

![MotorDriverBoard_terminal_power_supply](picture/terminal_power_servo.png)

## 驱动库使用

[**下载Arduino库**](https://github.com/emakefun/MotorDriverBoard/releases/download/v1.0/MotorDriverBoard.zip) ，打开IDE，点击左上角项目-->包含库-->添加.ZIP库，选中你所下载的压缩包，打开。

![1716167973006](picture/1716167973006.png)

![1716168840943](picture/1716168840943.png)

然后打开IDE，通过点击文件-->示例-->Emakefun_MotorDriverBoard，打开示例程序。![examples](picture/examples.png)

示例程序解析。

![1716169252803](picture/1716169252803.png)

![1716169302656](picture/1716169302656.png)

![1716169352693](picture/1716169352693.png)

## 基础示例程序

<a href="zh-cn/arduino_products/uno/motor_driver_board_encoder_motor/gpio_test.zip" download>**Gpio_test**</a>

这个示例程序为控制Uno主板的IO口输出高低电平, 控制PCA9685输出口当作普通IO口输出高低电平

```c++
Emakefun_MotorDriver gpio = Emakefun_MotorDriver(0x60);

gpio.begin(1000);      /*初始化io口的输出频率为1KHz*/
gpio.setPin(S1, HIGH); /*引脚S1(S1~S8)输出高电平*/
gpio.setPin(S1, LOW);  /*引脚S1(S1~S8)输出低电平*/
```

<a href="zh-cn/arduino_products/uno/motor_driver_board_encoder_motor/pwm_test.zip" download>**PWM_test**</a> 这个示例程序为控制PCA9685输出口输出PWM波形

```c++
Emakefun_MotorDriver pwm = Emakefun_MotorDriver(0x60);
pwm.begin(1500);      /*初始化io口的输出频率为1500Hz*/
pwm.setPin(S1, 1024); /*引脚1输出占空比为 1024/4096 的PWM波（0~4096）*/
```

<a href="zh-cn/arduino_products/uno/motor_driver_board_encoder_motor/ps2_test.zip" download>**PS2_test**</a>

PS2手柄测试程序

| PS2手柄引脚 | Arduino引脚 |
|---------|-----------|
| DAT     | D12       |
| CMD     | D11       |
| SEL/ATT | D10       |
| CLK     | D13       |

PS2安装请勿接反，左边是正确安装，右边为PS2接收器接反

![Ps2](picture/Ps2.png)

## 电机测试示例

### <a href="zh-cn/arduino_products/uno/motor_driver_board_encoder_motor/dc.zip" download>**DC**</a>

四路直流电机测试程序

```c++
Emakefun_MotorDriver m_motor = Emakefun_MotorDriver(0x60);
Emakefun_DCMotor *dc_motor_1 = m_motor.getMotor(M1);

void setup() {
  Serial.begin(9600);
  m_motor.begin(50); /*初始化io口的输出频率为50Hz*/
}

void loop() {
  // 前进
  dc_motor_1->setSpeed(200); /*设置速度为200 范围0~255 */
  dc_motor_1->run(FORWARD);  // 总共FORWARD前进，BACKWARD后退，BRAKE刹车 RELEASE释放四个状态
}
```

**接线图**![MotorDriverBoard_dc](picture/dc.png)

#### <a href="zh-cn/arduino_products/uno/motor_driver_board_encoder_motor/servo.zip" download>**Servo**</a>八路舵机测试程序

```c++
Emakefun_MotorDriver m_motor_driver = Emakefun_MotorDriver(0x60);
Emakefun_Servo *m_servo_1 = m_motor_driver.getServo(1);
m_motor_driver.begin(50);      /*初始化io口的输出频率为50Hz*/
m_servo_1->writeServo(90, 10); /*设置舵机角度为0~180，速度为0~100*/
```

**接线图**![MotorDriverBoard_servo](picture/servo.png)

#### <a href="zh-cn/arduino_products/uno/motor_driver_board_encoder_motor/stepper.zip" download>**Stepper**</a>步进电机测试程序

```c++
Emakefun_MotorDriver m_motor_driver = Emakefun_MotorDriver(0x60);
Emakefun_StepperMotor *stepper_motor_1 = m_motor_driver.getStepper(1, 200);
/*初始化步进电机1，42步进电机走一步是1.8度，所以一圈的步数为200*/

m_motor_driver.begin(1600); /*设置频率为最大 1600*/

stepper_motor_1->setSpeed(400); /*设置步进电机每分钟转的圈数为400圈, 速度越快力矩越小，这个速度不能太低，否则会抖动严重*/

stepper_motor_1->step(200, FORWARD, SINGLE);
/*驱动步进电机按 SINGLE(单步)的方式，FORWARD（前进）200步。*/

/*步进电机的驱动方式 全步DOUBLE、单步SINGLE、1/2步进INTERLEAVE这三种驱动方式（步进电机的驱动原理请查阅相关资料）*/
```

**接线图**

**不同步进电机的参数接线不一定一样，请一定要先确定步进电机每根线的颜色和对应A+ A- B+ B-相位（或者是A B C D）关系**

下图仅供接线参考

![MotorDriverBoard_stepper](picture/stepper.png)

#### <a href="zh-cn/arduino_products/uno/motor_driver_board_encoder_motor/encoder.zip" download>**Encoder**</a>四路编码电机测试程序

编码器关键参数如下：

| 类型     | 参数                                                                                                 |
|--------|----------------------------------------------------------------------------------------------------|
| 转速     | 电压6V  空载电流70mA  空载轮轴转速90RPM<br />电压9V  空载电流150mA  空载轮轴转速140RPM<br />电压12V  空载电流190mA  空载轮轴转速190RPM |
| 输出方波类型 | AB相方波                                                                                              |
| 基础脉冲   | 12PPR(电机转动一圈输出12个脉冲)                                                                               |
| 减速比    | 1:90(转轴转动一圈电机转动90圈)                                                                                |

通过上面参数可知，轮子旋转一圈，总共需要计数90x12=1080个脉冲

```c++
m_motor_driver.begin();     /*初始化io口的输出频率默认为最大*/
encode_motor_1->setSpeed(100);   /*设置速度为100*/
encode_motor_1->run(BACKWARD);
/*控制电机运行状态（FORWARD(前)、BACKWARD(后)、BRAKE(停止)）*/
```

测试四个编码电机都都能够旋转，打开串口我们要能打印出Encoder1Pulse，Encoder2Pulse，Encoder3Pulse，Encoder4Pulse四个脉冲值如下，证明编码电机都是正常工作的。

```c++
start
Encoder1Pulse:1
Encoder2Pulse:1
Encoder3Pulse:1
Encoder4Pulse:1
Encoder1Pulse:2
Encoder2Pulse:2
Encoder1Pulse:3
```

<a href="zh-cn/arduino_products/uno/motor_driver_board_encoder_motor/encoder_pid.zip" download>**Encoder_pid**</a>编码电机PID控制电机速度

```c++
PID my_pid(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
```

- Input：PID的输入(编码电机速度)
- Output：PID的输出(编码电机速度)
- Setpoint：PID的目标值
- Kp：PID的比例系数
- Ki：PID的积分系数
- Kd：PID的微分系数
- DIRECT：方向参数，编码电机正转
- REVERSE：方向参数，编码电机反转

```c++
my_pid.SetSampleTime(100);    /*设置PID采样时间为100ms*/
my_pid.SetMode(AUTOMATIC);     /*设置PID模式为AUTOMATIC*/
```

```c++
Emakefun_EncoderMotor *encode_motor_1 = m_motor_driver.getEncoderMotor(1); /*获取编码电机1*/
m_motor_driver.begin();                                                   /*初始化io口的输出频率默认为最大*/
encode_motor_1->init(encoder1);                                          /*初始化encoder1为编码电机1的回调函数(计算编码盘的脉冲)*/
MsTimer2::set(100, EncoderSpeed);                                       /*定时器2定时获取编码电机速度*/
MsTimer2::start();                                                      /*启动定时器2*/
```

**注意**

由于我们测试使用的是8.4V锂电池，大部分电池电压在7\~8V之间，我们实际测速只有100RPM，采样时间为100ms，那么计算出每个周采样周期的最大采样脉冲数为100x90x12x(0.1s)/60=180Pluse/samptime。被控制量的范围为0\~255，得出采样比例系数为ratio = 255/180 = 1.5。这个比例参数是可以自己定义的，你们可以根据自己的习惯来定义，我这个测试程序为了方便理解，把目标值和PWM控制量0\~255关联起来，即控制目标范围也为0\~255。

**第一步：纯比例作用整定**

由于是第一次进行PID参数整定，电机速度整定到100为目标，在程序中输入设定值。先把系统设定为纯比例作用，即只有比例增益Kp不为0，积分增益Ki和微分增益Kd都暂时设定为0。因为是这个小车第一次整定参数，也不知道什么比例增益比较好。比例作用从弱到强调节，随便写了个自认为不大的值3，**打开工具-->串口绘图器**。运行结果令我大吃一惊，电机以一定的周期在转和不转之间震荡。根据现象得知，肯定是比例作用已经非常大了，因此赶紧将比例增益调整为2，小车的电机不再出现剧烈的“抽搐”，开始以一种比较缓慢的姿态转动，但通过观察输出波形，还是存在较小的波动，并且经过1，2分钟之后，还是会有大幅度震荡。但与之前较大比例作用下的震荡相比，显然“温柔”多了。于是继续降低比例作用，直至Kp = 1时，输出波形已经相较其他参数下稳定很多了，如下图：

![pid](picture/pid_p.png)

**第二步：比例积分作用**

由上图可看出，一个适合的比例作用可以使系统趋于稳定，但却无法消除静态偏差，因此需要引入积分作用，其最大的好处就是可以消除静态偏差。笔者继续采用由小逐渐加大积分增益的方式。当设定Ki = 5时，由图可见

![pid](picture/pid_i.png)

静态偏差逐渐减小，输出的速度越来越接近设定的速度100的目标，不过调节速度太慢，还是不能满足需求。
于是还需要继续加积分作用，当Ki = 6时，可以看出，系统反应速度已经很快，可以在0.1秒内

**接线图**

编码电机我们使用的是6pin的GH1.25转PH2.0线材接线如下：

![encoder](picture/encoder.png)

## 综合应用

<a href="zh-cn/arduino_products/uno/motor_driver_board_encoder_motor/ps2_control_4wd.zip" download>PS2控制四驱小车</a>

<a href="zh-cn/arduino_products/uno/motor_driver_board_encoder_motor/ps2_control_mecanum_wheel_car.zip" download>PS2控制四驱麦克纳姆轮小车</a>

<a href="zh-cn/arduino_products/uno/motor_driver_board_encoder_motor/ps2_control_4wd_with_robotic_arm.zip" download>PS2控制四驱小车加机械臂</a>

<a href="zh-cn/arduino_products/uno/motor_driver_board_encoder_motor/bluetooth_wifi_control.zip" download>蓝牙(WIFI)控制四驱小车</a>

蓝牙或者wifi模块请使用数据透传模块，连接到arduino的硬件串口引脚上（0-RXD，1-TXD）

## 图像化编程块说明

### MotorDriverBoard 编程图形块

#### Mixly库安装(以Mixly2.0为例，默认主板为Arduino UNO)

1. **Mixly云端安装(只适合mixly2.0)**

   第一步

   ![mixly guanliku](mixly/mixly_guanliku.png)

   第二步

   ![mixly kuanzhuang](mixly/mixly_kuanzhuang.png)

   第三步

   ![install success](mixly/install_success.png)

   第四步 当看到一下界面，就证明安装成功。

   ![mixly success](mixly/mixly_success.png)

2. **本地安装**

   2.1 下载Mixly扩展包，解压；

   2.2 导入本地库；步骤如下：

   步骤一

   ![mixly guanliku](mixly/mixly_guanliku.png)

   步骤二

   ![local install](mixly/local_install.png)

   步骤三

   ![select xml](picture/mixly/select xml.png)

   当看到一下界面，就证明安装成功。

   ![mixly success](mixly/mixly_success.png)

#### Mixly块表述

1.[点击下载Mixly扩展包和案例](https://github.com/emakefun/MotorDriverBoard/releases/download/v1.0/MotorDriverBoard_Mixly.zip)

![download](mixly/download.png)

2.积木描述

| 序号  | 积木                                                       | 说明                                                       |
|-----|:---------------------------------------------------------|----------------------------------------------------------|
| 1   | ![mixly_init](mixly/mixly_init.png)     | 初始化积木，使用所有积木的前提                                          |
| 2   | ![set_freq](mixly/set_freq.png)         | 设置IO口输出频率，输出范围1-1600HZ                                   |
| 3   | ![set_mode](mixly/set_mode.png)         | 控制IO口输出高低电平，IO口有八个，分别为S1-S8                              |
| 4   | ![pwm](mixly/pwm.png)                   | 控制IO口输出PWM，输出范围0-4096                                    |
| 5   | ![dc_init](mixly/dc_init.png)           | 初始化直流电机接口，电机包含M1\M2\M3\M4四个                              |
| 6   | ![run_dc](mixly/run_dc.png)             | 设置直流电机的转动方向和速度，方向分为正转、反转、刹车、释放，速度范围为0-255                |
| 7   | ![stop_dc](mixly/stop_dc.png)           | 停止直流电机                                                   |
| 8   | ![init_encoder](mixly/init_encoder.png) | 初始化编码电机，编码电机有四个，分为Encoder1\Encoder2\Encoder3\Encoder4    |
| 9   | ![run_encoder](mixly/run_encoder.png)   | 设置编码电机运动方向和速度，方向分为正/反转，速度范围为0-255                        |
| 10  | ![stop_encoder](mixly/stop_encoder.png) | 停止编码电机                                                   |
| 11  | ![stepper_init](mixly/stepper_init.png) | 初始化步进电机，不同的步进电机转一圈的步数是不同的，并设置每分钟需要转的圈数，即旋转速度             |
| 12  | ![run_stepper](mixly/run_stepper.png)   | 设置步进电机运动方向、驱动方式和运动步数；方向分为正、反转，驱动方式分为全步、半步和单步；运动步数即需要运动步数 |
| 13  | ![stop_stepper](mixly/stop_stepper.png) | 停止步进电机                                                   |
| 14  | ![servo_init](mixly/servo_init.png)     | 初始化舵机                                                    |
| 15  | ![run_servo](mixly/run_servo.png)       | 设置选择的舵机的旋转角度和旋转的速度，速度范围为0-100                            |

<font color="red" size="5">**注:**</font> PS2、RGB灯、蜂鸣器等模块请使用Mixly自带的模块。

#### Mblock5

1. Mblock5库安装

   1.1 下载[Mblock5库](https://github.com/emakefun/MotorDriverBoard/releases/download/v1.0/MotorDriverBoard_Mblock5.zip)，解压

   1.2  将解压后的ext_motordriverboard.mext扩展包拖到Mblock5软件里面，能看到以下界面，证明安装成功。

   ![mblock install success](picture/mblock/mblock install success.png)

2. [Mblock5库和案例下载](https://github.com/emakefun/MotorDriverBoard/releases/download/v1.0/MotorDriverBoard_Mblock5.zip)

![download](mblock/download.png)

3. 积木描述

| 序号  | 积木                                                        | 说明                                                       |
|-----|:----------------------------------------------------------|----------------------------------------------------------|
| 1   | ![mixly_init](mblock/init.png)           | 初始化积木，使用所有积木的前提                                          |
| 2   | ![set_freq](mblock/set_freq.png)         | 设置IO口输出频率，输出范围1-1600HZ                                   |
| 3   | ![set_mode](mblock/set_mode.png)         | 控制IO口输出高低电平，IO口有八个，分别为S1-S8                              |
| 4   | ![pwm](mblock/pwm.png)                   | 控制IO口输出PWM，输出范围0-4096                                    |
| 5   | ![dc_init](mblock/dc_init.png)           | 初始化直流电机接口，电机包含M1\M2\M3\M4四个                              |
| 6   | ![run_dc](mblock/run_dc.png)             | 设置直流电机的转动方向和速度，方向分为正转、反转、刹车、释放，速度范围为0-255                |
| 7   | ![stop_dc](mblock/stop_dc.png)           | 停止直流电机                                                   |
| 8   | ![init_encoder](mblock/init_encoder.png) | 初始化编码电机，编码电机有四个，分为Encoder1\Encoder2\Encoder3\Encoder4    |
| 9   | ![run_encoder](mblock/run_encoder.png)   | 设置编码电机运动方向和速度，方向分为正/反转，速度范围为0-255                        |
| 10  | ![stop_encoder](mblock/stop_encoder.png) | 停止编码电机                                                   |
| 11  | ![stepper](mblock/stepper.png)           | 初始化步进电机，不同的步进电机转一圈的步数是不同的，并设置每分钟需要转的圈数，即旋转速度             |
| 12  | ![run_stepper](mblock/run_stepper.png)   | 设置步进电机运动方向、驱动方式和运动步数；方向分为正、反转，驱动方式分为全步、半步和单步；运动步数即需要运动步数 |
| 13  | ![stop_stepper](mblock/stop_stepper.png) | 停止步进电机                                                   |
| 14  | ![servo_init](mblock/servo_init.png)     | 初始化舵机                                                    |
| 15  | ![run_servo](mblock/run_servo    | 设置选择的舵机的旋转角度和旋转的速度，速度范围为0-100                            |

<font color="red" size="5">**注:**</font> PS2、RGB灯、蜂鸣器等模块可以去Mblock扩展库找对应的扩展，这里不做解释。

#### Mind+

1. 下载[Mind+库扩展包](https://github.com/emakefun/MotorDriverBoard/releases/download/v1.0/MotorDriverBoard_mindplus-V1.0.0.zip)
    ![extention-pkg.png](mind+/extention-pkg.png)
2. 将解压后的emakefun-motordriverboard-thirdex-V0.0.3.mpext扩展包导入到Mind+软件里面  
    第一步：点击扩展
    ![user-lib-step01.png](mind+/user-lib-step01.png)
    第二步：选择主控板
    ![user-lib-step02.png](mind+/user-lib-step02.png)
    第三步：导入用户库
    ![user-lib-step03.png](mind+/user-lib-step03.png)
    第四步：加载并返回
    ![user-lib-step04.png](mind+/user-lib-step04.png)
    第五步：查看并使用用户库，看到如下界面，说明已成功导入电机驱动板扩展包。
    ![user-lib-step05.png](mind+/user-lib-step05.png)

3. 积木描述

| 序号  | 积木                                                       | 说明                                                       |
|-----|:---------------------------------------------------------|----------------------------------------------------------|
| 1   | ![init](mind+/init.png)                 | 初始化积木，使用所有积木的前提                                          |
| 2   | ![set_freq](mind+/set_freq.png)         | 设置IO口输出频率，输出范围1-1600HZ                                   |
| 3   | ![set_mode](mind+/set_mode.png)         | 控制IO口输出高低电平，IO口有八个，分别为S1-S8                              |
| 4   | ![pwm](mind+/pwm.png)                   | 控制IO口输出PWM，输出范围0-4096                                    |
| 5   | ![dc_init](mind+/dc_init.png)           | 初始化直流电机接口，电机包含M1\M2\M3\M4四个                              |
| 6   | ![run_dc](mind+/run_dc.png)             | 设置直流电机的转动方向和速度，方向分为正转、反转、刹车、释放，速度范围为0-255                |
| 7   | ![stop_dc](mind+/stop_dc.png)           | 停止直流电机                                                   |
| 8   | ![init_encoder](mind+/init_encoder.png) | 初始化编码电机，编码电机有四个，分为Encoder1\Encoder2\Encoder3\Encoder4    |
| 9   | ![run_encoder](mind+/run_encoder.png)   | 设置编码电机运动方向和速度，方向分为正/反转，速度范围为0-255                        |
| 10  | ![stop_encoder](mind+/stop_encoder.png) | 停止编码电机                                                   |
| 11  | ![stepper](mind+/stepper.png)           | 初始化步进电机，不同的步进电机转一圈的步数是不同的，并设置每分钟需要转的圈数，即旋转速度             |
| 12  | ![run_stepper](mind+/run_stepper.png)   | 设置步进电机运动方向、驱动方式和运动步数；方向分为正、反转，驱动方式分为全步、半步和单步；运动步数即需要运动步数 |
| 13  | ![stop_stepper](mind+/stop_stepper.png) | 停止步进电机                                                   |
| 14  | ![servo_init](mind+/servo_init.png)     | 初始化舵机                                                    |
| 15  | ![readDegrees](mind+/readDegrees.png)   | 读取当前舵机角度                                                 |
| 16  | ![run_servo](mind+/run_servo.png)       | 设置选择的舵机的旋转角度和旋转的速度，速度范围为0-100                            |
备注：PS2手柄，可在扩展->通信模块中找到，如下图
![mindplus-ps2.png](mind+/mindplus-ps2.png)

#### MagicBlock

敬请期待

## MotorDriverBoard编码电机库（高阶版）

我们还提供了更高阶的库，可以在MotorDriverBoard上使用PID闭环功能实现**编码电机**的**速度**控制和**位置**控制。详情请[点击此处查看](zh-cn/arduino_products/uno/motor_driver_board_encoder_motor/README.md)。

## FAQ

#### Q：驱动板arduino IO对应关系?

##### A ：本驱动板采用I2C方式控制<a href="zh-cn/arduino_products/uno/motor_driver_board/PCA9685.pdf" target="_blank">PCA9685</a>(16路PWM输出芯片)。所以本驱动板电机或者舵机和arduino主板IO口不存在对应关系，是通过I2C扩展PWM控制

#### Q：驱动板该如何接电?

##### A ：请先判断手里是用什么电源，驱动什么样的电机，需要多大电压和电流，还有舵机，然后根据实际情况采用对应的电池，不建议使用干电池供电

#### Q：驱动板驱动不了电机?

##### A ：请先判断驱动板是否有供电，并且开关有打开，只通过usb口供电是驱动不了电机的，另外主板还得烧录对应的驱动程序

#### Q：PS2遥控不了驱动板?

##### A ：在使用驱动板的时候，如果是新手用户，请一定要一步步来熟悉使用，不要一上来就全部功能一起使用，然后问的问题很大。针对这个问题需要做如下三个测试才行

a、驱动板是否使用7V以上锂电池供电且正常，板子上灯是否亮
b、下载直流电机驱动测试程序**确保要上传成功**，电机接线正确，来确定板子驱动正常
c、测试PS2接收测试程序，来证明PS2遥控器是好的
d、前面正确后下载PS2控制四驱小车程序，并按按键控制电机

#### Q：驱动板是否有原理图?

##### A ：有，点击这里<a href="zh-cn/arduino_products/uno/motor_driver_board/MotorDriverBoard_V5.2.pdf" target="_blank">**驱动板原理图**</a>

#### Q：如何分析并判断驱动板是否损坏?

##### A ：先外观判断是否有芯片烧黑，冒烟，等情况。如果已经很熟练操作此板子，如果程序下载正确，供电也正确，板子就是驱动不了电机，那么有三种情况

1、电源切换开关接触不良，用万用表点一下确定，检测是否有5V电源输出

2、4个直流电机里面其中一部分转，一部分不转，有可能对应的驱动芯片烧坏

3、四个电机，舵机都不转，使用I2C 扫描程序测试，看是否能扫描到PCA968A的I2C地址，如果扫描不到PCA8685损坏

## 联系我们

**技术 + 合作(WX号)：nulllab_leishen*
