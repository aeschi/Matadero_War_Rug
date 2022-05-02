#include "Arduino.h" 
#include "Disc.h"
#include "Servo.h"



Disc::Disc(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;

  confVal = 0;

  beatTime = 1000;
}
void Disc::setDelayRate(int d){
  digitalWrite(_pin, HIGH);
  delay(d);
  digitalWrite(_pin, LOW);
  delay(d);
} 

void Disc::SetMovement(int delayRate, int rotation){
  servo.attach(_pin);
  servo.write(90);
  delay(delayRate);
  servo.write(rotation);
  delay(delayRate);
} 


