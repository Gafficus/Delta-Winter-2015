// This program reads a string from the user and reports back whether 
// or not the string represents a valid two-character state code. 

#include <iostream> 
#include <string> 
using namespace std; 

typedef char stateCode[3]; 

// Global declaration of state code constants 
const stateCode codeList[50]  
         = {"AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "FL", "GA", 
            "HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD", 
            "MA", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ", 
            "NM", "NY", "NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC", 
            "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY"}; 
const int NUMBER_OF_STATES = 50; 
                           
int main() 
{ 
    // Declarations 
    stateCode inCode; 
    bool valid; 
     
    // Prompt for user input 
    cout << "Enter a state code (in caps): "; 
    cin.getline(inCode, 3); 
     
    // Validate code 
    valid = false;                           // Assume an invalid input code 
    for (int i = 0; i < NUMBER_OF_STATES; i++) 
       if ( strcmp(codeList[i],inCode) == 0 ) 
          valid = true;                      // Until detected otherwise 

    // Report result to user 
    cout << inCode; 
    if (valid) 
       cout << " is a valid state code" << endl; 
    else 
       cout << " is not a valid state code." << endl; 
      
     return 0; 
} 

