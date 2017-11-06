//drive forward until it reaches black circle
//then drives the perimeter of the circle

#define REFLECT 18

#define WHITE 600
#define BLACK 700

void track() {
  //enable motors
  initMotors();

  //read reflect value
  pinMode(REFLECT, INPUT);
  int reflect = analogRead(REFLECT - 14);
  Serial.println(reflect);
//
//  //first drive forward until detect black
//  while(reflect < WHITE)
//  {
//    setPL(100);
//    forward();
//  }

  

  //follow perimeter of black by turning left when detect white
  if(reflect < WHITE)
  {
    setPL(100                                                       );
    turnL();
    delay(50);
    halt();
    delay(20);
  }

  //then if on black go forward
  else if(reflect > BLACK)
  {
    setPL(100);
    forward();
  }
}

