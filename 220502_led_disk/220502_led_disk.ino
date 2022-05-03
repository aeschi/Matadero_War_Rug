#include "Disc.h"
#include "Servo.h"

#define EXE_INTERVAL 600

unsigned long previousTime = 0; // vairable to save the last executed time
unsigned long currentMillis = 0;
unsigned long seconds = 0;

Disc disc1(1);  // fake
Disc disc2(2);
Disc disc3(3);
Disc disc4(4);
Disc disc5(5);
Disc disc6(6);
Disc disc7(7);
Disc disc8(8);
Disc disc9(9);
Disc disc10(10);
Disc disc11(11);
Disc disc12(12);
Disc disc13(13);
Disc disc14(44);
Disc disc15(30);  // fake
Disc disc16(31);  // fake
Disc disc17(32);  // fake
Disc disc18(45);
Disc disc19(46);
Disc disc20(33);  // fake

// war kernel
int kerFac = 1;
float kernel[3][3] = {
  { 0.25 * kerFac, -0.5 * kerFac, 0.25 * kerFac },
  { -0.5 * kerFac, 1 * kerFac, -0.5 * kerFac },
  { 0.25 * kerFac, -0.5 * kerFac, 0.25 * kerFac }
};

// conflict map
float mapArray[4][5] = {
  { 0, 0, 0, 90, 90 },
  { 0, 0, 90, 90, 0 },
  { 0, 90, 0, 0, 0 },
  { 0, 0, 0, 90, 0 },
};

int mapArrW = 5;
int mapArrH = 4;

int matrixsize = 3;

int beatTime =0;
int counter = 0;
int beat = 0;


// an array with 4 rows and 5 columns.
Disc discs[4][5] = { { disc1, disc2, disc3, disc4, disc5 }, { disc6, disc7, disc8, disc9, disc10 }, { disc11, disc12, disc13, disc14, disc15 }, { disc16, disc17, disc18, disc19, disc20 } };

void setup() {
  Serial.begin(9600);  // open the serial port at 9600 bps:
  resetDiscs();
  calculateConflictRate();
}

void loop() {
  currentMillis = millis();

  
  rotateDiscs2();
}


void calculateConflictRate() {

  for (int x = 0; x < mapArrW; x++) {
    for (int y = 0; y < mapArrH; y++) {

      int sum = 0;

      int offset[3] = { -1, 0, 1 };

      for (int i = 0; i < matrixsize; i++) {
        for (int j = 0; j < matrixsize; j++) {
          int nx = x - offset[i];  // nx is neighbours x pos
          int ny = y - offset[j];  // ny is neighbours y pos

          nx = constrain(nx, 0, mapArrW - 1);
          ny = constrain(ny, 0, mapArrH - 1);

          int val = mapArray[ny][nx];

          if (val >= 90) {
            // and calculate the accumulated sum
            sum += kernel[j][i] * val;
          }
        }
      }

      int conflict = mapArray[y][x];

      // check for max value 90 and reset conflicts to 90 if less
      sum = min(sum + conflict, 90);

      // adding 90 for no negative values for the motors
      sum = 90 + sum;

      discs[y][x].confVal = sum;
      // Serial.println("pin: ");
      // Serial.println(discs[y][x]._pin);
      Serial.println(discs[y][x].confVal);
    }
  }
}

void rotateDiscs() {
 if((currentMillis-previousTime)>=EXE_INTERVAL){
    seconds++;
    previousTime = currentMillis;
    beat = seconds % 4;
    Serial.println(beat);
  
    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 4; y++) {
        
        if(discs[y][x].confVal>=180)
        {
          if(beat == 0){
            discs[y][x].setMovement(discs[y][x].confVal);
          }else if(beat == 1){
            discs[y][x].setMovement(90);
          }else if(beat == 2){
            discs[y][x].setMovement(discs[y][x].confVal);
          }else if(beat == 3){
            discs[y][x].setMovement(90);
          }
        }
        else if(discs[y][x].confVal<0)
        {
          if(beat == 0){
            discs[y][x].setMovement(90);
          }else if(beat == 1){
            discs[y][x].setMovement(discs[y][x].confVal);
          }else if(beat == 2){
            discs[y][x].setMovement(discs[y][x].confVal);
          }else if(beat == 3){
            discs[y][x].setMovement(90);
          }
        }
        else
        {
          if(beat == 0){
            discs[y][x].setMovement(90);
          }else if(beat == 1){
            discs[y][x].setMovement(90);
          }else if(beat == 2){
            discs[y][x].setMovement(discs[y][x].confVal);
          }else if(beat == 3){
            discs[y][x].setMovement(90);
          }
        }
      }
    }
  }
}

void rotateDiscs2() {
 if((currentMillis-previousTime)>=EXE_INTERVAL){
    seconds++;
    previousTime = currentMillis;
    beat = seconds % 5;
    Serial.println(beat);
  
    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 4; y++) {
        
        if(discs[y][x].confVal>=180)
        {
          if(beat == 0){
            discs[y][x].setMovement(discs[y][x].confVal* 0.25 * 0.5 + 90);
          }else if(beat == 1){
            discs[y][x].setMovement(discs[y][x].confVal * 0.5 * 0.5 + 90);
          }else if(beat == 2){
            discs[y][x].setMovement(discs[y][x].confVal * 0.75 * 0.5 + 90);
          }else if(beat == 3){
            discs[y][x].setMovement(discs[y][x].confVal * 0.5 + 90);
          }else if(beat == 4){
            discs[y][x].setMovement(90);
          }
        }
        else if(discs[y][x].confVal<90)
        {
          if(beat == 0){
            discs[y][x].setMovement(90);
          }else if(beat == 1){
            discs[y][x].setMovement(90 - discs[y][x].confVal*0.5);
          }else if(beat == 2){
            discs[y][x].setMovement(90 - discs[y][x].confVal*0.5);
          }else if(beat == 3){
            discs[y][x].setMovement(90 - discs[y][x].confVal);
          }else if(beat == 4){
            discs[y][x].setMovement(90);
          }
        }
        else
        {
          if(beat == 0){
            discs[y][x].setMovement(90);
          }else if(beat == 1){
            discs[y][x].setMovement(90);
          }else if(beat == 2){
            discs[y][x].setMovement(90 + discs[y][x].confVal);
          }else if(beat == 3){
            discs[y][x].setMovement(90 + discs[y][x].confVal);
          }else if(beat == 4){
            discs[y][x].setMovement(90);
          }
        }
      }
    }
  }
}

void resetDiscs() {

  Serial.println("reset");
  for (int x = 0; x < 4; x++) {
    for (int y = 0; y < 5; y++) {
      // discs[y][x].setMovement(discs[y][x].confVal);
      discs[x][y].reset();
      // discs[x][y].test();
    }
  }
  
}
