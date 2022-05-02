#ifndef Disc_h
#define Disc_h
#include "Arduino.h"
#include "Servo.h"
 
class Disc {
public:
  Disc(int pin);
  void setMovement(int confVal);
  void test();
  void reset();

  int _pin;

  int confVal;
  int beatTime;

private:
  Servo servo;
  
};
#endif
