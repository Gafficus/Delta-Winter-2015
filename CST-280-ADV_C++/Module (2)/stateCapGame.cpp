// This program implements a state capital guessing game

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

typedef char String40[41];

void getStateData( String40 state[], String40 capital[]);
int randVal(int n);

const int NUMSTATES = 50;

int main()
{
   // Set up for random number processing
   time_t seconds;
   time(&seconds);
   srand( (unsigned int) seconds);

   // Declare parallel arrays
   String40 state[NUMSTATES];      
   String40 capital[NUMSTATES]; 
   String40 userGuess;
   
   bool done = false;     
   
   int index;
   int tries = 0;                // Count how many tries to get answer
  
   getStateData(state,capital); 
   
   // Start game
   index = randVal(NUMSTATES);   // Select random number 1..50
   do
   {   
      // Prompt user
      cout << "What is the capital of " << state[index] << "?" << endl;
      cout << "(Use underscores for any blanks in the work)" << endl;
      
      cin >> userGuess;
      tries++;
      
      if (strcmp(userGuess,capital[index]) == 0)
      {
         cout << "Correct!  It took you " << tries << " tries." << endl << endl;
         done = true;     // Declare game done
      }
      else 
         cout << "Incorrect.  Try again. " << endl;
   
   } while ( ! done );   // Continue while guess incorrect
   
       
   return 0;
}

// --------------------------------------------------------------------------------
// This function builds two parallel arrays from a file of state trivia data.
// File format example line:  "Michigan       MI    Lansing"
// State code (2nd data token) is read, and then ignored
void getStateData( String40 state[], String40 capital[])
{
   String40 stateCode;

   // Input the payroll data file and validate existence.
   ifstream fileIn;
   fileIn.open("stateCaps.txt"); 
    
   if (fileIn.fail() )         
   {
       cout <<  "Problem opening file";
       exit(-1);
   }
    
   // Read data file into parallel arrays
   for (int i = 0; i < NUMSTATES; i++)   
      fileIn >> state[i] >> stateCode >> capital[i];                           
}

// --------------------------------------------------------------------------------
// This function utilizes the C++ random number generator 
// to select a random integer 0 ... n
int randVal(int n)
{
   return rand() % n;
}
