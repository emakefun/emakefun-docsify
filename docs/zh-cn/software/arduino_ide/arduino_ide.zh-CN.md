# Arduino IDE 2.0 介绍

## 软件概述

### IDE 介绍

Arduino IDE（Integrated Development Environment，集成开发环境）是专为Arduin 硬件开发设计的软件工具，它简化了编程过程，使得初学者和专业人士都能轻松开发微控制器应用。Arduino IDE 提供了一个易于使用的界面，允许用户使用基于 C/C++ 的简化语言编写、编辑、编译和上传代码到 Arduino微控制器板。‌建议在Windows 10且内存8G及以上配置的电脑上使用。

### Arduino IDE 2.0 和 1.0 的主要区别

相比于 2021 年之前发布的 Arduino IDE 1.x 版本，官方于 2022 年正式推出的 Arduino IDE 2.0 版本在重构后引入了多项核心改进，提升了开发效率与体验。

- **集成串口监视器与绘图仪**：允许同时打开 Serial Monitor（串口监视器）与全新的 Serial Plotter（串口绘图仪），可实时查看和绘制串口数据。

- **性能与界面优化**：全面提升了代码编译、上传及串口输出的速率，操作界面响应更迅速、更直观。  
- **智能代码补全**：支持基于已输入内容的智能代码提示与自动补全功能，并可检查潜在拼写错误，提高编码效率与准确性。  
- **深色主题模式**：提供重新设计、更具一致性与美感的深色主题（黑底白字），有效缓解长时间编程的视觉疲劳。  
- **云端项目同步**：无缝集成 Arduino Cloud 及 Arduino Web Editor，支持将项目草图（Sketch）存储在云端，实现在多台设备间的同步与接续开发。

- **强大的串口绘图仪**：新工具 Serial Plotter 能同时绘制多个变量的实时变化曲线，尤其适用于传感器数据校准及动态数据对比分析。

- **自动更新支持**：自动提醒并支持一键更新新增的开发板（Board）与库（Library）支持包，无需手动查找。

\_注\_：Arduino IDE 2.0基于 **Eclipse Theia** 框架开发（与 Visual Studio Code 同源），前端主要使用 TypeScript，后端主要使用 Go（Golang），采用了类似的 Language Server Protocol 和扩展架构。

### Arduino IDE 和市面上其他软件的区别（以 Keil 为例

|对比维度|Arduino IDE|Keil|
| ----- | ----- | ----- |
|**目标用户群**|主要面向初学者和爱好者，适合快速入门和原型开发。|通常用于专业的嵌入式系统开发，适用于需要高级功能和复杂项目的开发者。|
|**支持的硬件**|专注于支持 Arduino 开发板，提供简单的接口和库。|支持广泛的嵌入式开发板和芯片，适用于多种不同类型的嵌入式系统开发。|
|**功能和复杂性**|功能相对简单，适合快速原型设计和简单项目，编程界面易于理解。|功能更丰富和复杂，具有更强大的调试功能、性能优化和硬件支持。|
|**学习曲线**|学习曲线平缓，适合初学者迅速上手。|学习曲线较陡峭，需要更多时间和经验来掌握其功能和特性。|
|**开发生态**|拥有庞大的开源社区和丰富的开源项目资源，便于分享和学习。|作为专业嵌入式开发工具，提供了更为完善的支持和技术资源。|

## Arduino IDE 软件的使用

### 下载Arduino IDE软件

访问 [Arduino 官网](https://www.arduino.cc/en/software) 下载并安装 Arduino IDE 软件。

安装版本下载安装如下：<br>
![image](images/ide_downloard.png.gif)<br>

绿色安装包，下载后只需解压，即可直接使用但是选择Windows ZIP file，如下操作：

![image](images/green_ide_downloard.png)

### 环境设置

#### 中文设置

对于初学者而言，语言是一大难题，但在Arduino IDE2.0中，已内置官方中文语言包，你可以直接进行使用。

- 打开 Arduino IDE → 进入首选项<br>
File（文件） → Preferences（首选项）<br>
- 填写语言代码 zh-CN<br>
向下滚动，找到这一项：Editor Language（编辑器语言）<br>
在输入框里输入：zh-CN<br>
全小写即可，不要加引号<br>
- 保存并重启并IDE

#### 调试设置（打开编译上传日志）

在正式开发之前，需要打开编译日志，这样当我们程序出现错误，或者端口没接好，可以通过查看编译日志去排查我们的错误，具体操作如下：

打开**文件 → 首选项**，勾选这俩个选项

![build_log_option](images/build_log_option.png)

这时候再去查看程序，会显示出完整的错误日志，我们只需根据错误提示进行修改即可。

### 安装开发板

下载启动在Arduino IDE 2.0后，我们先要安装开发板后，才能进行开发，

- 打开开发板管理器，Arduino IDE中：**工具 → 开发板 → 开发板管理器**<br>
- 搜索并安装开发板支持包<br>
常见开发板搜索关键词：<br>
Arduino AVR Boards：搜索"avr"，安装"Arduino AVR Boards"<br>
Raspberry Pi Pico ：搜索"pico"，安装"Arduino Mbed OS RP2040 Boards"<br>
![board_install](images/board_install.png)

- 安装完成后，选择开发板， ：**工具 → 开发板 → 选择对应的开发板型号**<br>

![board_select](images/board_select.gif)

### 如何配置下载端口（以 Windows 为例）

端口是Arduino开发板与计算机通信的通道：

计算机 ←→ USB连接 ←→ 端口(COM/tty) ←→ Arduino开发板

#### Windows端口号确定

 通过设备管理器查找端口

- 打开设备管理器<br>
     - Win + X → 设备管理器<br>
     - 或：控制面板 → 设备管理器<br>
- 展开“端口(COM 和 LPT)”
- 查找USB串口设备：<br>
     ├── USB-SERIAL CH340 (COM3)     ← 常见克隆板<br>
     ├── USB Serial Port (COM4)      ← 官方板<br>
     ├── CP210x USB to UART (COM5)   ← CP2102芯片<br>
     └── Arduino Uno (COM6)          ← 官方原装Uno<br>
- 记住COM口号，在Arduino IDE中选择

![com_port_select](images/device_port.png)

##### Arduino IDE上配置端口

  找Arduino IDE中，在工具中**端口**选择设备管理器对应的端口好即可。

![com_port_select](images/com_port_select.png)

### 如何安装扩展库（以 Windows 为例）

#### 使用Arduino IDE自带的库管理器安装库文件。(在线库)

- 打开 Arduino IDE 软件，在上方菜单栏点击“工具”。
- 在“工具”菜单中，点击“管理库”，打开“库管理器”。
- 在搜索框中输入库名称，或浏览找到需要的库。
- 在显示的库信息中，点击“安装”按钮。

![lib_install](images/lib_install.gif)

#### 离线库安装

📥 **下载em_led库压缩包**

<a href="zh-cn/software/arduino_ide/em_led.zip" download>点击下载离线库</a>，

在文件夹中找到 em_led.zip

![em_led_lib](images/em_led_lib.png)

- 解压并安装
- 将下载的库文件安装进Arduino中

可以通过“导入库>添加一个.ZIP库”方式直接将压缩文件加入。

也可以将下载的压缩包文件解压，然后将解压出来的名为的文件夹移至 “C:\\用户名\\Documents\\Arduino\\Libraries”\\”里。

- 验证：重启IDE并测试

![add_local_lib](images/add_local_lib.png)

### 示例程序怎么使用

#### 使用示例程序

在Arduino IDE中，为了方便开发者学习，IDE内部集成了很多Arduino的例程，点击文件->示例可打开环境内置示例程序。Arduino自带非常多的例程，包括基础、数字、模拟、通讯、显示等。我们所用的是 Basic(基础例程的) Blink也就是点灯，相当于arduino界的“Hello,World”。

- “Verify”图标，确认程序是否可编译通过
- 点击上传图标，将代码烧录到你的主板中去

![blink](images/blink.gif)

然后你就能观察到开发板上的LED指示灯在以1秒为间隔不断地亮、灭。断电后重新给只开发板正确供电，开发板上的黄指指示灯依然能够以1秒为间隔不断地亮、灭。程序已经上载到开发板的内部Flash里面，可以脱离开发环境在开发板上离线运行了。

### IDE串口工具

#### 串口工具的作用

在嵌入式世界里，微控制器就像一个沉默的黑箱——它在高速运转，却不会说话。这时候，你需要的是是一双能“看见”程序运行过程和接收数据的眼睛。这双眼睛，就是 Arduino IDE 的串口工具 。

串口工具用于通过串行通信接口（COM口）与外部设备进行数据交互，支持参数配置、数据收发、协议调试等功能。

- 串口监视器是最基础的串口调试工具，用于查看串口接收到的文本数据，并可以发送简单的命令给设备。
- 串口绘图仪用于实时可视化串口数据，将接收到的数值绘制成动态曲线图。

#### 各个参数含义

- 波特率 (Baud Rate)：波特率表示每秒钟传输的位数。在串行通信中，发送和接收设备之间必须使用相同的波特率。常见的波特率包括9600、115200等。
- 数据位 (Data Bits)：数据位表示每个字节中包含的位数。通常设置为8位，但也可以是5、6、7或9位，具体取决于通信协议。
- 校验位 (Parity)：校验位用于在数据传输过程中检测错误。通常有无、奇校验和偶校验三种选项。 停止位 (Stop Bits)：停止位指示一个字节的结束。通常设置为1位或2位。
- 流控制 (Flow Control)：流控制用于控制数据传输的速率，常见的选项包括无流控制、硬件流控制 (RTS/CTS) 和软件流控制 (XON/XOFF)。

#### 串口监视器

使用串口监视器，你需要用USB线将Arduino连接到电脑，然后打开**Arduino IDE → 工具 → 串口监视器**（或者快捷键 `Ctrl+Shift+M` ）或者鼠标点击IDE右上角。

![serial_port](images/serial_port.png)

### 串口绘图仪

跟串口监视器一样，将Arduino与电脑连接起来，然后点击IDE菜单 **工具 → 串口绘图仪**。

![serial_port_analyzer](images/serial_port_analyzer.png)

## Arduino IDE2.0的秘密

想对Arduino IDE2.0进行深度的开发，我们需要对底层的驱动程序深入了解，这是win10系统下 Arduino IDE2.0的默认配置（路径可能会因系统设置而异）

|目录路径|大小|用途|
|-----|-----|-----|
|C:\Users\用户名.arduinoIDE|322K|IDE 配置文件|
|C:\Users\用户名\AppData\Local\arduino|110M|Arduino 数据存储|
|C:\Users\用户名\AppData\Local\Arduino15|1.1G|硬件包、库和工具链|
|C:\Users\用户名\Documents\Arduino|7.3M|用户项目库|

接下来我们逐一进行分析

### 库文件路径

默认情况下，ArduinoIDE库文件软件包的位置默认在“C:\\Users\\用户名\\Documents\\Arduino”（路径可能会因系统设置而异）。如果你想对其中的库进行修改，不想将其存放在C盘中，你可以进行下面的操作。

- 点开**文件 → 首选项**
- 修改项目文件夹地址，选择你想要存放的位置

![image](images/preferences.png)

修改完成后，打开Arduino IDE ，可以看到已经安装的库都可以正常使用了：

### Arduino开发板路径

在线安装的板卡（boards）存储路径会默认配置到C:\\Users\\你的用户名\\AppData\\Local\\Arduino15\\packages\\ （路径可能会因系统设置而异）或者我们可以通过编译代码，查看Arduino开发板路径。

![image](images/development_board_path.png)

在 C:\\Users\\用户名\\AppData\\Local\\Arduino15中，我们可以找到配置的开发板，这是其详细目录分析

```Plain Text
├── packages/arduino/
│   ├── hardware/
│   │   ├── avr/1.8.7                    # AVR 开发板支持
│   │   └── mbed_rp2040/4.5.0            # RP2040 开发板支持
│   └── tools/
│       ├── avr-gcc/7.3.0-atmel3.6.1     # AVR 编译器
│       ├── arm-none-eabi-gcc/7-2017q4   # ARM 编译器
│       ├── avrdude/8.0.0                # AVR 上传工具
│       ├── openocd/0.11.0               # 调试工具
│       └── rp2040tools/1.0.6            # Pico 工具链
├── libraries/                  # 内置库
├── builtin/                    # 内置工具
├── library_index.json          # 库索引（52MB）
└── package_index.json          # 包索引（1.4MB）
```

### 编译生成的文件路径

Arduino IDE（集成开发环境）生成HEX文件通常是在完成程序编写并上传到Arduino硬件的过程中发生的。默认路径配置在C:\\Users\\13797\\AppData\\Local\\arduino\\sketches（路径可能会因系统设置而异）中，以下是其编译输出目录结构

```Plain Text
C:\Users\13797\AppData\Local\arduino\sketches\随机ID

├── Blink/                      # 你的工程名称
│   ├── Blink.ino               # 源文件
│   ├── core/                   # Arduino 核心库
│   │   ├── core.a
│   │   └── ...
│   ├── includes/               # 头文件缓存
│   │   └── cache/
│   ├── libraries/              # 使用的库
│   │   └── ...
│   ├── sketch/                 # 编译后的 .o 文件
│   │   ├── Blink.ino.o
│   │   └── ...
│   ├── dependencies/           # 依赖关系文件
│   │   └── Blink.ino.d
│   ├── prerequisites/          # 前置条件
│   │   └── ...
│   ├── build.options.json      # 编译选项
│   └── firmware/               # 最终输出
│       ├── Blink.ino.hex       # 主要输出文件
│       ├── Blink.ino.hex       # 带启动引导的hex
│       ├── Blink.ino.elf       # ELF格式（调试用）
│       ├── Blink.ino.bin       # 二进制格式
│       └── Blink.ino.with_bootloader.hex
```

如果不知道自己的临时文件存储地址，我们可以通过Arduino IDE详细输出查看

- 编译你的工程（比如 Blink）
- 在输出控制台滚动到最底部，会看到类似：

```Plain Text
"C:\\Users\\nulllab\\AppData\\Local\\Temp\\arduino\\sketches\\D8A2978298DEA2D3900B293A63B6355A/Blink.ino.hex"
```

- 复制路径，在资源管理器中粘贴即可访问

### Arduino IDE2.0配置文件

默认情况下，Arduino IDE2.0配置是通过一个叫arduino-cli.yaml文件来配置的。位置在“C:\用户名\.arduinoIDE\arduino-cli.yaml”，修改该文件directories中的“libraries”、“data”、“downloads”中的路径，就可以变更默认库文件的存储位置，进而将系统盘中的整个Arduino15文件夹剪切到其他目录。

![arduino-cli_path](images/arduino-cli_path.png)

下图展示如何将“C:\Users\用户名\AppData\Local”文件夹内的Arduino15剪切到“D:\ProgramData”文件夹内  
修改arduino-cli.yaml修改后的内容如下：

```Plain Text
board_manager:
    additional_urls:
        - http://arduino.esp8266.com/stable/package_esp8266com_index.json
        - https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json
        - https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
build_cache:
    compilations_before_purge: 10
    ttl: 720h0m0s
daemon:
    port: "50051"
directories:
    builtin:
        libraries: C:\Users\用户名\AppData\Local\Arduino15\libraries
    data: d:\ProgramData\Arduino15
    downloads: D:\ProgramData\Arduino15\staging
    user: d:\Users\用户名\Documents\Arduino
library:
    enable_unsafe_install: false
locale: zh-cn
logging:
    file: ""
    format: text
    level: info
metrics:
    addr: :9090
    enabled: true
output:
    no_color: false
sketch:
    always_export_binaries: false
updater:
    enable_notification: true
```

修改完成后，打开Arduino IDE，可以看到已经安装的库都可以正常使用了。  
对这个arduino-cli文件感兴趣的[直接查看官方详细介绍](https://docs.arduino.cc/arduino-cli/getting-started/)

## 常见错误排查

### 如何通过编译错误定位解决问题

在使用Arduino开发板和Arduino IDE进行项目开发时，用户可能会遇到各种错误，这些错误可能源于硬件连接、软件配置或代码编写等方面的问题，以下是一些常见的Arduino报错及其解决方法：

### 确保打开编译日志

当我们程序出现错误，或者端口没接好，我们需要通过查看编译日志去排查我们的错误，具体操作如下**文件--》首选项 勾选编译、上传两个选项**：

![build_log_option](images/build_log_option.png)

我们打开Blink测试示例，当我们不插主板时，看看编译会提示我们什么。

![com3_error](images/com3_error.png)

点击上传，发现日志里提示我们can‘t open device“\\.\com3”:，这里告诉我我们端口COM3无法打开，因为我们拔掉usb线了，所以这时候我们再插入Arduino主板，就能够顺利的上传程序了，有时候也出现这种情况，也无法解决，可以尝试可以拔插一下usb、换个端口，重启电脑、重装驱动。

如果程序出现了问题了，要怎么排查呢？  
其实也是一样的，（假设我把36行代码后面的分号删掉），点击编译。

![program_error](images/program_error.png)

这就提示我们一个错误，再"}"之前没有分号，编译器也在对应的行数进行了标记。  
如果提示的错误我们不知道如何解决的话，我们也可以把错误信息到百度或者AI，看看别人如何解决问题的。

|**错误类型**|**错误描述**|**可能原因**|**解决方法**|
|-----|-----|-----|-----|
|Board not in Sync|计算机无法与Arduino板建立通信|1\. 电路板类型不匹配 2. 上传代码时未按下复位按钮 3. 串口管脚0、1被占用 4. 串口不匹配|1\. 检查并确保电路板类型与使用的一致 2. 在上传代码时按下电路板上的复位按钮 3. 断开串口管脚0、1中的一个连接线 4. 断开电路板，查看哪个端口从列表中消失，然后重新连接开发板并选择相应端口|
|COM端口错误|选择的串行端口与连接的Arduino板不正确|1\. USB数据线或开发板本身[存在](https://blog.huochengrm.cn/zmt/15089.html)问题 2. 多个设备连接到计算机 3. 驱动程序损坏或需要更新|1\. 断开并重新连接Arduino板 2. 检查设备管理器以查看Arduino板是否在端口部分下 3. 尝试不同的USB数据线或USB端口 4. 重新启动计算机和Arduino IDE|
|无法识别Arduino板|Arduino板没有被电脑识别|1\. USB电缆连接不牢固 2. USB数据线或开发板本身有问题 3. 驱动损坏或需要更新|1\. 验证USB电缆连接是否牢固 2. 检查设备管理器以查看Arduino板是否在端口部分下 3. 检查并更新驱动|
|串口正在使用中|尝试使用的端口当前正在被另一个应用程序或进程使用|1\. 其他应用程序正在使用串行端口 2. USB电缆连接问题|1\. 关闭可能正在使用串行端口的其他应用程序 2. 尝试从Arduino板上断开USB电缆，然后重新连接以释放串口 3. 使用不同的串行端口|
|串行监视器不工作|串行监视器无法显示数据或乱码|1\. 连接错误 2. 代码编写错误 3. 波特率设置不正确 4. 缓冲区数据过多|1\. 检查连接是否正确 2. 确保代码包含必要的Serial.begin()和Serial.print()语句 3. 调整串行监视器中的波特率设置 4. 按“清除”按钮清除缓冲区 5. 重置Arduino|
|编译错误|代码无法成功编译|1\. 语法错误 2. 缺失符号或分号 3. 拼写错误 4. 缺失变量定义 5. 程序中多余的文本|1\. 根据错误提示信息定位到出错位置并进行修正 2. 确保所有符号和分号正确无误 3. 检查拼写是否正确 4. 确保所有变量都已声明 5. 删除多余的文本|
|上传错误|代码无法成功上传至Arduino板|1\. 硬件连接故障 2. 选择了错误的开发板或端口 3. 草图[尺寸](https://blog.huochengrm.cn/ask/15210.html)大于电路板容量 4. 引导加载程序损坏|1\. 检查硬件连接是否正确 2. 确保选择了正确的开发板和端口 3. 减少代码占用空间或分割代码 4. 使用外部编程器上传草图或刷新引导加载程序|

### Arduino编译编译故障排查

要验证Arduino是软件问题、硬件问题还是驱动问题，可以按照以下步骤进行排查：

- **检查硬件连接**
物理连接：确保Arduino板正确连接到计算机，并且连接线没有损坏。检查USB端口是否工作正常，可以尝试连接其他设备到同一个端口。
电源指示灯：检查Arduino板上的电源指示灯（ON）是否亮起，确认电源供应是否正常。

- **检查主板**
按Arduino Uno主板上复位按键，看L灯是否会快闪3下，没有快闪，代表主控芯片坏掉或者bootloard丢失

- **检查驱动程序**
设备管理器：在计算机的设备管理器中查看是否有未知设备或有问题的设备。如果有，尝试更新或重新安装驱动程序。
驱动安装：参考Arduino IDE安装及驱动教程，确保已经安装了正确的驱动程序。对于Windows系统，可能需要手动安装驱动。
端口识别：在Arduino IDE中检查是否能够识别到串行端口。如果IDE无法识别串行端口，可能是驱动问题。

- **测试Arduino IDE**
IDE版本：确保使用的是最新版本的Arduino IDE，老版本的IDE可能存在兼容性问题。
板和端口选择：在IDE中选择正确的板型和端口。如果选择错误，IDE可能无法与Arduino板通信。

- **测试简单的程序**
基础程序：上传一个简单的程序（如Blink）到Arduino板上，检查LED是否闪烁。如果基础程序无法工作，可能是硬件问题。
串行通信：使用串行监视器测试串行通信是否正常。如果无法接收到数据，可能是硬件或驱动问题。

- **交叉替代检查**
替换测试：如果可能，尝试将Arduino板替换到另一台计算机上，或者使用另一块Arduino板替换当前的板，以排除是特定硬件的问题。
组件检查：检查Arduino板上是否有可见的损坏，如烧毁的组件或焊接问题。

- **软件问题排查**
编译错误：查看IDE中的编译错误信息，这可以提供关于代码问题的线索。
库依赖：确保所有必需的库都已经安装，并且代码中没有引用不存在的库或函数。

## 编写属于自己的扩展库

在开发过程中，为了满足自己或者项目的独特需求，我们需要掌握编写扩展库的能力

- 功能独特：现有库无法满足需求
- 代码复用：避免重复劳动
- 组织代码：让代码更清晰、易维护
- 封装复杂：隐藏实现细节，简化使用
- 模块化：便于测试和协作
- 保护知识产权：商业应用需要
- 社区贡献：分享知识，帮助他人

### 编写源文件头文件

在 C/C++ 开发中，一个代码模块通常由以下核心文件组成：

|文件|作用|
|-----|-----|
|**.h (Header)**|头文件，包含类声明、函数原型等。|
|**.cpp (Source)**|源文件，包含函数的具体实现。|

Arduino IDE继承了C/C++风格，因此封装功能模块通常需要成对的“.h”和“.cpp”（或“.c”）文件。例如，若要将LED 控制封装成模块，可以创建 `led.h` 和 `led.cpp` 两个文件。

**示例代码文件**

```Plain Text
/**
 *led.cpp
 */

#include "Arduino.h"
#include "led.h"

LED::LED(byte p, bool state) : pin(p)
{

    pinMode(pin, OUTPUT);
    digitalWrite(pin, state);
}

LED::~LED()
{
    detach();
}

void LED::on()
{
    digitalWrite(pin, HIGH);
}

void LED::off()
{
    digitalWrite(pin, LOW);
}

bool LED::getState()
{
    return digitalRead(pin);
}

void LED::detach() 
{
    digitalWrite(pin, LOW);
    pinMode(pin, INPUT);
}
```

和`led.cpp` 的源代码， examples中存放着`blink.ino` ，可以通过调用它实现点亮主板上自带的led灯的效果。
<a href="zh-cn/software/arduino_ide/em_led.zip" download>点击下载以上示例库</a>，

### 在Arduino上使用自己的库

如果模块好用且经常使用，可将它变成自己的库文件，以便于将来的项目直接调用。

#### 库的标准文件结构

```Plain Text
  MyLibrary/                    # 库文件夹（库名）
  ├── MyLibrary.h               # 头文件（声明）
  ├── MyLibrary.cpp             # 源文件（实现）
  ├── keywords.txt              # 可选：语法高亮
  ├── library.properties        # 可选：库元数据
  ├── examples/                 # 可选：示例代码
  │     └── BasicExample/
  │     └── BasicExample.ino
  └── README.md                 # 可选：说明文档
```

#### 使用自己的库的步骤

- 创建库文件（.h和.cpp）
- 放到正确位置（“C:\\用户名\\Documents\\Arduino\\Libraries”\\”）
- 重启Arduino IDE
- 在.ino中引用（#include < led.h>）
- 创建对象并使用

![led_lib](images/led_lib.png)

### 如何高效提问

 开发板出现错误时，我们要提供关键信息给到其他人需求支持，以下为具体步骤：

#### 1、描述问题

- **清晰简洁**：用简洁明了的语言描述您遇到的问题。
- **具体细节**：包括问题发生的具体场景和条件。

#### 2、提供错误信息

- **错误代码**：如果IDE或程序中有错误代码或错误消息，请提供完整的错误输出。
- **截图**：如果可能，提供屏幕截图或错误信息的图片。

#### 3、说明您的尝试

- **已采取措施**：列出您已经尝试的步骤和方法，以及这些尝试的结果。
- **相关修改**：如果您对代码或硬件进行了修改，请详细说明。

#### 4、提供环境信息

- **硬件信息**：提供Arduino板的型号、连接的外围设备等。
- **软件信息**：包括操作系统、Arduino IDE的版本、安装的库和插件等。
- **驱动信息**：如果适用，提供驱动程序的版本和安装状态。

#### 5、分享代码

- **代码片段**：分享出现问题的代码片段，但不要过长，只包含相关部分。
- **注释**：在代码中添加注释，指出可能的问题所在或您不确定的部分。

#### 6、描述期望的结果

- **预期行为**：说明您的代码或硬件应该表现出什么样的行为。
- **实际行为**：描述实际发生的情况，与预期行为的差异。
