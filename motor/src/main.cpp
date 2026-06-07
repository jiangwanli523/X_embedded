#include <Arduino.h>
#include <Stepper28BYJ48.h>
 
const int stepsPerRevolution = 4096;  //28BYJ48电机旋转一周需要的步数
 
 
// 电机接在引脚8 ~ 11: 电机线依次为蓝，粉，黄，橙
Stepper myStepper(stepsPerRevolution, 15, 2, 4, 16);

void setup() {
  // initialize the serial port:
  Serial.begin(115200);
  
  //设置电机转速r/min
  myStepper.setSpeed(10);
}
 
void loop() {
  myStepper.step(stepsPerRevolution);
  Serial.print("steps:" );
  Serial.println(stepsPerRevolution);
  delay(2000);

  myStepper.step(-stepsPerRevolution);
  Serial.print("steps:" );
  Serial.println(-stepsPerRevolution);
  delay(2000);
  
}