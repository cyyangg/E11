void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting...");

}

void loop() {
  
  followLine();
  //testSensors();
  
}
