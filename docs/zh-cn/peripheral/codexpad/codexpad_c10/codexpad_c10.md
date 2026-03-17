# CodexPad-C10

## 产品图

![codexpad_c10](picture/codexpad_c10.png)

---

## 按键示意图

![功能示意图](picture/functional_illustration.jpg)

---

## 概述

**CodexPad-C10​** 是 CodexPad 系列中专为创客与嵌入式开发者打造的低功耗蓝牙手柄。与市面上依赖操作系统蓝牙协议栈的通用手柄不同，本产品**专为无操作系统的硬件平台打造**，无需系统层支持，即可直接与裸机运行的低功耗蓝牙硬件平台（ **ESP32** 系列、**ESP32-S** 系列、**ESP32-C** 系列、**STM32** 系列、**nRF** 系列、 **micro:bit**、**树莓派**系列等）进行对等通信，为机器人控制、物联网设备交互及自定义人机界面等项目提供灵活可靠的物理输入解决方案。

CodexPad-C10 继承了系列核心优势，提供简单易用的数据接口，开发者可轻松获取按键状态与摇杆模拟量数值。我们为适配的硬件平台配备了简洁的通信协议、轻量级驱动库及丰富的示例代码，并支持图形化编程环境，让从初学者到专业开发者都能快速将手柄集成到固件中，将创意高效转化为现实。

---

## 输入设备规格

- 按键数量: 5 （A/B/X/Y/START）
- 摇杆数量: 1
- 摇杆类型: 双轴模拟摇杆（支持按压，即 L3 功能）
- 摇杆分辨率: 8位（0 ~ 255）

---

## 电气特性

- 供电方式: 纽扣电池供电 或 USB Type-C接口直接供电
- 工作电压: **​3.3V** (纽扣电池)
- 电池类型: CR2032（推荐）
- 电池接口电压: **不能大于3.6V**
- 充电功能: 不支持，无充电功能
- 续航时间: 典型使用下约 2 小时

---

## 连接性与协议

- 蓝牙版本: Bluetooth Low Energy 5.3
- 蓝牙传输距离: 最大约30米（0 dBm，理想环境）
- 发射功率: **-16 dBm 到 +6 dBm** （可调）
- 震动反馈: 无
- 通信协议: 开放的、专为嵌入式优化的轻量级二进制协议
- 支持角色: BLE外设设备（从机）
- 抗干扰技术: 采用跳频技术，有效避免信号串扰

---

## 软件与兼容性

| 硬件平台 | 支持的开发环境 |
| :--- | :--- |
| ESP32 | Arduino IDE, MicroPython，米思齐（mixly），Mind+ |
| ESP32-S3 | Arduino IDE, MicroPython，米思齐（mixly），Mind+ |
| ESP32-C3 | Arduino IDE, MicroPython，米思齐（mixly），Mind+ |
| micro:bit | MakeCode |

- **即插即用示例**: 丰富的示例代码覆盖从基础连接到高级应用的各种场景

- **详细文档支持**: 提供完整的中英文技术文档和API参考

---

## 机械尺寸

- PCB厚度: 1.6mm
- 产品尺寸: 48*100mm

### 机械尺寸图

![机械尺寸图](picture/dimension_drawing.png)

<a href="zh-cn/peripheral/codexpad/codexpad_c10/codexpad_c10_3d.zip" download>点击下载3D文件</a>

---

## 安装电池

1. 将手柄电源开关拨动至`OFF​`端关闭电源，切断电路，防止安装过程中发生短路或静电损坏器件。

2. 小心剥离手柄背部外壳，露出背部电路板和电池扣插件。

3. 将手柄翻转至**背部朝上**。

4. 将CR2032纽扣电池**正极（"+"标识面）朝上**，平行于电池扣中间间隙，平滑推入，确保牢固卡住、不会脱落。

---

## 安装外壳

- 电池安装完毕后，立即将外壳装回并固定好，这样**避免手直接触碰背部电路，防止因静电或短路导致器件损坏**。

---

## 开机与关机

- **开机**：将手柄电源开关拨动至`ON`端打开电源，指示灯开始慢闪，设备启动。

- **关机**：将手柄电源开关拨动至`OFF`端关闭电源，指示灯熄灭，设备关机。

---

## 指示灯状态说明

| 指示灯状态 | 设备状态含义 |
| :--- | :--- |
| 慢闪 （约1秒亮/灭） | 已开机，正在广播信号，可被连接 |
| 快闪 （约100毫秒亮/灭） | 低电量警告。电池电量已不足，无法正常工作，请更换电池 |
| 常亮 | 已开机，已成功连接到主机设备 |
| 熄灭 | 已关机 |

---

## Bluetooth Device Address(BD_ADDR)说明

在连接与开发时，可能需要使用到设备的唯一标识：Bluetooth Device Address(BD_ADDR)。它如同设备的“身份证号”，是建立连接所必需的信息，若需指定连接本设备而非广播中的其他设备，将会使用到此信息。

> **注意：术语说明**  
> 本文档统一使用标准术语 Bluetooth Device Address(BD_ADDR)。请注意，在部分旧的示例代码、SDK或针对旧型号设备的文档中，可能会使用 MAC Address​ 来指代 Bluetooth Device Address(BD_ADDR)。在蓝牙上下文中，两者通常指向同一个地址。

它由12位十六进制字符组成，以冒号分隔，格式为`XX:XX:XX:XX:XX:XX`（其中`X`为 0-9 或 A-F），例如：`E4:66:E5:A2:24:5D`。在后续连接主机时，您将需要用到它。

### 获取Bluetooth Device Address(BD_ADDR)

> 💡 **重要提示：每台手柄均需单独获取**
>
> 由于此类手柄的Bluetooth Device Address(BD_ADDR)都是全球唯一的，因此每台新手柄在使用前，都需要按照此章节的步骤重新获取并记录其专属的Bluetooth Device Address(BD_ADDR)。请勿误以为获取一次即可通用于所有手柄。

请确保手柄已**开机**，并使用USB-Type C数据线将其与电脑连接，然后使用以下方式获取Bluetooth Device Address(BD_ADDR)并妥善保存。

#### 工作原理

当您使用USB数据线将手柄连接到电脑时，手柄会**虚拟成一个标准的串口设备（COM端口）**。获取Bluetooth Device Address(BD_ADDR)的本质，就是通过任意串口工具与这个虚拟串口进行通信。

**通信参数与流程：**

- **通用性**：任何串口工具（网页版、Windows、macOS、Linux）在正确配置后均可使用
- **关键配置**：波特率可任意设置，但务必使能DTR信号
- **自动应答**：连接成功后，手柄自动上报包含Bluetooth Device Address(BD_ADDR)的元数据信息

理解此原理后，您可以根据自身喜好和操作系统，选择下方任意一种工具进行操作。

---

#### 获取方式1：使用网页串口工具获取

1. 确保手柄已**开机**并已通过USB连接到电脑

2. 打开浏览器访问：<https://terminal.spacehuhn.com/>

3. 点击屏幕中间的**CONNECT**图标

4. 在弹出的设备列表中，选择以`CodexPad-C10`开头的设备，然后点击**连接**

    ![picture/find_bluetooth_device_address/web_serial_tool/01_connect_device.png](picture/find_bluetooth_device_address/web_serial_tool/01_connect_device.png)

5. 连接成功后，内容框会打印设备信息。在其中找到标识为 `7. Mac Address:`或者`7. Bluetooth Device Address(BD_ADDR):`的一行，将其后的内容复制并妥善保存，例如：`E4:66:E5:A2:24:5D`

    ![picture/find_bluetooth_device_address/web_serial_tool/02_find_bluetooth_device_address.png](picture/find_bluetooth_device_address/web_serial_tool/02_find_bluetooth_device_address.png)

6. 断开手柄与电脑的连接

---

#### 获取方式2：通过Windows电脑的串口调试助手获取

此方法使用通用的串口调试工具与手柄通信，获取Bluetooth Device Address(BD_ADDR)信息。

1. 安装串口调试助手

   - 访问串口调试助手下载页面：<https://apps.microsoft.com/detail/9nblggh43hdm?launch=true&hl=zh-cn&gl=cn>

   - 自行下载安装适用于Windows的最新版本

2. 启动串口调试助手

   - 安装完成后在桌面或开始菜单找到并启动程序

3. 配置串口连接

   - 选择正确的COM端口

     - 确保手柄已**开机**并已通过USB连接到电脑

     - 在软件界面的“**端口名**”下拉菜单中，选择对应的COM端口（例如`COM172`）

     - **如何确认哪个是手柄**：如果无法确定哪个端口对应手柄，您可以**拔掉手柄的USB线**，观察列表中哪个端口消失，**重新插上手柄**，观察哪个新出现的端口，该端口即对应您的手柄

   - 配置串口参数

     - **波特率**：可设置为任意值（如9600、115200等）

     - **数据位**：8

     - **停止位**：1

     - **校验位**：None (无)

     - **接收显示**：确保“十六进制显示”选项未勾选，以便查看文本格式的元数据

   - 启用DTR信号

     - 在软件界面中找到“**DTR**”选项，并点击启用它，选项会变为绿色

     ![picture/find_bluetooth_device_address/windows_serial_debugger/01_configure.png](picture/find_bluetooth_device_address/windows_serial_debugger/01_configure.png)

4. 连接并获取Bluetooth Device Address(BD_ADDR)

   - 完成上述配置后，点击“**打开**”按钮建立连接

       ![picture/find_bluetooth_device_address/windows_serial_debugger/02_click_open.png](picture/find_bluetooth_device_address/windows_serial_debugger/02_click_open.png)

   - 连接成功后，手柄会自动发送一次设备元数据，并显示在软件右侧的“**接收区**”

   - - 在接收区查看显示的数据找到标识为 `7. Mac Address:`或者`7. Bluetooth Device Address(BD_ADDR):`的一行，将其后的内容复制并妥善保存，例如：`E4:66:E5:A2:24:5D`

       ![picture/find_bluetooth_device_address/windows_serial_debugger/03_find_bluetooth_device_address.png](picture/find_bluetooth_device_address/windows_serial_debugger/03_find_bluetooth_device_address.png)

5. 断开手柄与电脑的连接

---

#### 获取方式3：通过Windows电脑的设备管理器获取

1. 启动“**设备管理器**”

   - **启动方式1**：启动 “**开始**”菜单，输入 “**设备管理器**”。 然后，从搜索结果中选择“**设备管理器**”点击启动

       ![picture/find_bluetooth_device_address/windows_device_manager/01_01_open_device_manager.png](picture/find_bluetooth_device_address/windows_device_manager/01_01_open_device_manager.png)

   - **启动方式2**：通过“**文件资源管理器**”启动

     - 在文件资源管理器中，右键单击“**此电脑**”，选择“**管理**”

         ![picture/find_bluetooth_device_address/windows_device_manager/01_02_01_right_click_computer_manage.png](picture/find_bluetooth_device_address/windows_device_manager/01_02_01_right_click_computer_manage.png)

     - 然后从生成的对话框中列出的系统工具中选择 “**设备管理器**”

         ![picture/find_bluetooth_device_address/windows_device_manager/01_02_02_select_device_manager.png](picture/find_bluetooth_device_address/windows_device_manager/01_02_02_select_device_manager.png)

2. 展开端口列表

   - 在设备管理器的设备列表中，找到并点击“**端口（COM和LPT）**”类别左侧的 “**>**” 符号，将其展开

        ![picture/find_bluetooth_device_address/windows_device_manager/02_expand_com_ports.png](picture/find_bluetooth_device_address/windows_device_manager/02_expand_com_ports.png)

3. 识别您的手柄设备

   - 在展开的列表中，您会看到一个或多个名为“**USB 串行设备 (COMxx)**”的条目，其中xx代表数字

   - **如何确认哪个是手柄**：如果列表中有多个此类设备，您可以**拔掉手柄的USB线**，观察列表中哪个“USB 串行设备”条目消失；**重新插上手柄**，观察哪个新出现的条目，该条目即对应您的手柄。请记下其COM口号（例如：COM172）

4. 打开设备属性

   - 右键点击您所识别出的“**USB 串行设备 (COMxx)**”，在弹出的菜单中选择“**属性**”

       ![picture/find_bluetooth_device_address/windows_device_manager/03_right_click_properties.png](picture/find_bluetooth_device_address/windows_device_manager/03_right_click_properties.png)

5. 查看设备详细信息

   - 在弹出的属性窗口中，点击顶部的“**详细信息**”选项卡

   - 在“**属性(P)**”下方的下拉菜单中，选择“**设备实例路径**”

       ![picture/find_bluetooth_device_address/windows_device_manager/04_select_instance_path.png](picture/find_bluetooth_device_address/windows_device_manager/04_select_instance_path.png)

6. 记录Bluetooth Device Address(BD_ADDR)

   - 此时，“**值(V)**”下方的文本框中将显示一串信息

   - - 在这串信息中，找到“**CODEXPAD-C10_**”字段，其后面紧跟的由冒号分隔的12位字符（例如：`E4:66:E5:A2:24:5D`）即为您手柄的Bluetooth Device Address(BD_ADDR)

       ![picture/find_bluetooth_device_address/windows_device_manager/05_find_bluetooth_device_address.png](picture/find_bluetooth_device_address/windows_device_manager/05_find_bluetooth_device_address.png)

   - - 请准确抄录这串Bluetooth Device Address(BD_ADDR)并妥善保管，用于后续连接

7. 断开手柄与电脑的连接

---

## 🔋 电源管理

为确保产品续航并避免不必要的电量损耗，当您长时间不使用手柄时，**请务必将手柄的电源开关拨动至 OFF位置**切断电源。在电源开启 (ON) 状态下，即使没有进行任何按键操作，手柄为保持可被连接状态，其低功耗蓝牙 (BLE) 模块仍会以一定间隔进行广播，这个过程会产生持续电流消耗。主动关机是最大限度延长纽扣电池使用寿命的最有效方式。

---

## ⚡ USB Type-C 接口说明

本手柄的 USB Type-C 接口主要用于 ① 为手柄电路供电​ 和 ② 虚拟串口通信（如用于获取Bluetooth Device Address(BD_ADDR)）。需要特别注意的是，此接口不具备电池充电功能。当手柄通过 USB 线缆供电运行时，若突然拔下线缆，系统会瞬间切换至纽扣电池供电。如果纽扣电池电量已处于较低水平，其电压在负载突然加大的瞬间可能无法及时响应，导致电压骤降而引发系统复位重启。此现象属于电源切换过程中的正常特性，并非设备故障。建议在需稳定使用的场景下，确保使用电量充足的电池或保持 USB 供电连接。

---

## 🛡️ 安装与静电防护

为防止静电放电 (ESD) 对精密电子元件造成不可逆的损伤，**在使用手柄前，必须确保其外部外壳已完全安装并紧固**。手柄背部的电路板直接暴露在外时，人体或环境产生的静电可能通过直接接触或近距离感应，瞬间击穿脆弱的集成电路，这种损伤通常是永久性的。完整的外壳构成了重要的物理屏障，能有效避免手部直接接触电路，是保证产品可靠性和使用寿命的关键步骤。

---

## 手柄TX Power（发射功率）设置

### 发射功率概述

发射功率（TX Power）是指手柄蓝牙射频信号的输出强度，其单位为 **dBm（分贝毫瓦）**。这是一个用于表示功率绝对值的对数单位。

- **数值大小的意义**：在dBm的标度下，**数值越大，代表发射功率越强**。例如，`+3 dBm` 的功率就比 `0 dBm` 强，而 `0 dBm` 又比 `-5 dBm` 强。每增加大约 `3 dBm`，实际功率约翻一倍。
- **正负号的意义**：`0 dBm` 代表1毫瓦（mW）的功率。**正数（如 +3 dBm）表示功率大于1毫瓦，负数（如 -12 dBm）表示功率小于1毫瓦。**
- **作用与权衡**：**增大发射功率可有效提升通信距离和信号抗干扰能力，但同时也会显著增加功耗，缩短电池续航时间。** 用户应根据实际使用场景（如通信距离、环境障碍物、对续航的要求）在信号强度和功耗之间进行权衡，选择一个合适的固定值。

### 设置方法与注意事项

- **默认值**：手柄在每次与主机建立蓝牙连接后，其发射功率**默认会自动重置为 0 dBm**。
- **设置方式**：必须通过主机端代码调用专用API（相关库中已提供）将目标功率值发送给手柄，设置会**立即生效**。
- **重要提示**：为避免无线连接出现波动，建议在单次连接中**仅设置一次**，避免频繁更改。请在设备初始化阶段根据应用场景选定一个合适的功率档位。

### 支持档位

手柄支持通过主机编程设置以下12个档位的发射功率（**从弱到强**排列）：

| 发射功率档位  |
| ------- |
| -16 dBm |
| -12 dBm |
| -8 dBm  |
| -5 dBm  |
| -3 dBm  |
| 0 dBm   |
| +1 dBm  |
| +2 dBm  |
| +3 dBm  |
| +4 dBm  |
| +5 dBm  |
| +6 dBm  |

您可以在主机示例代码中找到相应的API进行设置。

💡 建议：根据距离需求选择合适档位，避免频繁更改。

---

## 重要协议说明

CodexPad系列手柄采用**标准的低功耗蓝牙协议**进行通信，这与常见的**BLE HID**协议有本质区别。

- **协议类型**：本产品使用专为嵌入式开发优化的自定义标准BLE协议，而非即插即用的BLE HID协议。
- **连接与使用**：这意味着您的电脑或手机操作系统（如Windows、macOS、Android、iOS）在扫描并成功连接本手柄后，**不会将其识别为标准的游戏控制器或输入设备**，因此无法直接在任何游戏或应用中使用。
- **正确使用方式**：本产品的设计初衷是作为**一个可编程的输入模块**，必须通过您自己编写的主机端代码来连接手柄、读取其数据，并实现您所需要的控制逻辑。
  - **主要支持模式**：我们为**嵌入式开发板（如ESP32、micro:bit等）** 提供了完善的库和示例代码，这是推荐且官方技术支持的主要方向。
  - **进阶使用模式**：技术开发者也可以在**电脑（如使用Python、Node.js等）或手机（如使用Android Studio、Swift等）** 上编写主机端代码来连接并控制手柄。此为实现特定项目的进阶用法，**我司不提供此模式下的官方技术支持、库或示例**。关于其底层BLE GATT通信特征，我们后续将根据市场需求评估是否提供详细说明文档。

> **💡 请务必知悉**：本产品是为**可编程嵌入式项目**设计的开发工具。若您需要连接电脑或手机即插即用，本产品无法满足需求。若您是有能力的开发者，希望在PC或手机端集成本手柄，需要您自行研究其BLE通信协议。

---

## ⌨ 连接与使用

请根据您使用的硬件平台和开发平台，选择对应的库和示例代码进行开发。在示例代码中，通常需要填入手柄的 **Bluetooth Device Address(BD_ADDR)** 以建立连接。

### ESP32 Arduino库和示例程序

适用于在 **Arduino IDE** 或 **PlatformIO** 中进行开发。

| 硬件平台  |
| -------- |
| ESP32    |
| ESP32-S3 |
| ESP32-C3 |

<a href="https://gh-proxy.com/https://github.com/CodexPad/codex_pad_arduino_lib/archive/refs/tags/v1.0.5.zip" download>点击此处下载Arduino示例程序</a>

#### Arduino 库使用文档

<a href="https://codexpad.github.io/codex_pad_arduino_lib/html/zh-CN/annotated.html" target="_blank">点击此处查看API说明文档</a>

#### Arduino 库示例程序

<a href="https://codexpad.github.io/codex_pad_arduino_lib/html/zh-CN/basic_polling_8ino-example.html" target="_blank">基本轮询</a>

<a href="https://codexpad.github.io/codex_pad_arduino_lib/html/zh-CN/inputs_detection_8ino-example.html" target="_blank">输入状态检测</a>

### ESP32 MicroPython库和示例程序

适用于在 **MicroPython** 固件上进行开发。

| 硬件平台 |
| -------- |
| ESP32    |
| ESP32-S3 |
| ESP32-C3 |

<a href="https://gh-proxy.com/https://github.com/CodexPad/codex_pad_mpy_lib/archive/refs/tags/v1.0.1.zip" download>点击下载ESP32 MicroPython示例程序</a>

### Mind+库和示例程序

Mind+ CodexPad蓝牙手柄用户库链接：<https://gitee.com/emakefun_midplus_lib/codexpad-c10>

[点击查看Mind+导入用户库方法](https://mindplus.dfrobot.com.cn/extensions-user-libraries)

[点击下载CodexPad蓝牙手柄Mind+示例程序](https://gitee.com/emakefun_midplus_lib/codexpad-c10/releases/download/V0.0.1/codexpad_c10%E6%B5%8B%E8%AF%95%E7%A4%BA%E4%BE%8B.zip)

### Mixly库和示例程序

[点击下载CodexPad蓝牙手柄Mixly库](https://gitee.com/emakefun_mixly_lib/codexpad-c10/releases/download/V0.0.1/codexpad-c10_Mixly%E5%BA%93.zip)

[点击下载CodexPad蓝牙手柄Mixly示例程序](https://gitee.com/emakefun_mixly_lib/codexpad-c10/releases/download/V0.0.1/codexpad-c10%E8%93%9D%E7%89%99%E6%89%8B%E6%9F%84Mixly%E7%A4%BA%E4%BE%8B.zip)

### Micro:bit MakeCode图形化扩展

适用于在 **MakeCode** 图形化编程环境中为 micro:bit 开发。

| 硬件平台 |
| :--- |
| micro:bit |

**Microbit MakeCode扩展链接为**: **<https://github.com/CodexPad/codex_pad_makecode_extension>**

---

## ❓ 常见问题（FAQ）

### Q1：手柄无法开机怎么办？

**答：请按以下步骤排查**：

1. **检查电池安装**：

   - 确认纽扣电池正极（"+"面）朝上。
   - 确保电池已卡紧，没有松动。

2. **电池电量不足**：

   - 尝试更换一颗全新的纽扣电池。

3. **检查电源开关**：

   - 将开关完全拨至 ON 位置，确认到位。

4. **尝试USB供电**：

   - 通过Type-C 接口供电验证是否可以正常开机。

5. **硬件故障**：

   - 如果以上方法都不行，可能是硬件故障。
   - 请联系技术支持，提供您尝试过的步骤和现象描述。

### Q2：蓝牙连接不稳定、容易断开？

**答：可能原因及解决方法：**

- **距离过远/障碍物多**：尽量在无遮挡、无强干扰的环境中使用，理想通信距离建议不超过20米。
- **发射功率设置过低**：如果连接距离较远，可尝试通过主机代码将发射功率调高（如设为 +3 dBm 或更高）。
- **电池电量不足**：电量不足也会影响信号稳定性，请确保电池电量充足。
- **环境干扰**：远离路由器、微波炉、大型金属物体等可能干扰信号的设备。
- **多设备干扰**：避免周围有过多蓝牙/WiFi设备同时工作。

### Q3：为什么手机/电脑不能直接识别为手柄？

**答：CodexPad-C10**是一款为嵌入式开发设计的可编程BLE设备，采用专为嵌入式开发优化的自定义标准BLE协议，而非即插即用的BLE HID协议。因此它不能被系统直接识别为即插即用的手柄。您需要使用我们提供的主机端库，在ESP32、micro:bit等开发板上编写程序来读取和控制手柄。

### Q4：手柄多久进入休眠？如何唤醒？

**答**：**CodexPad-C10手柄暂不支持休眠功能**。

- **省电建议**：长时间不使用时，请将手柄电源开关拨动至`OFF`端以关闭电源，延长使用寿命。
- **重新使用**：再次使用时将手柄电源开关拨动至`ON`端即可开机。

### Q5：手柄可以充电吗？

**答：CodexPad-C10手柄不可以充电**。

- **供电方式**：
  - **纽扣电池供电**：使用CR2032纽扣电池（推荐）。
  - **USB Type-C 接口直接供电**：通过Type-C接口供电，但**不会给电池充电**。
- **重要提示**：
  - USB供电时如果电池电量过低，拔掉USB线可能导致设备重启。
  - 建议USB Type-C 接口供电时使用电量充足的电池，或保持USB连接。

### Q6：如何获取手柄的MAC Address？获取不到MAC Address怎么办？

**答：获取方法**：请参考本文档中 [📍 手柄MAC Address说明](#手柄MAC Address说明) 章节。

**如果无法获取，请按以下步骤排查：**

1. **检查手柄状态**：

   - 确认手柄已开机（指示灯慢闪）。
   - 如果指示灯不亮，检查电池和开关。

2. **检查USB连接**：

   - 使用优质USB数据线（支持数据传输）。
   - 尝试更换USB端口或电脑。

3. **检查电脑识别**：

   - 打开设备管理器（Windows）。
   - 查看"端口(COM和LPT)"下是否有新手柄设备。
   - 如果看不到，可能是驱动问题或数据线问题。

4. **检查工具配置**：

   - 使用网页工具时，确保浏览器支持Web Serial API（Chrome/Edge 89+）。
   - 使用串口工具时，确保参数配置正确以及启用了DTR信号。

5. **硬件故障**：

   - 如果以上方法都不行，可能是硬件故障。
   - 请联系技术支持，提供您尝试过的步骤和现象描述。
