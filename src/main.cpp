#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);


//
double normalize(double angle) {
    while (angle > M_PI)  angle -= 2 * M_PI;
    while (angle <= -M_PI) angle += 2 * M_PI;
    return angle;
}

int SPEED = 6;
int TURNSPEED = 3;
int BREADTH = 3;

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  
}

void attack() {
  int ae = normalize(2*M_PI - M_PI/2);
  int w = ae*TURNSPEED;

  double left = SPEED - (w * BREADTH / 2);
  double right = SPEED + (w * BREADTH / 2);


  analogWrite(A0, left);
  analogWrite(A1, right);



}

void loop() {
  attack();
  delay(100);
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}