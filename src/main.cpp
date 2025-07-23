#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

int SPEED = 6;
int TURNSPEED = 3;
int BREADTH = 3;

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
}

int i = 0;
int j = 0;

int tL = -M_PI/4
int tC = 0
int tR = M_PI/4

void attack() {
  if(j > i) {
      // reverse
      
  }
  if(analogRead(A3) > 200 && i > j) {
    j=i + 20;

    // find out how to reverse
  }
  double ang = atan2(1-analogRead(A2)/255, 1-analogRead(A3)/255) - M_PI/4;
  double w = ang*TURNSPEED;

  double left = SPEED - (w  / 2);
  double right = SPEED + (w / 2);


  analogWrite(A0, left);
  analogWrite(A1, right);



}

void loop() {
  attack();
  delay(50);
  i++;
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
