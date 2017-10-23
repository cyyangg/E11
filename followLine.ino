//follow the line in a CCW motion

#define REFLECT 18

//white = 32 to 47 (mode 44)
#define WHITE 590
//grey = 61 to 95 (mode 76)
#define GREYLOW 600
#define GREYHIGH 680
//black = more than 100 (mode 101)
#define BLACK 680

void followLine() {
  //enable motors
  initMotors();

  //read reflect value
  pinMode(REFLECT, INPUT);
  int reflect = analogRead(REFLECT - 14);
  Serial.println(reflect);
  
  //if on white, turn right to find line
  if(reflect < WHITE) 
  {
    setPL(220);
    turnR();
    delay(10);
    halt();
    delay(12);


  }

  //if on grey, turn left ot find line
  else if(reflect < GREYHIGH && reflect > GREYLOW)
  {
    setPL(220);
    turnL();
    delay(10);
    halt();
    delay(12);

  }

  //if on black, go forward
  else if(reflect > BLACK)
  {
    setPL(255);
    forward();
  }
}

