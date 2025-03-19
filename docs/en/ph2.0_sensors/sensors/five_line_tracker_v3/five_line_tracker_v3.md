# [Five-Line Tracker V3.0](http://localhost:3000/#/en/ph2.0_sensors/sensors/five_line_tracker_v3/five_line_tracker_v3?id=五路循迹模块v30)

## [Describe](http://localhost:3000/#/en/ph2.0_sensors/sensors/five_line_tracker_v3/five_line_tracker_v3?id=描述)

The module mainly uses a grayscale sensor for line detection. It is a photoelectric sensor with strong resistance to interference. The light source of the transmitting tube uses a high-brightness white concentrated LED. The light emitted by the transmitting tube is reflected by different environmental backgrounds and finally received by the photosensitive receiving tube. The impedance of the photosensitive receiving tube changes with the intensity of the reflected light (the stronger the reflected light, the smaller the resistance). Finally, the dual output of digital and analog signals is realized through the voltage divider and operational amplifier comparison circuit.

The grayscale sensor module has a very good recognition effect on background environments with different white light reflection strengths. The greater the background difference, the better the resolution effect. Grayscale sensors have higher anti-interference capabilities than ordinary infrared sensors.

The module supports five digital outputs. If a black line is recognized, the output is 0, and if a black line is not recognized, the output is 1. We can adjust the tracking detection height by setting the grayscale reflection simulation threshold.

The module can also directly read the analog voltage value on the five-way grayscale receiving sensor. When a black line is detected or it is closer to a black line, the value will be larger, and vice versa.

It is recommended that the probe be about 1CM away from the ground.

## [Physical Picture](http://localhost:3000/#/en/ph2.0_sensors/sensors/five_line_tracker_v3/five_line_tracker_v3?id=实物图)

## [Product Parameters](http://localhost:3000/#/en/ph2.0_sensors/sensors/five_line_tracker_v3/five_line_tracker_v3?id=产品参数)

- Working voltage: 3~5V
- Communication method: IIC
- Interface type: PH2.0-4Pin (GV SDA SCL)
- Detection height: 0.5cm ~ 4 cm
- Output value: analog value and digital value

## [Pin Definition](http://localhost:3000/#/en/ph2.0_sensors/sensors/five_line_tracker_v3/five_line_tracker_v3?id=引脚定义)

| Pin Name | describe       |
| -------- | -------------- |
| V        | 3~5V power pin |
| G        | GND Ground     |
| SDA      | IIC data pin   |
| SCL      | IIC clock pin  |

## [Module size](http://localhost:3000/#/en/ph2.0_sensors/sensors/five_line_tracker_v3/five_line_tracker_v3?id=模块尺寸)

## [Instructions](http://localhost:3000/#/en/ph2.0_sensors/sensors/five_line_tracker_v3/five_line_tracker_v3?id=使用说明)

The tracking module can read the received analog value and digital value of each photosensitive probe. Each probe has a high threshold and a low threshold. When the analog value is higher than the high threshold, the digital value is 0; when the analog value is lower than the low threshold, the digital value is 1. If the analog value is between the high threshold and the low threshold, the digital value will not change. In other words, when the analog value increases, it must be higher than the high threshold for the digital value to become 0; when the analog value decreases, it must be lower than the low threshold for the digital value to become 1, thereby achieving the effect of delayed reversal.

The high and low thresholds can be set by the user according to the actual scenario. If the user does not set it, the default value in the factory firmware will be used. It is recommended to install the module on the car first, so that the probe is about 1CM off the ground. Then, put the car on the line so that all probes can detect the line. At this time, use the program to read the analog value and calculate the average value, recorded as `X`. Next, put the car on the line so that all probes can detect the non-line ground. Use the program again to read the analog value and calculate the average value, recorded as `Y`. The high threshold can be set to `(X - Y) * 2 / 3 + Y`, and the low threshold is set to `(X - Y) / 3 + Y`.

Please refer to the following sections for how to set the threshold and how to read the digital and analog values.

## [Arduino (C/C++) Example Code](http://localhost:3000/#/en/ph2.0_sensors/sensors/five_line_tracker_v3/five_line_tracker_v3?id=arduinocc示例代码)

### [Arduino Library and Example Code](http://localhost:3000/#/en/ph2.0_sensors/sensors/five_line_tracker_v3/five_line_tracker_v3?id=arduino库和示例代码)

[Click here to download the Arduino library and example code](http://localhost:3000/#/emakefun_five_line_tracker_v3.zip)

## [Micropython Example Code](http://localhost:3000/#/en/ph2.0_sensors/sensors/five_line_tracker_v3/five_line_tracker_v3?id=micropython示例代码)

[Click here to download the ESP32 MicroPython example code](http://localhost:3000/#/five_line_tracker_v3_micropython.zip)

## [Mixly Graphical Blocks](http://localhost:3000/#/en/ph2.0_sensors/sensors/five_line_tracker_v3/five_line_tracker_v3?id=mixly图形化块)



![loading-ag-147](http://localhost:3000/en/ph2.0_sensors/sensors/five_line_tracker_v3/pictures/mixly_select.png)



[Click to download Misiqi Five-Way Tracking V3.0 to get the simulation value sample program](http://localhost:3000/#/./examples/mixly_get_analog.zip)

[Click to download Misiqi Five-Way Tracking V3.0 Get Digital Value Sample Program](http://localhost:3000/#/./examples/mixly_get_digital.zip)

## [Mind + Graphics](http://localhost:3000/#/en/ph2.0_sensors/sensors/five_line_tracker_v3/five_line_tracker_v3?id=mind图形化)

[Click to download Mind + Five-way Tracking V3.0 User Library](http://localhost:3000/#/./libs/emakefun-em_five_tracker_v3-thirdex-V0.0.1.mpext)



![Mind+ Select Five-way Tracking V3.0](http://localhost:3000/en/ph2.0_sensors/sensors/five_line_tracker_v3/pictures/mindplus_select.png)



[Click to download mind + sample](http://localhost:3000/#/./examples/mindplus_example.mp)

## [Microbit Sample Program](http://localhost:3000/#/en/ph2.0_sensors/sensors/five_line_tracker_v3/five_line_tracker_v3?id=microbit示例程序)

Stay tuned...

