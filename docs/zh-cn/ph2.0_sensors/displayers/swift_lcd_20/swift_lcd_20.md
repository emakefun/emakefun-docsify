# SWIFT-LCD-20显示屏模块

## 实物图

![实物图](picture/swift_lcd_20.jpg)

## 概述

SWIFT-LCD-20显示屏模块是一款**2.0英寸**全彩TFT LCD显示屏模块，屏幕分辨率为**240\*320**像素。模块采用标准4线SPI通信接口和IPS硬屏技术，集成了高性能驱动芯片与背光电路，提供丰富的色彩显示和清晰的图像效果，具备色彩鲜艳、可视角度大、高对比度的特点。其核心设计亮点在于硬件连接的简化：关键的RES（复位） 与BLK（背光控制） 引脚已在模块内部通过电阻上拉至高电平，极大降低了硬件连接与初始化的复杂度。适用于需要内容更丰富的嵌入式人机交互场景。

### 产品特性

- 屏幕尺寸：2.0英寸
- 屏幕分辨率：240*320像素
- 显示颜色：全彩
- 背光类型：LED背光
- 驱动芯片：ST7789
- 通信接口：4线SPI
- 工作温度：-20°C ~ 70°C

## 原理图

![原理图](picture/schematic_diagram.png)

## 模块参数

- 工作电压：3.3V ~ 5V
- 接口：GH1.25间距接口
- 连接方式：GH1.25 转 PH2.0 6Pin 防反接连接线
- 模块尺寸：56*40mm

| 引脚名称  | 描述                   |
| -------- | ---------------------- |
| G        | GND 地线               |
| V        | 3.3V ~ 5V电源引脚       |
| SCL      | 串行接口时钟            |
| SDA      | SPI接口输入/输出引脚     |
| DC       | 数据显示/命令选择引脚    |
| CS       | 片选信号引脚，低电平有效  |
| RES      | 复位引脚                |
| BLK      | 背光控制引脚             |

**特别说明：RES（复位）和BLK（背光控制）引脚在模块内部默认拉高，不对外引出，无需外部连接。**

## 机械尺寸图

![机械尺寸图](picture/dimension_drawing.png)

## ESP32 Arduino 使用示例

**接线**

| 显示屏模块  | ESP32  |
| ---------- | ------ |
| CS         | 14     |
| DC         | 15     |
| SDA        | 16     |
| SCL        | 17     |
| V          | 5V     |
| G          | GND    |

**依赖库安装**

1. 打开管理库：Arduino IDE → 项目 → 导入库 → 管理库
2. 安装**lvgl** by kisvegabor，版本**9.2.2**
3. 安装**GFX Library for Arduino** by Moon On，版本**1.6.3**

<a href="zh-cn/ph2.0_sensors/displayers/swift_lcd_20/swift_lcd_20_example.zip" download>示例程序下载</a>

```c++
#include <lvgl.h>
#include <memory>

#include "Arduino_GFX_Library.h"
#include "lv_conf.h"

namespace {
constexpr gpio_num_t kDisplaySclk = GPIO_NUM_17;
constexpr gpio_num_t kDisplayMosi = GPIO_NUM_16;
constexpr gpio_num_t kDisplayDc = GPIO_NUM_15;
constexpr gpio_num_t kDisplayCs = GPIO_NUM_14;

constexpr uint32_t kExampleLvglTickPeriodMs = 2;

constexpr uint16_t kScreenWidth = 240;
constexpr uint16_t kScreenHeight = 320;

lv_display_t *g_display = nullptr;
lv_color_t g_display_buffer[kScreenWidth * kScreenHeight / 10] = {0};

std::unique_ptr<Arduino_DataBus> g_bus;
std::unique_ptr<Arduino_GFX> g_gfx;

lv_style_t g_large_white_font_style;

void OnDisplayFlush(lv_display_t *display, const lv_area_t *area, uint8_t *pixel_map) {
  const uint32_t width = area->x2 - area->x1 + 1;
  const uint32_t height = area->y2 - area->y1 + 1;

  g_gfx->draw16bitRGBBitmap(area->x1, area->y1, reinterpret_cast<uint16_t *>(pixel_map), width, height);

  lv_display_flush_ready(display);
}

void OnLvglTickTimer(void *arg) {
  lv_tick_inc(kExampleLvglTickPeriodMs);
}
}  // namespace

void setup() {
  g_bus = std::make_unique<Arduino_ESP32SPI>(kDisplayDc, kDisplayCs, kDisplaySclk, kDisplayMosi);

  g_gfx = std::make_unique<Arduino_ST7789>(g_bus.get(), -1, 0, true, kScreenWidth, kScreenHeight, 0, 0, 0, 0);

  if (!g_gfx->begin()) {
    printf("Error: Failed to initialize g_gfx.\n");
    return;
  }

  lv_init();

  const esp_timer_create_args_t lvgl_tick_timer_args = {.callback = &OnLvglTickTimer, .name = "lvgl_tick"};
  esp_timer_handle_t lvgl_tick_timer = NULL;
  esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer);
  esp_timer_start_periodic(lvgl_tick_timer, kExampleLvglTickPeriodMs * 1000);

  g_display = lv_display_create(kScreenWidth, kScreenHeight);
  if (g_display == nullptr) {
    printf("Error: Failed to create g_display.\n");
    return;
  }

  lv_display_set_flush_cb(g_display, OnDisplayFlush);
  lv_display_set_buffers(g_display, g_display_buffer, NULL, sizeof(g_display_buffer), LV_DISPLAY_RENDER_MODE_PARTIAL);

  lv_style_init(&g_large_white_font_style);
  lv_style_set_text_font(&g_large_white_font_style, &lv_font_montserrat_24);
  lv_style_set_text_color(&g_large_white_font_style, lv_color_white());

  lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x003a57), LV_PART_MAIN);

  lv_obj_t *label = lv_label_create(lv_screen_active());
  lv_label_set_text(label, "Hello World!");
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
  lv_obj_add_style(label, &g_large_white_font_style, 0);
}

void loop() {
  lv_timer_handler();
  delay(5);
}
```
