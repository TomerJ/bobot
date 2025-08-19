#include <Arduino.h>
#include <math.h>

// === Constants ===
int SPEED = 150;
const int TURNSPEED = 3;
const int BREADTH = 3;

// === Motor Pins ===
#define MOTOR_L_PWM 5
#define MOTOR_L_DIR 4
#define MOTOR_R_PWM 6
#define MOTOR_R_DIR 7

bool start = false;

// === Line Sensors ===
#define LINE_LEFT A3
#define LINE_RIGHT A4

// === Distance Sensors ===
#define DIST_LEFT  A0
#define DIST_MID   A1
#define DIST_RIGHT A2



// === Start Button ===
#define START 3

// === Power Supply Control ===
#define POWER_1 7
#define POWER_2 8
#define POWER_3 11
#define POWER_4 12
#define POWER_5 13

// === Setup ===
void setup() {
  Serial.begin(9600);

  // Motor pins
  pinMode(MOTOR_L_PWM, OUTPUT);
  pinMode(MOTOR_L_DIR, OUTPUT);
  pinMode(MOTOR_R_PWM, OUTPUT);
  pinMode(MOTOR_R_DIR, OUTPUT);

  // Line sensor pins
  pinMode(LINE_LEFT, INPUT);
  pinMode(LINE_RIGHT, INPUT);

  // Distance sensor pins
  pinMode(DIST_LEFT, INPUT);
  pinMode(DIST_MID, INPUT);
  pinMode(DIST_RIGHT, INPUT);

  // Start button
  pinMode(START, INPUT_PULLUP);

  // Power supply control
  pinMode(POWER_1, OUTPUT);
  pinMode(POWER_2, OUTPUT);
  pinMode(POWER_3, OUTPUT);
  pinMode(POWER_4, OUTPUT);
  pinMode(POWER_5, OUTPUT);

  digitalWrite(POWER_1, HIGH);
  digitalWrite(POWER_2, HIGH);
  digitalWrite(POWER_3, HIGH);
  digitalWrite(POWER_4, HIGH);
  digitalWrite(POWER_5, HIGH);

  delay(3000);
  start = true;
}

// === Motor Control ===
void stop() {
  analogWrite(MOTOR_L_PWM, 0);
  analogWrite(MOTOR_R_PWM, 0);
}

void back() {
  digitalWrite(MOTOR_L_DIR, LOW);
  digitalWrite(MOTOR_R_DIR, LOW);
  analogWrite(MOTOR_L_PWM, SPEED);
  analogWrite(MOTOR_R_PWM, SPEED);
}

void forward() {
  digitalWrite(MOTOR_L_DIR, LOW);
  digitalWrite(MOTOR_R_DIR, LOW);
  analogWrite(MOTOR_L_PWM, SPEED);
  analogWrite(MOTOR_R_PWM, SPEED);
}

void right() {
  // Left motor forward, right motor back
  digitalWrite(MOTOR_L_DIR, HIGH);
  digitalWrite(MOTOR_R_DIR, LOW);
  analogWrite(MOTOR_L_PWM, SPEED);
  analogWrite(MOTOR_R_PWM, SPEED);
}

void left() {
  // Left motor back, right motor forward
  digitalWrite(MOTOR_L_DIR, LOW);
  digitalWrite(MOTOR_R_DIR, HIGH);
  analogWrite(MOTOR_L_PWM, SPEED);
  analogWrite(MOTOR_R_PWM, SPEED);
}

// === Main Loop ===
int i;
void loop() {
  if (start == true) {
    i++;
    
    // Debug line sensors
    /*Serial.print("LINE_LEFT: ");
    Serial.print(analogRead(LINE_LEFT));
    Serial.print(" | LINE_RIGHT: ");
    Serial.println(analogRead(LINE_RIGHT));*/
   // forward();
    /*
    // Line detected (danger zone)
    if (analogRead(LINE_LEFT) < 100 || analogRead(LINE_RIGHT) < 100) {
      Serial.println("Edge detected -> backing up");
      back();
      delay(500);
      right();
      delay(200);
    }
    // If something is directly ahead
    else if (digitalRead(DIST_MID)) {
      forward();
    }
    // If something is on the left
    else if (digitalRead(DIST_LEFT)) {
      left();
    }
    // If something is on the right
    else if (digitalRead(DIST_RIGHT)) {
      right();
    }
    // Default: keep moving forward
    else {
      forward();
    }
    */

    if(digitalRead(START) == false) {
      forward();
    } else {
      stop();
    }
  }
}

// === Placeholder function ===
int myFunction(int x, int y) {
  return x + y;
}
