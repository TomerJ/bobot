#include <Arduino.h>

#include <math.h>
// put function declarations here:
int myFunction(int, int);

int SPEED = 100;
int TURNSPEED = 3;
int BREADTH = 3;

void setup()
{
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.begin(9600);
  // l
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  // r
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  pinMode(A0, INPUT); // line sensor
  pinMode(A1, INPUT);
  pinMode(A2, INPUT); // middle thingy
  pinMode(A3, INPUT);
}

void stop()
{
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}

void forward()
{
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
}

void back()
{
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
}

void right()
{
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
}

void left()
{
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
}

void loop()
{
  if (digitalRead(A0))
  {

    delay(500);
    back();
    delay(500);
    right();
    delay(500);
    stop();
  }

  else if (digitalRead(A2))
  {
    forward();
  }

  else if (digitalRead(A1))
  {
    left();
  }

  else if (digitalRead(A3))
  {
    right();
  }
  else
  {
    right();
  }

  delay(50);
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}
