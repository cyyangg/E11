//Crystal Yang
//cyang@hmc.edu
//Due 10/4/2017
//Gold codes
//took 5 hours

#define numRegisters 5
#define numGoldCodes 8
#define gcLength 31

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

  
  // loop 8 times to create the 8 gold codes
  for(int i=0; i<8; ++i)
  {
    
    // Call getGC to create the 8 goldcodes
    // send GC, the two polynomials poly1 and poly2 that
    // determine the feedback registers, as well as the
    // 8 different seeds and the index for which GC you
    // are creating 
    getGC(Q1, Q2, seeds, i);
    Serial.println("");
  }
} 

void loop()
{

}

// This function will calculate 1 gold code using the two polynomials and seeds
// Of the 8 gold codes to generate, it will calculate number "gcIndex"
boolean getGC(boolean p1[numRegisters], boolean p2[numRegisters], boolean s[numGoldCodes][numRegisters], int gcIndex)
{
  // Determine size of gold code
  //int gcSize = pow(2,numRegisters)-1;// 2^numRegisters - 1;

  // Create an array to store the goldcode
  boolean gc[gcLength];  
 
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
  for(int i=0; i<gcLength; i++)
  {
    // Set the i^th bit in the gold code to be the XOR of last two bits of Q1 and Q2
    gc[i] = XOR(Q1[4], Q2[4]);

    // Step all registers for both polynomials by calling the stepRegisters() function
    stepRegisters();
 
    // Print the gc to the screen
    Serial.print(gc[i]);
    
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
