#include <Arduino.h>

// put function declarations here:

unsigned long previousTime = 0;
int sele = 0;
int pins[] = {2, 4, 16, 15};  
int Count = 4;

void setup() {
  for (int i = 0; i < Count; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentTime = millis();
    if (currentTime - previousTime >= 1000) {
        previousTime = currentTime;
        for (int i = 0; i < Count; i++) {
            digitalWrite(pins[i], LOW);
        }
        digitalWrite(pins[sele], HIGH);
        sele = (sele + 1) % Count;
    }
  }



