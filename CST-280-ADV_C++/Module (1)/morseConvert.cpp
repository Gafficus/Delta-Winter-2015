//************************************************************************** 
// This program reads a one-line string from the user.  It then converts the  
// string to its equivalent in Morse code in preparation for transmission as 
// a message.  The message should be in all caps with no punctuation. 
// Author: T. Klingler 
//************************************************************************** 

#include <iostream> 
#include <fstream> 
using namespace std; 

typedef char string30[31]; 
typedef char codeString[5]; 
const int ALPHA_SIZE = 26; 
const char BLANK = ' '; 
const char END_STRING = '\0'; 

// Function protottypes 
void BuildAlphaList(char alpha[], codeString morse[]); 
void printMorse(string30 theString, char alpha[], codeString morse[]); 

int main() 
{     
    string30 inString;           // Input string from user 
    char alphaList[26];          // Array containing alphabet (all caps) 
    codeString MorseList[26];    // Array of morse code pattern  
     
    // Build arrays from file 
    BuildAlphaList(alphaList,MorseList); 
     
    // Prompt user for input string and read 
    cout << "Enter string (30 characters or less - all CAPS)" << endl; 
    cin.getline(inString,31); 
         
    // Print Morse code pattern 
    printMorse(inString,alphaList,MorseList); 
     
    return 0; 

}  // end main 

//************************************************************************** 
// This function builds arrays containing the alphabet and matching 
// Morse code pattern.  No file checking is performed. 
//************************************************************************** 
void BuildAlphaList(char alpha[], codeString morse[]) 
{ 
    ifstream inFile("morse.txt");            // Open file  
     
    for (int i=0; i < ALPHA_SIZE; i++) 
        inFile >> alpha[i] >> morse[i]; 
         
}  // end BuildAlphaList 

//************************************************************************** 
// This function builds arrays containing the alphabet and matching 
// Morse code pattern. 
//************************************************************************** 
void printMorse(string30 theString, char alpha[], codeString morse[]) 
{ 
    int currChar = 0;                // Point to first character in string 
     
    while (theString[currChar] != END_STRING) 
    { 
        if (theString[currChar] != BLANK) 
        { 
            // Search for character in alphabet array 
            for (int i=0; i < ALPHA_SIZE; i++) 
                if (alpha[i] == theString[currChar]) 
                    cout << morse[i] << endl; 
        } 
        else 
            cout << endl;            // For blanks, print blank line 

        currChar++;                  // Go to next character in string 
    } 

}  // end printMorse 

