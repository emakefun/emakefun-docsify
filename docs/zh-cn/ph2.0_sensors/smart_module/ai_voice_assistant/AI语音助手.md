# AI 语音助手
# 实物图
![AI语音助手实物图](images/ai_voice_assistant.png)

## 什么是 AI 语音助手？

AI 语音助手是一款基于虾哥开源项目**小智 AI** 进行二次开发的智能语音助手，它集成了先进的语音识别和 AI 对话能力。在具备自然语音交互功能的基础上，AI 语音助手新增加了**外设控制指令串口输出**功能，构建了一套完整的 **"语音 → 指令 → 硬件"** 控制链路。

当用户通过自然语言发出设备控制指令（如"请打开灯""调节电机速度"）时，AI 语音助手会通过配置的**知识库引擎**智能匹配预设的"语音指令 - 串口指令"映射关系，并通过指定串口输出对应的标准化控制指令（如 `turn on led`），供外部设备（如 Arduino）接收并执行。

用户只需通过简单配置，自定义"语音指令"与"串口指令"的映射关系，即可快速实现语音控制 LED、电机、舵机等多种外设功能，大幅降低智能语音交互的开发门槛。


> **📦 源码仓库**：本产品基于虾哥开源项目小智 AI 进行二次开发，相关源码可访问：https://github.com/nulllaborg/xiaozhi_ai_vox3_ai_smart


## AI-Vox3 主板详情

AI 语音助手主板基于 **ESP32-S3** 芯片，板载麦克风、扬声器、显示屏、按键等外设，并预留一个 **PH2.0 串口**用于输出外设控制指令。

> **📖 主板详情**：https://dcnmu33qx4fc.feishu.cn/docx/VXHzdBYH0ohpNAxw2ifc3P2InBe


## 编译教程
### 一.固件编译教程
固件编译方法查看小智ai官方文档：https://my.feishu.cn/wiki/Zpz4wXBtdimBrLk25WdcXzxcnNS

本教程提供AI-Vox3 主板的编译固件：

### 二.源码编译教程
> 如果你有更改配置的需要，推荐使用源码编译，源码编译需要你有一定的编程基础。以下的两种源码编译方法你都可以使用。
### 编译环境安装

### 1.1 windows 环境下载安装 ESP-IDF 环境，教程参考小智官方文档，要求下载IDF6版本。
> **📖 编译教程**：https://icnynnzcwou8.feishu.cn/wiki/JEYDwTTALi5s2zkGlFGcDiRknXf

### 1.2 下载完 ESP-IDF 环境后，打开桌面上的 ESP-IDF ，进入以下界面。
   
|          IDF6 环境           | IDF6 PowerShell                                |
| :--------------------------: | :--------------------------------------------- |
| ![IDF6环境](images/IDF6.png) | ![IDF6-powershell](images/IDF6_powershell.png) |

### 1.3 访问https://github.com/nulllaborg/xiaozhi_ai_vox3_ai_smart 项目目录，git clone最新版本的源码，在cmd中输入git clone命令，而后在ESP-IDF中输入命令 进入项目目录。
> cd 解压的文件目录 
 
|              clone源码              | 克隆源码                  | 进入目录                             |
| :---------------------------------: | :------------------------ | :----------------------------------- |
| ![github](images/github-aivox3.png) | ![](images/git_clone.png) | ![进入目录](images/ai-vox3-IDF6.png) |

##  idf.py build编译方法
### 2.1 设置芯片类型
默认的编译芯片是ESP32的，所以一定要输入以下命令把芯片设置为S3
>  idf.py set-target esp32s3

![设置芯片类型](images/set-target.png)

### 2.2 更换编译板子类型
默认编译出的固件是面包板的，我们需要更换为NullLab AI Vox3 V3主板,输入 idf.py menuconfig，进入Xiaozhi Assistant选项，选Target Board 进去选择NullLab AI Vox3 V3主板,按键盘的‘S’键保存 然后Esc退出menuconfig.

 
|               编译选项               | assistant                                  |选择板子                                  |
| :----------------------------------: | :----------------------------------------- |:----------------------------------------- |
| ![menuconfig](images/menuconfig.png) | ![assistant](images/xiaozhi-assistant.png) | ![assistant](images/targetboard.png) |! |
### 2.3 开始编译
输入以下命令开始编译
> idf.py build

注意编译时，要先使主板进入下载模式
> 每次给AI-VOX3 烧录程序的时候都需要让AI-VOX3进入到下载模式
> 
> 进入下载模式的操作步骤:
>  - 连接Type-C线至电脑 →按住Boot按键 → 短按一次PWR按键 → 继续按住Boot键约1秒后松开→ 板子自动进入下载模式。
> 
>按键操作时机：确保在开机或复位前提前按住Boot键，并在开机/复位后保持1秒再松开。


## 编译脚本方法（推荐）
> 推荐使用编译脚本进行编译：python ./scripts/build.py nulllab-ai-vox-v3，省去切换开发板配置。 案例所需要的配置都写在了 config.json 文件中，如果你需要更改配置，直接在 config.json 文件中修改即可。



### 3.1.输入编译脚本
> 安装好编译环境后，进入项目，输入以下命令编译固件即可。

> python ./scripts/build.py nulllab-ai-vox-v3、

等待编译完成即可

## 网络配置

### 1.固件烧录完成后，按下 AI 语音助手的 **Power** 按键，进入配网模式。

![进入配网](images/in_connect_wifi.jpg)

### 2. 打开手机 WiFi，连接 AI 语音助手发出的对应 WiFi, 在配网页面配置要连接的 WiFi 名称和密码

 
  |           配置WIFI           | 连接成功                    |
  | :--------------------------: | :-------------------------- |
  | ![](images/connect_wifi.png) | ![](images/config_wifi.png) |


> **🔁 重新配网说明**：将 AI 语音助手重新上电 / 重启，在连接 WiFi 闪烁蓝灯时（即还未连上 WiFi 时），直接按下 **Boot** 按钮然后松开，听到提示音后重新进入 WiFi 配网模式。


## 设备激活

网络配置好后，登录小智平台 **https://xiaozhi.me/** 进行设备激活。

### 1. 点击进入【控制台】页面
### 2. 进入智能体控制页面，点击页面上的【添加设备】按钮
### 3. 在弹窗中输入播报的 **6 位数验证码**，点击确定即可激活   
### 4. 添加设备后，按下 AI 语音助手的 **Power** 按键，进入语音交互模式。 

|                 添加设备                  | 输入验证码                           |
| :---------------------------------------: | :----------------------------------- |
| ![添加设备](images/click_add_devices.png) | ![输入验证码](images/input_code.png) |



## 修改唤醒词

打开桌面上的 ESP-IDF，输入 idf.py menuconfig，进入 Xiaozhi Assistant 配置项进行配置修改，如下图示：选Wake Word Implementation Type, 进去选择Multinet model选项，退出修改下列选项。
- Custom Wake Word：输入拼音，字与字之间用空格分隔，例如： xiao tu dou
- Custom Wake Word Display：对应中文显示，如： 小土豆
- Custom Wake Word Threshold (%)：识别阈值，建议15~25，值越小越敏感。
  
按键盘的‘S’键保存 然后Esc退出menuconfig，重新编译即可。

|            修改唤醒词①            | 修改唤醒词②                       | 修改唤醒词③                       |
| :-------------------------------: | :-------------------------------- | :-------------------------------- |
| ![](images/change_wake_word1.png) | ![](images/change_wake_word2.png) | ![](images/change_wake_word3.png) |

## 如何关闭AEC打断功能

ACE打断功能是指，在用户说话时，AI 语音助手会自动停下正在执行的指令，等待用户说话结束后再重新执行新的指令。

### 关闭AEC打断功能步骤
在idf.py menuconfig中进入Xiaozhi Assistant选项，点击Ena；ble AFE Audio Processsing即可关闭，按键盘的‘S’键保存 然后Esc退出menuconfig，重新编译即可。

![AEC打断功能](images/AFE.png)

## 利用MCP协议控制外设示例
AI 语音助手支持利用 MCP 协议控制外设。

## 知识库配置（重点）

使用时，需要在小智后台进行相应智能体的**知识库配置**，才能正常使用外设控制指令串口输出功能。

### 关于知识库

知识库用于存储 **"用户语音指令"** 与 **"串口输出指令"** 之间的映射关系。当小智 AI 识别到用户语音指令后，会查询知识库中是否匹配对应条目，若匹配则通过串口发送相应指令。

### 创建外设控制指令表（Excel）

新建 Excel 文件，按照以下格式输入外设控制的相应指令，然后保存。

| 外设控制                                                                                           | 串口发送指令       | 调用工具         | 备注 |
| :------------------------------------------------------------------------------------------------- | :----------------- | :--------------- | :--- |
| 打开灯                                                                                             | turn on led        | self.serial.send |      |
| 关闭灯                                                                                             | turn off led       | self.serial.send |      |
| 设置电机速度    代表转动速度，其绝对值为速度大小，正负代表旋转方向，速度大小为 0~255，x 默认为 100 | dc run speed 100   | self.serial.send | x    |
| 设置舵机转动角度                                                                                   | servo set angle 90 | self.serial.send |      |

### 新建知识库

1. 登录小智平台 **xiaozhi.me**
2. 点击进入【控制台】页面
3. 点击进入【知识库】模块
4. 点击【新建知识库】按钮
   
|                知识库模块                | 新建知识库                                   |
| :--------------------------------------: | :------------------------------------------- |
| ![知识库模块](images/knowledge_base.png) | ![新建知识库](images/new_knowledge_base.png) |

5. 在弹窗里填写相关信息，创建知识库：

| 配置项     | 说明                                                                                                        |
| :--------- | :---------------------------------------------------------------------------------------------------------- |
| 知识库名称 | 会在智能体配置时，显示在知识库列表里                                                                        |
| 知识库描述 | 介绍该知识库的作用，AI 会根据介绍内容来决定是否调用该知识库；描述词会直接影响 AI 调用逻辑，应尽可能准确描述 |

> **⚠️ 知识库描述参考（重要）**
>
> 本文档包含"外设控制的串口发送指令"内容，当用户提及外设控制时（如打开灯），我不能直接作答，必须在每次对话中调用该工具查询资料后，再调用相应 MCP 功能进行发送相应文本。注意，外设控制必须是在此资料中已有，如若在此资料中匹配不到相应外设控制，则应当回复暂时无法设置此功能。

### 上传指令文档

1. 在知识库列表中，找到刚刚创建的知识库，点击【查看】按钮，进入文档上传页面
2. 点击右上角的【新建文档】按钮
3. 选择第一步中新建的外设控制指令文档，点击【确定】上传
4. 文档上传成功后，系统会自动解析文档，解析完成后，状态会变成【解析完成】
   
|                  查看知识库                   |                新建文档                 |               添加文档               |                 选择文档                 |
| :-------------------------------------------: | :-------------------------------------: | :----------------------------------: | :--------------------------------------: |
| ![查看知识库](images/knowledge_base_view.png) | ![新建文档](images/upload_document.png) | ![添加文档](images/add_document.png) | ![选择文档](images/add_document_two.png) |
### 关联知识库

1. 在"控制台 → 智能体"模块页面
2. 选择 AI 语音助手所在的智能体，点击【配置角色】
3. 在配置角色页面，下拉找到并点击展开【MCP 设置】
4. 在"官方服务"中勾选【知识库】功能
5. 在下方【知识库配置】列表中，选择刚刚创建的外设控制指令知识库
6. 点击【保存】，并按提示**重启设备**，使配置生效
   
 |                  配置角色                  |               添加知识库                |                   添加成功                    |
 | :----------------------------------------: | :-------------------------------------: | :-------------------------------------------: |
 | ![配置角色](images/role_configuration.png) | ![添加知识库](images/knowledge_add.png) | ![添加成功](images/add_knowledge_success.png) |


## 串口参数说明

AI 语音助手通过 PH2.0 串口与外部 MCU（如 Arduino）通信，串口参数如下：

| 串口参数 | 配置      | 说明                     |
| :------- | :-------- | :----------------------- |
| TX 引脚  | IO 引脚 5 | 接外部串口工具的 RX 引脚 |
| RX 引脚  | IO 引脚 6 | 接外部串口工具的 TX 引脚 |
| 波特率   | 115200    | 波特率固定为 115200      |

> **⚠️ 接线注意**：串口接线需遵循 **"交叉连接"** 原则（本设备的 TX 接对端的 RX，本设备的 RX 接对端的 TX），接反会导致指令无法接收。


## Arduino 使用示例

下面通过一个完整的例子，演示如何用 Arduino Uno 接收 AI 语音助手的串口指令，控制 LED 灯、SG90 舵机和 R300C 电机风扇。

### 硬件准备

| 硬件                              | 数量 |
| :-------------------------------- | :--- |
| Arduino Uno 开发板                | 1    |
| AI 语音助手（已配置好相应知识库） | 1    |
| LED 灯                            | 1    |
| SG90 舵机                         | 1    |
| R300C 电机风扇                    | 1    |

### 硬件接线

| 模块              | Arduino 开发板引脚 |
| :---------------- | :----------------- |
| AI 语音助手引脚 5 | 12                 |
| AI 语音助手引脚 6 | 13                 |
| LED 灯            | 3                  |
| SG90 舵机         | 4                  |
| R300C 电机 INA    | 5                  |
| R300C 电机 INB    | 6                  |

![接线图](images/wiring_diagram.jpg)



### 程序下载与库安装

1. 下载并解压示例程序，用 Arduino IDE 打开示例文件
2. 主板选择 **Arduino Uno**
3. 本程序使用了 `Servo.h`（舵机库）和 `SoftwareSerial.h`（软件串口库），二者均为 Arduino IDE **自带的官方库**，无需额外安装

### Arduino IDE 代码

```cpp
#include <Servo.h>
#include <SoftwareSerial.h>

namespace {
constexpr uint8_t kSoftwareSerialRX = 12;
constexpr uint8_t kSoftwareSerialTX = 13;

constexpr uint8_t kServoPin = 4;
constexpr uint8_t kMotorInAPin = 5;
constexpr uint8_t kMotorInBPin = 6;
constexpr uint8_t kLedPin = 3;

SoftwareSerial g_soft_serial(kSoftwareSerialRX, kSoftwareSerialTX);
Servo g_servo;

const String knownCommands[] = {"turn on led", "turn off led", "dc run speed", "servo set angle"};

void SetMotorSpeed(const int16_t speed) {
  if (speed > 255 || speed < -255) {
    Serial.println("Error: Speed must be between -255 and 255");
    return;
  }
  if (speed >= 0) {
    analogWrite(kMotorInAPin, speed);
    analogWrite(kMotorInBPin, 0);
  } else {
    analogWrite(kMotorInAPin, 0);
    analogWrite(kMotorInBPin, -speed);
  }
  Serial.print("Motor speed set to: ");
  Serial.println(speed);
}

void SetServoAngle(const uint8_t angle) {
  if (angle > 180) {
    Serial.println("Error: Angle must be between 0 and 180");
  } else {
    g_servo.write(angle);
    Serial.print("Servo angle set to: ");
    Serial.println(angle);
  }
}

uint8_t StringSimilarity(const String &a, const String &b) {
  uint8_t matches = 0;
  for (uint8_t i = 0; i < min(a.length(), b.length()); i++) {
    if (a.charAt(i) == b.charAt(i)) {
      matches++;
    }
  }
  return matches * 100 / max(a.length(), b.length());
}

void ProcessCommand(const String &command) {
  command.trim();
  command.toLowerCase();

  int16_t best_index = -1;
  uint16_t best_score = 0;

  for (uint16_t i = 0; i < sizeof(knownCommands) / sizeof(knownCommands[0]); i++) {
    if (command.indexOf(knownCommands[i]) != -1) {
      best_index = i;
      break;
    }

    const auto score = StringSimilarity(command, knownCommands[i]);
    if (score > best_score && score > 60) {
      best_score = score;
      best_index = i;
    }
  }

  if (best_index == 0) {  // "turn on led"
    digitalWrite(kLedPin, HIGH);
    Serial.println("LED turned ON");

  } else if (best_index == 1) {  // "turn off led"
    digitalWrite(kLedPin, LOW);
    Serial.println("LED turned OFF");

  } else if (best_index == 2) {  // "dc run speed"
    if (command.lastIndexOf(' ') != -1) {
      SetMotorSpeed(command.substring(command.lastIndexOf(' ') + 1).toInt());
    } else {
      Serial.println("Error: No speed value provided for motor command");
    }

  } else if (best_index == 3) {  // "servo set angle"
    if (command.lastIndexOf(' ') != -1) {
      SetServoAngle(command.substring(command.lastIndexOf(' ') + 1).toInt());
    } else {
      Serial.println("Error: No angle value provided for servo command");
    }
  } else {
    Serial.println("Unknown command");
  }
}
}  // namespace

void setup() {
  Serial.begin(115200);

  g_soft_serial.begin(115200);

  pinMode(kLedPin, OUTPUT);
  digitalWrite(kLedPin, LOW);

  pinMode(kMotorInAPin, OUTPUT);
  pinMode(kMotorInBPin, OUTPUT);

  g_servo.attach(kServoPin);
  g_servo.write(90);

  Serial.println("System ready. Waiting for commands...");
}

void loop() {
  if (g_soft_serial.available() ) {
    String command = g_soft_serial.readStringUntil('\n');
    Serial.println("Received: " + command);
    ProcessCommand(command);
  }
}
```

### 实验结果

> ✅ 配置好 AI 语音助手的知识库，并将示例程序烧录到 Arduino Uno 后，给主板通电，用户即可通过语音发出控制指令。语音助手识别到指令后，会通过串口向 Arduino Uno 发送对应的控制指令（如 `turn on led`），Arduino 接收到指令后进行解析和匹配，最终控制相应的外设执行动作。
>
> 例如，对语音助手说"舵机转到 150 度"，语音助手通过串口发送 `servo set angle 150` 指令，Arduino 识别后即控制舵机旋转至 150 度位置。


## 常见问题排查

### Q1：语音助手无法识别语音指令？

1. 检查 AI 语音助手是否已进入语音交互模式（按下 Power 按键）
2. 检查网络配置是否正确，设备是否已成功激活

### Q2：语音助手能识别，但 Arduino 收不到指令？

1. **检查接线**：确认 AI 语音助手与 Arduino 之间是否**交叉连接**（TX 接 RX、RX 接 TX）
2. **检查共地**：确认 AI 语音助手的 GND 与 Arduino 的 GND 相连
3. **检查引脚**：确认 AI 语音助手引脚 5 接 Arduino D12、引脚 6 接 Arduino D13
4. **检查波特率**：确认代码中软件串口波特率为 **115200**

### Q3：串口监视器显示乱码？

检查串口监视器的波特率是否设置为 **115200**（与代码中 `mySerial.begin(115200)` 一致）。

### Q4：语音助手回复"暂时无法设置此功能"？

1. **检查知识库**：确认知识库中是否已包含对应的外设控制指令
2. **检查知识库描述**：确认知识库描述是否填写了推荐参考描述词
3. **检查智能体配置**：确认智能体已关联该知识库，并已重启设备使配置生效
