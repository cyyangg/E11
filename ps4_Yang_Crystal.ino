//Crystal Yang
//cyang@hmc.edu
//Due 10/11/2017
//Gold codes Correlation 
//took 5 hours

/*PLEASE READ: for some reason, arduino only prints out 23 correlations before looping back.
I tried my best but I couldn't see what in my code was causing this error so I assume
there's some restraint in arduino that I don't know about how many calculations I can do at a time.
Therefore I split the calculated correlations into 4 different 4 loops. 
Altogether they should produce the accurate correlations.
Please only run one calculation at a time */


#define numRegisters 5
#define numGoldCodes 8
#define gcLength 31
#define corrs 36

boolean seed1[numRegisters] = {0,0,0,0,1};
boolean seeds[numGoldCodes][numRegisters] = {{0,0,0,0,1},{0,0,0,1,0}, {0,0,0,1,1},{0,0,1,0,0}, {0,0,1,0,1},{0,0,1,1,0}, {0,0,1,1,1},{0,1,0,0,0}};
boolean poly1[numRegisters] = {0,1,1,1,1};
boolean poly2[numRegisters] = {0,0,1,0,1};
boolean Q1[numRegisters] = {0,0,0,0,0};
boolean Q2[numRegisters] = {0,0,0,0,0};
boolean D1, D2;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting.");

//PLEASE ONLY RUN ONE 'calculate' FUNCTION AT A TIME
//  calculate1();
//  calculate2();
  calculate3();
//  calculate4();  
} 

void loop()
{

}

//calculates the correlations of i from 0 to 3 and j from 0 to 3
void calculate1()
{
  for(int i=0; i<4; ++i)
  {
    for(int j=0; j<4; ++j)
    {
      
      Serial.println(' ');
      Serial.println(' ');
      Serial.print("correlation GC ");
      Serial.print(i); 
      Serial.print(", ");
      Serial.println(j);
      correlation(getGC(Q1, Q2, seeds, i, new boolean[gcLength]), getGC(Q1, Q2, seeds, j, new boolean[gcLength]));
      
    } 
  }
}

//calculates the correlations of i from 0 to 3 and j from 4 to 7
void calculate2()
{
   for(int i=0; i<4; ++i)
  {
    for(int j=4; j<8; ++j)
    {
      
      Serial.println(' ');
      Serial.println(' ');
      Serial.print("correlation GC ");
      Serial.print(i); 
      Serial.print(", ");
      Serial.println(j);
      correlation(getGC(Q1, Q2, seeds, i, new boolean[gcLength]), getGC(Q1, Q2, seeds, j, new boolean[gcLength]));
      
    } 
  }
}

//calculates the correlations of i from 4 to 7 and j from 0 to 3
void calculate3()
{
  for(int i=4; i<8; ++i)
  {
    for(int j=0; j<4; ++j)
    {
      
      Serial.println(' ');
      Serial.println(' ');
      Serial.print("correlation GC ");
      Serial.print(i); 
      Serial.print(", ");
      Serial.println(j);
      correlation(getGC(Q1, Q2, seeds, i, new boolean[gcLength]), getGC(Q1, Q2, seeds, j, new boolean[gcLength]));
      
    } 
  }
}

//calculates the correlations of i from 4 to 7 and j from 4 to 7
void calculate4()
{
  for(int i=4; i<8; ++i)
  {
    for(int j=4; j<8; ++j)
    {
      
      Serial.println(' ');
      Serial.println(' ');
      Serial.print("correlation GC ");
      Serial.print(i); 
      Serial.print(", ");
      Serial.println(j);
      correlation(getGC(Q1, Q2, seeds, i, new boolean[gcLength]), getGC(Q1, Q2, seeds, j, new boolean[gcLength]));
      
    } 
  }
}

//This function will correlate 2 gold codes then shift second of the gcs
//and make and print an array of all the correlate values
//it will return the max of the correlates
int correlation(boolean p1[gcLength], boolean p2[gcLength])
{
  //array of the correlations
  int sums[gcLength];
  int largest = 0;
  
  for(int i=0; i<gcLength; i++)
  {  
    sums[i] = correlate(p1, p2);
    wrap(p2);  
    Serial.print(sums[i]);
    Serial.print(' ');
  }

  for(int i=0; i<gcLength; i++)
  {
    if(abs(sums[i])>abs(largest))
    {
      largest = sums[i];
    }
  }
  
  Serial.println(' ');
  Serial.print("MAX: ");
  Serial.println(largest);
  return largest;
}

//This function will compare two different gold codes and return the correlation value 
//-1 if the digits don't match, +1 if they do
int correlate(boolean p1[gcLength], boolean p2[gcLength])
{
  int cor;

  for(int i=0; i<gcLength; i++)
  {
    if(p1[i] == p2[i])
    {
      ++cor;
    }
    else --cor;
  }
  return cor;
  
}


//This function shifts the gc over by one
//last index wraps around and becomes the zeroth index
void wrap(boolean p[gcLength])
{
  boolean temp[gcLength];
  int last = p[gcLength-1];
  
  //set temp array to p array
  for(int i=0; i<gcLength; i++)
  {
    temp[i] = p[i];
  }
  
  //shift everything over by one
  for(int i=1; i<gcLength; i++)
  {
    p[i] = temp[i-1];
  }

  //set zeroth index to initial last digit
  p[0] = last;

}




// This function will calculate 1 gold code using the two polynomials and seeds
// Of the 8 gold codes to generate, it will calculate number "gcIndex"
boolean* getGC(boolean p1[numRegisters], boolean p2[numRegisters], boolean s[numGoldCodes][numRegisters], int gcIndex, boolean gc[gcLength])
{

  // Initialize D1 and D2 to be 1 here

  D1 = 1;
  D2 = 1;
   
  // Initialize the values of all the register bits in Q1 and Q2
  // to be the appropriate seeds from variables seed1 and seeds
  for (int i=0; i<numRegisters; i++)
  {
    Q1[i] = seed1[i];
    Q2[i] = seeds[gcIndex][i]; 
  }
  
  
  
  // Run through all steps of shifting 
  // i.e. use a for loop on gcSize
  for(int i=0; i<gcLength; ++i)
  {
    // Set the i^th bit in the gold code to be the XOR of last two bits of Q1 and Q2
    gc[i] = XOR(Q1[4], Q2[4]);

    // Step all registers for both polynomials by calling the stepRegisters() function
    stepRegisters();
     
  }
  
  return gc;

  
}

void stepRegisters()
{

  // Calculate the values of D1 based on the 
  // XOR of the registers in Q1 and the polynomial poly1
  // defining which registers are fed back. Then do the same for D2 
  // These should call the feedbackXOR() function.
  
  D1 = feedbackXOR(Q1, poly1);
  D2 = feedbackXOR(Q2, poly2);
  boolean temp1[numRegisters] = {0,0,0,0,0};
  boolean temp2[numRegisters] = {0,0,0,0,0};

  for(int i=0; i<numRegisters; i++)
  {
    temp1[i] = Q1[i];
    temp2[i] = Q2[i];
  }
  

  // Use a for loop to countdown through all the registers,
  // to set up the shifting 
  for (int i=1; i<numRegisters; i++)
  {
    // Shift, by setting each value of Q1[i], Q2[i] to the value
    // of Q1[i-1], Q2[i-1] respectively.
    Q1[i] = temp1[i-1];
    Q2[i] = temp2[i-1];
  }
  
  // Set the first value in Q1 and Q2 to be D1 and D2 respectively
  Q1[0] = D1;
  Q2[0] = D2;
}


// Input two arrays of booleans and output the XOR of them
int feedbackXOR(boolean p[numRegisters], boolean r[numRegisters])
{ 
  int sum = 0;
  // Loop through all the registers, starting at index 1
  for(int i=1; i<numRegisters; ++i)
  {
    // Increase the sum if both r[i] and p[i] are true
    if(r[i] && p[i])
    {
      ++sum;
    }
  }
 
  // If the sum is odd, return true
  // else, return false 
  if(sum%2 == 1)
  {
    return true;
  }
  else return false;
}


// Input two booleans and return the XOR of them
boolean XOR(boolean a, boolean b)
{
 
 // Return false if both a and b are the same value,
 // otherwise return true. 
 if(a == b) {
  return false;
 }
 else return true;

}
