#define gcLength 31

boolean gc5[gcLength] = {0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,1,1,1,0,1,0,0,1,1,1};
boolean gc6[gcLength] = {1,1,1,0,0,0,1,0,0,1,1,0,1,1,1,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0};
boolean gc7[gcLength] = {0,1,1,0,0,1,1,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,1,0};
boolean gc8[gcLength] = {1,0,0,1,0,1,1,1,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,0,0,1,0,0,0,1,1};
boolean gc9[gcLength] = {0,0,0,1,0,0,1,1,1,1,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,1};


void setup() {
  Serial.begin(9600);
  Serial.println("IT'S THE FINAL COUNTDOWN.");
  initLight();    //activate lights

  forward();
  delay(600);
  halt();
  delay(200);
  turnL();
  delay(70);
  halt();
  delay(500);
}

void loop() {
  flash(gc5); 
  flash(gc5);
  followBlack();
  flash(gc6);
  flash(gc6);
  followBlack();
  flash(gc7);
  flash(gc7);
  followBlack();
  flash(gc8);
  flash(gc8);
  followBlack();
  flash(gc9);
  flash(gc9); 
  //testSensors();
  followBlack();

}
