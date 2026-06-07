#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    pinMode(15, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
    Serial.println("发送 '1' 改变LED1，发送 '2' 改变LED2，发送 '3' 改变LED3，其余指令无效");
}

void loop() {
    if (Serial.available() > 0) {
        char cmd = Serial.read();

        if (cmd == '1') {
            digitalWrite(15, !digitalRead(15)); // 切换LED1状态
            Serial.println("LED1 状态已切换");
        } 
        else if (cmd == '2') {
            digitalWrite(2, !digitalRead(2)); // 切换LED2状态
            Serial.println("LED2 状态已切换");
        }
        else if (cmd == '3') {
            digitalWrite(4, !digitalRead(4)); // 切换LED3状态
            Serial.println("LED3 状态已切换");
        } 
        else {
            Serial.println("无效指令，请发送 '1'、'2' 或 '3'");
        }
    }
}