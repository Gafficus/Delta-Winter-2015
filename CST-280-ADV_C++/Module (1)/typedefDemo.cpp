// This program demonstrates usage of the C++ typedef 
// (type definition) construct 

#include <iostream> 
using namespace std; 

typedef char string25[26]; 
typedef int bigArray[10000]; 

int main() 
{ 
   // C-string variables firstName and lastName are of identical data type 
   string25 firstName; 
   char lastName[26]; 
    
   cout << "Enter first name: "; 
   cin.getline(firstName,26); 
    
   cout << "Enter last name: "; 
   cin.getline(lastName,26); 
    
   cout << "Hello " << firstName << " " << lastName << endl << endl; 

   // A variable of type "bigArray" declares a very large array of 
   // integers.  The declaration below is the same as: 
   //     int array1[10000]; 
   bigArray array1; 

   // Initialize array elements to zero 
   for (int i = 0; i < 10000; i++) 
      array1[i] = 0; 
   cout << "Large array initialized" << endl << endl; 

   return 0; 
} 

