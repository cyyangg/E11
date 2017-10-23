#include <Servo.h>
#define SERVOPIN 10

Servo servo;

void testServo() {
  initServo();
  servo.write(90);
}


void initServo() {
  pinMode(SERVOPIN, OUTPUT);
  servo.attach(SERVOPIN);
}

