#define DISTANCE 14
#define REFLECT 18
#define PHOTOTRAN 19

void testSensors() {
  pinMode(DISTANCE, INPUT);
  int dist = analogRead(DISTANCE - 14);

  pinMode(REFLECT, INPUT);
  int reflect = analogRead(REFLECT - 14);

  pinMode(PHOTOTRAN, INPUT);
  int photo = analogRead(PHOTOTRAN - 14);

  Serial.println(' ');
  Serial.print("Distance ");
  Serial.print(dist);
  Serial.print("  Reflect ");
  Serial.print(reflect);
  Serial.print("  Photo ");
  Serial.print(photo);
  delay(500);
}

void testPhoto() {
  pinMode(PHOTOTRAN, INPUT);
  int photo = analogRead(PHOTOTRAN - 14);
  
  turnR();

  if(photo < 400) {
    forward();
  }
}

void testRef() { 
  pinMode(REFLECT, INPUT);
  int reflect = analogRead(REFLECT - 14);
  Serial.println(reflect);
  
  forward();
  
  if(reflect > 100) { 
    halt();   
    if(reflect > 150) {
      backward(); 
      delay(200);
      turnR();
      delay(200);
      halt();
    }
  }


  
}

