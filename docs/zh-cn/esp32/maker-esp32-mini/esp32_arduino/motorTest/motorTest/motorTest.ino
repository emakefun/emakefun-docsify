#if ESP_ARDUINO_VERSION >= ESP_ARDUINO_VERSION_VAL(3, 0, 0)

#define BASE_FREQ 5000
#define LEDC_TIMER_8_BIT    8
struct motor_t {
  int pin1;
  int pin2;
};

motor_t motor[4] = {{27, 13}, {4, 2}, {17, 12}, {14, 15}};
void Motor_Speed(motor_t motorID, int speed) {  // 电机速度设置
                                                // ID=0~3,speed=-255~255
  if (speed == 0) {
    ledcWrite(motorID.pin1, 0);
    ledcWrite(motorID.pin2, 0);
  } else if (speed > 0) {
    ledcWrite(motorID.pin1, speed);
    ledcWrite(motorID.pin2, 0);
  } else {
    ledcWrite(motorID.pin1, 0);
    ledcWrite(motorID.pin2, -speed);
  }
}
void setup() {
  for (int i = 0; i < 4; i++) {
    ledcAttach(motor[i].pin1, BASE_FREQ, LEDC_TIMER_8_BIT);
    ledcAttach(motor[i].pin2, BASE_FREQ, LEDC_TIMER_8_BIT);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    Motor_Speed(motor[i], 255);  // 设电机组速度
    delay(1000);
    Motor_Speed(motor[i], (-255));  // 设电机组速度
    delay(1000);
  }
}

#else
void Motor_Setup(int motorID, int pin1,
                 int pin2) {  // 电机初始化 ID=1~4 定义四组电机
  ledcSetup(motorID * 2 - 2, 5000, 8);
  ledcAttachPin(pin1, motorID * 2 - 2);
  ledcSetup(motorID * 2 - 1, 5000, 8);
  ledcAttachPin(pin2, motorID * 2 - 1);
}
void Motor_Speed(int motorID, int speed) {  // 电机速度设置
                                            // ID=1~4,speed=-255~255
  if (speed == 0) {
    ledcWrite(motorID * 2 - 2, 0);
    ledcWrite(motorID * 2 - 1, 0);
  } else if (speed > 0) {
    ledcWrite(motorID * 2 - 2, speed);
    ledcWrite(motorID * 2 - 1, 0);
  } else {
    ledcWrite(motorID * 2 - 2, 0);
    ledcWrite(motorID * 2 - 1, -speed);
  }
}

void setup() {
  Motor_Setup(1, 27, 13);  // 设电机组标号和对应的引脚
  Motor_Setup(2, 4, 2);
  Motor_Setup(3, 17, 12);
  Motor_Setup(4, 14, 15);
}

void loop() {
  Motor_Speed(1, 255);  // 设电机组速度
  Motor_Speed(2, 255);
  Motor_Speed(3, 255);
  Motor_Speed(4, 255);
  delay(1000);
  Motor_Speed(1, (-255));
  Motor_Speed(2, (-255));
  Motor_Speed(3, (-255));
  Motor_Speed(4, (-255));
  delay(1000);
}
#endif