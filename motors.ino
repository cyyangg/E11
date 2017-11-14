#define LPLUS 9
#define LMINUS 8
#define RPLUS 7
#define RMINUS 12
#define LEN 6
#define REN 11

int powerLevel = 255;


//declare relevant pins as output, make sure robot is stopped
void initMotors() {
  pinMode(LEN, OUTPUT);
  pinMode(LPLUS, OUTPUT);
  pinMode(LMINUS, OUTPUT);

  pinMode(REN, OUTPUT);
  pinMode(RPLUS, OUTPUT);
  pinMode(RMINUS, OUTPUT);
}


//stops all motors
void halt() {
  digitalWrite(LEN, 0);
  digitalWrite(LPLUS, 0);
  digitalWrite(LMINUS, 0); 

  digitalWrite(REN, 0);
  digitalWrite(RPLUS, 0);
  digitalWrite(RMINUS, 0);
}


//drive forward indefinitely
void forward() {
  digitalWrite(LEN, 1);
  analogWrite(LPLUS, powerLevel);
  digitalWrite(LMINUS, 0);

  digitalWrite(REN, 1);
  analogWrite(RPLUS, powerLevel);
  digitalWrite(RMINUS, 0);
}


//drive backwards indefinitely
void backward() {
  digitalWrite(LEN, 1);
  digitalWrite(LPLUS, 0);
  analogWrite(LMINUS, powerLevel);
  
  digitalWrite(REN, 1);
  digitalWrite(RPLUS, 0);
  analogWrite(RMINUS, powerLevel);
}


//turn left indefinitely
void turnL() {
  digitalWrite(LEN, 1);
  digitalWrite(LPLUS, 0);
  analogWrite(LMINUS, powerLevel);
  
  digitalWrite(REN, 1);
  analogWrite(RPLUS, powerLevel);
  digitalWrite(RMINUS, 0);
}


//turn right indefinitely
void turnR() {
  digitalWrite(LEN, 1);
  analogWrite(LPLUS, powerLevel);
  digitalWrite(LMINUS, 0);
  
  digitalWrite(REN, 1);
  digitalWrite(RPLUS, 0);
  analogWrite(RMINUS, powerLevel);
}


//slightly turn right
void slightR() {
  digitalWrite(LEN, 1);
  analogWrite(LPLUS, powerLevel-75);
  digitalWrite(LMINUS, 0);
  
  digitalWrite(REN, 1);
  digitalWrite(RPLUS, powerLevel);
  analogWrite(RMINUS, 0);
}


//set power level, 255 max speed
//note: power levels under around 220 start turning towards the left
void setPL(int pl) {
  powerLevel = pl;
}


