#include "Arduino.h" 
#include "Disc.h"
#include "Servo.h"



Disc::Disc(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;

  confVal = 0;

  beatTime = 1000;
} 

void Disc::setMovement(int confVal){
  servo.attach(_pin);
  if(confVal>=90)
  {
    servo.write(confVal);
    delay(1000);
    servo.write(0);
    delay(1000);
    servo.write(confVal);
    delay(1000);
    servo.write(0);
  }
  else if(confVal<0)
  {
    servo.write(0);
    delay(1000);
    servo.write(confVal);
    delay(1000);
    servo.write(confVal);
    delay(1000);
    servo.write(0);

  }
  else
  {
    servo.write(0);
    delay(1000);
    servo.write(0);
    delay(1000);
    servo.write(confVal);
    delay(1000);
    servo.write(0);

  }
} 

void Disc::test(){
  servo.attach(_pin);
  servo.write(90);
  delay(1000);
  servo.write(0);
  delay(1000);
}


