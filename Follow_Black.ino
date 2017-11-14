//drive forward until it reaches black circle
//then drives the perimeter of the circle

#define REFLECT 18

#define WHITE 600
#define BLACK 750

void followBlack() {
  //activate motors
  initMotors();

  //read reflect value
  pinMode(REFLECT, INPUT);
  int reflect = analogRead(REFLECT - 14);
  
  
  //if on white, turn right to find line
  if(reflect < WHITE) 
  {
    setPL(75);
    turnR();

  }

  //if on black, go forward
  else if(reflect > BLACK)
  {

    setPL(200);
    slightR();
   
  }

}

