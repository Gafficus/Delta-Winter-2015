// This program reads a sequence of values from a file and 
// stores them in an array.  It then processes the array to
// calculate the average of the numbers
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_ARRAY = 200;

void getData(ifstream& inFile, int inValues[], int& size);
double getAverage(int inValues[], int size);

int main()
{
    ifstream fileIn;                
    
    int theData[MAX_ARRAY];     // Array for data storage
    int numElems;               // Actual number of values in array 
                                // (1 more than largest index)

    fileIn.open("avedata.txt"); // Open file
    
    if (fileIn.fail() )         // Test for file existence
    {
      cout <<  "Problem opening file";
      exit(-1);
    }
    
    // Read file and count values in array
    getData(fileIn,theData,numElems);
    
   // Determine and write average; test first for non-empty data file   
    if (numElems > 0)
       cout << "Average: " << getAverage(theData,numElems) << endl << endl;
     else
       cout << "ERROR:  No data processed" << endl << endl;

    // Close file
    fileIn.close();    
    
    return 0;                
}

// This function reads integers from a file and stores the values in
// an array.  It returns the loaded array and the number of elements 
// in the array
void getData(ifstream& inFile, int inValues[], int& numVals)
{
    int i = 0;
    inFile >> inValues[i];                
    while (!inFile.eof() && i < MAX_ARRAY)    // Test for end of file and array    
    {
       i++;        
       inFile >> inValues[i];
    }            
    numVals = i;
}

// This function receives an array of integers, calculates the average
// of the array values, and returns it.
double getAverage(int inValues[], int dataSize)
{
    double sum = 0.0;
    
    for (int i = 0; i < dataSize; i++)
       sum = sum + inValues[i];    
       
    return sum / dataSize;
} 
