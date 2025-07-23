#include <Arduino.h>

#include <math.h>
// put function declarations here:
int myFunction(int, int);

int SPEED = 100;
int TURNSPEED = 3;
int BREADTH = 3;


struct pii{
  double first,second;
};

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

int i = 0;
int j = 0;

double tL = M_PI/4;
double tC = 0;
double tR = -M_PI/4;

void attack() {
  if(j > i) {
      // reverse

      analogWrite(A0, -255);
      analogWrite(A1, -255);
      return;
  }
  if(analogRead(A3) > 200 && i > j) {
    j=i + 20;


    // find out how to reverse
  }

  double dL = max(digitalRead(A2)*255,0.01);
  double dC = max(digitalRead(A3)*255,0.01);
  double dR = max(digitalRead(A4)*255,0.01);

  pii vL = {1/dL * cos(tL), 1/dL * sin(tL)};
  pii vC = {1/dC * cos(tC), 1/dC * sin(tC)};
  pii vR = {1/dC * cos(tR), 1/dR * sin(tR)};




  double x = vL.first + vC.first + vR.first;
  double y = vL.second + vC.second + vR.second;
  

  double w = atan2(y,x) * TURNSPEED;


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
