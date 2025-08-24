#include <Arduino.h>
#include <math.h>
#include <limits.h>

int SPEED = 255;




const int TURNSPEED = 3;
const int BREADTH = 3;

#define MOTOR_1_B 5
#define MOTOR_2_B 4
#define MOTOR_2_A 6
#define MOTOR_1_A 7

bool start = false;

#define LINE_LEFT A3
#define LINE_RIGHT A4

#define DIST_LEFT_T 8
#define DIST_MID_T 9
#define DIST_RIGHT_T 10
#define DIST_LEFT_E 11
#define DIST_MID_E 12
#define DIST_RIGHT_E 13

#define START 3

const int uthresh = 20;

float readSensor(int trigPin, int echoPin) {
  long duration;
  float distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, 30000);
  //Serial.println(duration);
  if (duration == 0) {
    return INT_MAX;
  }
  distance = duration * 0.034 / 2.0;
  return distance;
}

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_1_A, OUTPUT);
  pinMode(MOTOR_1_B, OUTPUT);
  pinMode(MOTOR_2_A, OUTPUT);
  pinMode(MOTOR_2_B, OUTPUT);
  pinMode(LINE_LEFT, INPUT);
  pinMode(LINE_RIGHT, INPUT);
  pinMode(DIST_LEFT_T, OUTPUT);
  pinMode(DIST_MID_T, OUTPUT);
  pinMode(DIST_RIGHT_T, OUTPUT);
  pinMode(DIST_LEFT_E, INPUT);
  pinMode(DIST_MID_E, INPUT);
  pinMode(DIST_RIGHT_E, INPUT);
  pinMode(START, INPUT_PULLUP);
  //digitalWrite(POWER_1, HIGH);

  delay(3000);
  start = true;
}
void stop() {
  digitalWrite(MOTOR_2_A, LOW);  // Left motor forward (inverted)
  digitalWrite(MOTOR_2_B, LOW);

  digitalWrite(MOTOR_1_A, LOW);  // Right motor forward
  digitalWrite(MOTOR_1_B, LOW);
}

void forward() {
  digitalWrite(MOTOR_2_A, HIGH);  // Right motor forward (inverted)
  digitalWrite(MOTOR_2_B, LOW);

  digitalWrite(MOTOR_1_A, HIGH);  // Left motor forward
  digitalWrite(MOTOR_1_B, LOW);
}

void back() {
  digitalWrite(MOTOR_2_A, LOW);  // Left motor forward (inverted)
  digitalWrite(MOTOR_2_B, HIGH);

  digitalWrite(MOTOR_1_A, LOW);  // Right motor forward
  digitalWrite(MOTOR_1_B, HIGH);
}

void left() {
  digitalWrite(MOTOR_2_A, HIGH);  // Left motor forward (inverted)
  digitalWrite(MOTOR_2_B, LOW);

  digitalWrite(MOTOR_1_A, LOW);  // Right motor stop
  digitalWrite(MOTOR_1_B, LOW);
}

void right() {
  digitalWrite(MOTOR_2_A, LOW);  // Left motor stop
  digitalWrite(MOTOR_2_B, LOW);

  digitalWrite(MOTOR_1_A, HIGH);  // Right motor forward
  digitalWrite(MOTOR_1_B, LOW);
}



void loop() {
  //Serial.println(analogRead(LINE_LEFT));

  float dleft = readSensor(DIST_LEFT_T, DIST_LEFT_E);
  delay(10);
  float dmid = readSensor(DIST_MID_T, DIST_MID_E);
  delay(10);
  float dright = readSensor(DIST_RIGHT_T, DIST_RIGHT_E);
  delay(10);

  int lineLeft = analogRead(LINE_LEFT);
  int lineRight = analogRead(LINE_RIGHT);
  Serial.print(lineLeft);
  Serial.print(" | ");
  Serial.print(lineRight);
  Serial.print(" | ");
  Serial.print(dleft);
  Serial.print(" | ");
  Serial.print(dmid);
  Serial.print(" | ");
  Serial.println(dright);
  Serial.println(digitalRead(START));
  if (digitalRead(START) == HIGH) {
    
   
    // 1. Edge detection override
    // if (lineLeft < 550 || lineRight < 550) {
    //   stop();
    //   delay(5000);
    //   back();
    //   delay(500);
    //   return;
    // }

    // float dleft  = readSensor(DIST_LEFT_T, DIST_LEFT_E);
    // delay(50);
    // float dmid   = readSensor(DIST_MID_T, DIST_MID_E);
    // delay(50);
    // float dright = readSensor(DIST_RIGHT_T, DIST_RIGHT_E);

    // 2. RAM when very close
    // if (dmid > 0 && dmid < 10) {
    //   forward();
    //   delay(500);
    // }
    if(dleft <= uthresh){
      left();
    }
    else if(dright <= uthresh){
      right();
    }
    else{
      forward();
    }
    if (dmid > uthresh && (lineLeft < 550 || lineRight < 550))
    {
      back();
      delay(500);
      left();
      delay(1000);
      forward();
    }
  }

  else {
    stop();
  }
}
