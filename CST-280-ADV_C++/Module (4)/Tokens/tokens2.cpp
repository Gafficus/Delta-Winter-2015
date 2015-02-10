// This program demonstrates tokenizing comma-delimited data
// using a string tokenizer class
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "StringTokenizer.h"

void processLine(string inputLine);

//***************************************************************
//***************************************************************
int main()
{ 
    string inputLine;
 
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - -     
    // File initialization
 //   ifstream inFile ("tokenData.txt");
    ifstream inFile ("tokenData.txt");
    
    if (inFile.fail() )         // Test for file existence
    {
      cout <<  "Problem opening file";
      exit(-1);
    }
    
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
    
    // Read and process data file containing coded input info
    getline(inFile,inputLine);                
    while( ! inFile.eof())
    {
        processLine(inputLine);  
        getline(inFile,inputLine);            
    }    
	system("pause");
    return 0;
}

// This function reads and parses a comma-delimited line.  The
// for is:  string,double,string,int
void processLine(string inputLine)
{
    string string1,string2;
    double theDouble;
    int    theInt;
    
    // Instantiate string tokenizer object.  Set to use
    // comma delimiter
    StringTokenizer tokenizer(inputLine,',');
    
    // Access tokens in string in sequence.  Recognize
    // appropriate type and number of tokens.
    string1   = tokenizer.getStringToken();
    theDouble = tokenizer.getDoubleToken();
    string2   = tokenizer.getStringToken();
    theInt    = tokenizer.getIntToken();
 
    // Write results to console
    cout << "First string:  " << string1   << endl;
    cout << "Second string: " << string2   << endl;
    cout << "Decimal value: " << theDouble << endl;
    cout << "Integer value: " << theInt    << endl;
    cout << endl << endl;
    
}
