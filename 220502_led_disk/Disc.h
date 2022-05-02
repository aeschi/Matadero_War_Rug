#ifndef Disc_h
#define Disc_h
#include "Arduino.h"
#include "Servo.h"
 
class Disc {
public:
  Disc(int pin);
  void setDelayRate(int delayRate);
  void SetMovement(int confVal);
  void test();

  int _pin;

  int confVal;
  int beatTime;

private:
  Servo servo;
  
};
#endif
