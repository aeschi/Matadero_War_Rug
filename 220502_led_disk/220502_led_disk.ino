#include "Disc.h"
#include "Servo.h"

Disc disc1(1); // fake
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
Disc disc15(30); // fake
Disc disc16(31); // fake
Disc disc17(32); // fake
Disc disc18(45);
Disc disc19(46);
Disc disc20(33); // fake

// war kernel
int kerFac = 1;
float kernel[3][3] = {
  {0.25 * kerFac, -0.5 * kerFac, 0.25 * kerFac},
  {-0.5 * kerFac, 1 * kerFac, -0.5 * kerFac},
  {0.25 * kerFac, -0.5 * kerFac, 0.25 * kerFac}
  };

// conflict map
float mapArray[4][5] = {
  {0, 0, 0, 100, 100},
  {0, 0, 100, 100, 0},
  {0, 100, 0, 0, 0},
  {0, 0, 0, 100, 0},
};

int matrixsize = 3;

// an array with 4 rows and 5 columns.
Disc discs[4][5] = {{disc1,disc2,disc3,disc4,disc5}, {disc6,disc7,disc8,disc9,disc10}, {disc11,disc12,disc13,disc14,disc15}, {disc16,disc17,disc18,disc19,disc20}};

void setup() {
  Serial.begin(9600);      // open the serial port at 9600 bps:    
  
}

void loop() {
  // disc4.setDelayRate(2000);

  disc2.setDelayRate(1000);
  getNeighbour(1,3);
  //  disc2.SetMovement(1000, 170);
}

void getNeighbour(int x, int y){
    int offsetX[8] = {0,1,1,1,0,-1,-1,-1};
    int offsetY[8] = {-1,-1,0,1,1,1,0,-1};
    //int sum = discs[y][x];
    for(int i=0; i<sizeof(offsetX); i++){
    int nx = x + offsetX[i]; // nx is neighbours x pos
    int ny = y + offsetY[i]; // ny is neighbours y pos

    if(nx<0 || nx > 5 || ny < 0 || ny > 5 ){
      continue;
    }
    Serial.println(discs[nx][ny]._pin);

    // Serial.println(mapArray[1][2]);
    // sum += Disc[ny][nx]
    //calculate speed here 
  }
}


void discConvolution(int x, int y, int matrixsize){
  float confVal = 0.0;

  int offset = matrixsize/2;

  for (int i = 0; i < matrixsize; i++){
    for (int j= 0; j < matrixsize; j++){

      // What pixel are we testing
      int xloc = x+i-offset;
      int yloc = y+j-offset;
      // int loc = xloc + img.width*yloc;
      // Make sure we haven't walked off our image, we could do better here
      loc = constrain(loc,0,img.pixels.length-1);
      // Calculate the convolution
      confVal += (img.pixels[loc] * kernel[i][j]);
    }
  }
}