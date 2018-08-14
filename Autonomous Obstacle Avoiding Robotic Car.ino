#include <NewPing.h>        //Ultrasonic sensor function library. You must install this library */

//our L298N control pins
const int leftForward = 7;
const int leftBackward = 6;
const int rightForward = 5;
const int rightBackward = 4;
const int enA = 10;
const int enB = 9;

//sensor pins
#define trig_pin A1 //analog input 1
#define echo_pin A2 //analog input 2

#define maximum_distance 200
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function */

void setup(){
  pinMode(enA, OUTPUT);
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
}

void loop(){

moveForward();
distance = sonar.ping_cm();
if (distance <= 10){
  moveStop();
  delay(1000);
  moveBackward();
  delay(1000);
  moveRight();
  }
  else{
    moveForward();
  }
}

void moveForward(){
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  digitalWrite(leftForward, HIGH);
  digitalWrite(rightForward, HIGH);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightBackward, LOW);
}

void moveBackward(){
  analogWrite(enA, 100);
  analogWrite(enB, 100);
  digitalWrite(leftForward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightBackward, HIGH);
}

void moveStop(){
  digitalWrite(leftForward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightBackward, LOW);
}

void moveLeft(){

  analogWrite(enA, 200);
  analogWrite(enB, 200);
  digitalWrite(leftForward, HIGH);
  digitalWrite(rightBackward, HIGH);
  
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  
  delay(500);
  
  digitalWrite(leftForward, HIGH);
  digitalWrite(rightForward, HIGH);
  
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightBackward, LOW);
 
  
  
}

void moveRight(){

  analogWrite(enA, 200);
  analogWrite(enB, 200);
  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightForward, HIGH);
  
  digitalWrite(leftForward, LOW);
  digitalWrite(rightBackward, LOW);

  delay(500);
  
  digitalWrite(leftForward, HIGH);
  digitalWrite(rightForward, HIGH);
  
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightBackward, LOW);
}
