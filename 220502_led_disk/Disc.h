#ifndef Disc_h
#define Disc_h
#include "Arduino.h"
#include "Servo.h"
 
class Disc {
public:
  Disc(int pin);
  void setDelayRate(int delayRate);
  void SetMovement(int delayRate, int rotation);

  int _pin;

  float confVal;
  int beatTime;

private:
  Servo servo;
  
};
#endif
