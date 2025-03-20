# [RaspberryPi-Motordriver-Board V4.0](http://localhost:3000/#/en/raspberrypi/raspberrypi_sensor_board/raspberrypi_sensor_board?id=raspberrypi-sensor-board-v40)

The Raspberry Pi Sensor Expansion Board is designed by [Shenzhen Yichuang Space Technology Co., Ltd.](http://www.emakefun.com/) to facilitate the external sensor connection of the Raspberry Pi. This expansion board is suitable for Raspberry Pi Zero/Zero W/Zero WH/A+/B+/2B/3B/3B+/4B. The Raspberry Pi can be powered by a 5.5-2.1mm DC plug or terminal. The RF24L01 module, HC-SR04 ultrasonic module, I2C interface, UART interface, and 8-way ADC are reserved. At the same time, the camera and DIP display cable interface are free.



![raspberrypi_sensor_board](http://localhost:3000/en/raspberrypi/raspberrypi_sensor_board/picture/raspberrypi_sensor_boardv4.0.jpg)



## [Features](http://localhost:3000/#/en/raspberrypi/raspberrypi_sensor_board/raspberrypi_sensor_board?id=特点)

- Built-in 10-bit ADC MCU, supports 8-channel ADC detection, ADC value range is 0 ~ 1023
- Support Raspberry Pi 2B/3B/3B+/4B/zero
- 5.5x2.1DC header and terminal block for external power supply
- External sensor power supply voltage 3V3 and 5V switch
- Onboard DC-DC step-down chip wide voltage input: 5~36V Voltage output: 5V, Maximum current output: 5A, can directly power the Raspberry Pi

## [MCU Specifications](http://localhost:3000/#/en/raspberrypi/raspberrypi_sensor_board/raspberrypi_sensor_board?id=mcu规格)

- Working voltage: 3.3V and 5V Select ADC according to jumper cap Check voltage
- Communication method with Raspberry Pi: I2C rate 1~400K
- I2C address: 0x24, address can be configured on the back
- IO: 8-way ADC detection corresponding to pins A0~A7
- 8-channel expansion mode supports ADC input, GPIO, PWM (only A1-A2 supports),

## [Register](http://localhost:3000/#/en/raspberrypi/raspberrypi_sensor_board/raspberrypi_sensor_board?id=寄存器)

    The expansion board MCU I2C address is 0x24, and the register address description is as follows:



![picture9.png](http://localhost:3000/en/raspberrypi/raspberrypi_sensor_board/picture/picture10.png)



- 0x01 Register is mode setting

  The following modes can be set

  | Order | model               | Functional Description                                       |
  | ----- | ------------------- | ------------------------------------------------------------ |
  | 0x01  | Input pull-up       |                                                              |
  | 9x02  | Input Dropdown      |                                                              |
  | 0x04  | Floating input mode |                                                              |
  | 0x08  | Output Mode         | The pin can be configured as high or low level output mode, and then the pin outputs high or low level |
  | 0x10  | ADC Mode            | The pin can be configured as ADC mode, and then the ADC value of the pin can be read with an accuracy of 10 bits and an ADC value range of 0 to 1023. |
  | 0x20  | PWM Output Mode     | You can configure the PWM output frequency of the expansion board (1 ~ 10000Hz), then set the pin to PWM output mode, and then configure the duty cycle of the pin PWM output (12-bit precision: 0 ~ 4095), and then make the pin output PWM, which can be used to drive **the servo** |

- 0x10 ~ 0x17: Read ADC raw data

- 0x20 ~ 0x27: Read input voltage, unit is mv

- 0x30 ~ 0x37: Read the ratio of input voltage to output voltage, input voltage/output voltage (0~100)

- 0x40 ~ 0x47: Read or set the digital value of A0-A7

- 0x51 ~ 0x52: Set the PWM duty cycle of A1-A2

- 0x61 ~ 0x62: Set the PWM frequency of A1-A2

## [Raspberry Pi I2C library installation](http://localhost:3000/#/en/raspberrypi/raspberrypi_sensor_board/raspberrypi_sensor_board?id=树莓派i2c库安装)

    Open the Raspberry Pi terminal and enter the "sudo raspi-config" command, then follow the steps in the following figure.



![Local pictures](http://localhost:3000/en/raspberrypi/raspberrypi_sensor_board/picture/picture1.png)





![Local pictures](http://localhost:3000/en/raspberrypi/raspberrypi_sensor_board/picture/picture2.png)





![Local pictures](http://localhost:3000/en/raspberrypi/raspberrypi_sensor_board/picture/picture3.png)





![Local pictures](http://localhost:3000/en/raspberrypi/raspberrypi_sensor_board/picture/picture4.png)



    The above is to enable I2C on the Raspberry Pi. Next, we install the Raspberry I2C library by typing "sudo apt-get install i2c-tools" in the terminal. After the input is completed, you can see that the I2C library is being downloaded. After the installation is complete, you can enter "sudo i2cdetect -l" in the terminal to check whether it is installed correctly. If a message similar to the following appears, it means that the installation is normal.



![Local pictures](http://localhost:3000/en/raspberrypi/raspberrypi_sensor_board/picture/picture5.png)



    Enter the command "sudo i2cdetect -y 1" in the terminal to scan all I2C devices connected to the I2C bus and print out the I2C bus address of the device. The I2C address of our expansion board is 0x24.



![Local pictures](http://localhost:3000/en/raspberrypi/raspberrypi_sensor_board/picture/picture6.png)



!!! Edit the config.txt file to set the Raspberry Pi IIC bus speed

```markup
sudo nano /boot/config.txtCopy to clipboardErrorCopiedCopy to clipboardErrorCopied
```

Find the line containing "dtparam=i2c_arm=on", add ",i2c_arm_baudrate=100000", where 100000 is the new speed (100kbit/s), note the comma in front of i2c. The complete code is as follows:

```markup
dtparam=i2c_arm=on,i2c_arm_baudrate=100000Copy to clipboardErrorCopiedCopy to clipboardErrorCopied
```

This will enable the I2C bus and set the new baud rate. Once you are done editing, use CTRL-X, then Y, then Enter to save the file and exit.



![Local pictures](http://localhost:3000/en/raspberrypi/raspberrypi_sensor_board/picture/picture7.png)



Restart the Raspberry Pi to make the new settings take effect:

```markup
sudo rebootCopy to clipboardErrorCopiedCopy to clipboardErrorCopied
```

## [Read ADC analog value](http://localhost:3000/#/en/raspberrypi/raspberrypi_sensor_board/raspberrypi_sensor_board?id=读取adc模拟值)

    As we all know, there is no ADC in Raspberry Pi, so the analog value of the sensor cannot be read directly. With the help of the I2C ADC MCU built into the expansion board, the 10-bit ADC can be read. This means that analog sensors can be used on the Raspberry Pi, and there are a total of 8 available interfaces.

    The analog sensor inputs the analog voltage into the 10-bit analog-to-digital converter. The analog-to-digital converter converts the analog data into digital data and then inputs the digital data into the Raspberry Pi via I2C.

### [Python code](http://localhost:3000/#/en/raspberrypi/raspberrypi_sensor_board/raspberrypi_sensor_board?id=python代码)

```python
     import time
     import smbus as smbus
    
     ADC = smbus.SMBus(1)    # Declare to use I2C 1
    
     while True:
          ADC.write_byte(0x24, 0x10)    # Write a byte to the slave
          print(ADC.read_word_data(0x24, 0x10))    # Raspberry Pi reads the data returned by the expansion board and prints it out
          time.sleep(1)#Copy to clipboardErrorCopiedCopy to clipboardErrorCopied
```

### [C code](http://localhost:3000/#/en/raspberrypi/raspberrypi_sensor_board/raspberrypi_sensor_board?id=c代码)

```c
#include<stdio.h> // Import basic libraries
#include<wiringPi.h> // Import Raspberry Pi WiringPi coding IO control library
#include<wiringPiI2C.h> // Import Raspberry Pi WiringPi coding I2C control library
int value;//Define a variable
int main (void){
wiringPiSetup(); // Initialize WiringPi coding.
wiringPiI2CSetup(0x24); // Open the I2C device, 0x24 is the MCU I2C address on the expansion board
while(1){
wiringPiI2CWrite(0x24,0x10); // Write a byte to the slave
value = wiringPiI2CReadReg16(0x24,0x10); // Read the two bytes of the slave address and assign them to value
printf("%d\r\n",value); // Print value
delay(100);
}
}Copy to clipboardErrorCopiedCopy to clipboardErrorCopied
    
```

    If the following error occurs when generating the current file:



![Local pictures](http://localhost:3000/en/raspberrypi/raspberrypi_sensor_board/picture/picture8.png)



    If this problem occurs, please modify the build command to the following settings:

  Compile        gcc -Wall -c "%f"

        Build        gcc -Wall -o "%e" -lwiringPi "%f"

        Lint        cppcheck --language=c --enable=warning,style --template=gcc "%f"



![Local pictures](http://localhost:3000/en/raspberrypi/raspberrypi_sensor_board/picture/picture9.png)



## [Digital high and low level input](http://localhost:3000/#/en/raspberrypi/raspberrypi_sensor_board/raspberrypi_sensor_board?id=数字高低电平输入)

## [Digital high and low level output](http://localhost:3000/#/en/raspberrypi/raspberrypi_sensor_board/raspberrypi_sensor_board?id=数字高低电平输出)

## [PWM Output](http://localhost:3000/#/en/raspberrypi/raspberrypi_sensor_board/raspberrypi_sensor_board?id=pwm输出)

The original hardware PWM of Raspberry Pi only has GPIO1 GPIO26 GPIO23 GPIO24. The corresponding WiringPi pins are 1, 26, 23, 24. However, different libraries support different outputs, which may conflict with the hardware resources of Raspberry Pi, such as sound card, timer, etc. Therefore, this expansion board can solve this problem by expanding 2 PWM pins. However, only pins A1 and A2 support

## [Steering gear control](http://localhost:3000/#/en/raspberrypi/raspberrypi_sensor_board/raspberrypi_sensor_board?id=舵机控制)

With PWM support, we can also expand this pwm into an interface to drive the servo