// This program reads a sentence and counts the number of vowels 
// included. 

int countVowels(char sentence[]); 

#include <iostream> 
using namespace std; 

int main() 
{ 
   char aSentence[81];            // Max sentence size:  80 char                

   // Input 
    cout << "Enter a sentence:" << endl; 
    cin.getline(aSentence,81); 

   // Output 
   cout << "Sentence: " << endl; 
   cout << aSentence    << endl; 
   cout <<"has " << countVowels(aSentence) 
        << " vowels" << endl << endl; 
         
   return 0; 
} 

// This function reads a sentence (up to 80 characters long), counts 
// the number of vowels included, and returns the count 
int countVowels(char sentence[]) 
{ 
    char vowelSet[] = {'a','e','i','o','u','A','E','I','O','U','\0'}; 
    int vowels; 
    int i, j; 
     
    vowels = 0; 
    i = 0; 
    while (sentence[i] != '\0')         
    { 
      j = 0; 
      while (vowelSet[j] != '\0') 
      { 
         if (sentence[i] == vowelSet[j]) 
            vowels++;     
         j++; 
      }         
      i++;                 
    } 
         
   return vowels;                  
} 

