#include <TimerOne.h>

int val = 20;
const int fanPin = 40;
int pulseLength;
int up = 12;
int down = 13;
boolean fetUp = false;
boolean fetDown = false;
int repTime = 100;

void setup() {
  Serial.begin(9600);
  Timer1.initialize(20000);
  Timer1.attachInterrupt(pulse);
  pulseLength = 0;
  pinMode(up, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
}

void loop() {
    if(digitalRead(up) == LOW) {
      val += 5;   
      Serial.println(val);
      delay(100);
    }
    if(digitalRead(down) == LOW) {
      val -= 10;   
      Serial.println(val);
      delay(100);
    }
    pulseLength = 1000 + val;
  }

void pulse() {
  digitalWrite(fanPin, HIGH);
  delayMicroseconds(pulseLength);
  digitalWrite(fanPin, LOW);
}


