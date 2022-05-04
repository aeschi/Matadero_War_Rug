#include "Arduino.h" 
#include "Disc.h"
#include "Servo.h"



Disc::Disc(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;

  confVal = 0;
  beatTime = 100;
} 


void Disc::setMovement(int confVal){
  servo.write(confVal);
}

void Disc::reset(){
  servo.attach(_pin);
  servo.write(90);
}  

void Disc::test(){
  servo.attach(_pin);
  servo.write(180);
  delay(400);
  servo.write(0);
  delay(400);
  servo.write(180);
  delay(400);
  servo.write(0);
  delay(400);
  servo.write(90);
}



