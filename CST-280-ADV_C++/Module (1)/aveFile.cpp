// This program reads a sequence of values from a file and  
// calculates the average of the numbers 

#include <iostream> 
#include <fstream> 
using namespace std; 

int main() 
{ 
    ifstream fileIn;                // Input file stream identifier 
    double sum,value; 
    int count; 

    fileIn.open("avedata.txt");     // Open file 
     
    if (fileIn.fail() )             // Test for file existence 
    { 
      cout <<  "Problem opening file"; 
      exit(-1); 
    } 

    // Initialize counters 
    sum = 0.0; 
    count = 0; 
     
    fileIn >> value;                // Priming read 
    while (!fileIn.eof())           // While not at end-of-file 
    { 
       sum = sum + value;              // Process data 
       count++;                        // Count number of items 
       fileIn >> value;                // Continuation read 
    } 
     
    // Write average 
    cout << "Average: " << sum / count << endl; 

    fileIn.close();                 // Close file 
     
    return 0;                       // Successful program termination 
} 

