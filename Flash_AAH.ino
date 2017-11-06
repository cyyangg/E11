//Flash gold codes
#define LED1 13
#define LED2 10
#define LED3 5 
#define gcLength 31
#define INVERT true //set to if(gc[i] == false) for inverse

//set all LEDs to output
void initLight() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}


//flash when gc is true
void flash(boolean gc[gcLength]){
  
  for(int i=0; i<gcLength; ++i)
  {
    long int start = micros();
    
    while(micros() - start < 250){
      if(gc[i] == INVERT) 
      {
        digitalWrite(LED1, 1);
        digitalWrite(LED2, 1);
        digitalWrite(LED3, 1);
        //Serial.print("1");
      }

      else{
        digitalWrite(LED1, 0);
        digitalWrite(LED2, 0);
        digitalWrite(LED3, 0);
        //Serial.print("0");
      }
    }
    
  }

  
}

