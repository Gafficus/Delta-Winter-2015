// This program performs an experiment to demonstrate the relative
// efficiency of the binary search versus the linear search.  The
// number of comparisons (if statements) performed for each search
// is counted as a measure of the "work" performed

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
void GenerateArray(int theList[]);
int binarySearch(int array[], int value);
int searchList(int list[], int value);
int randomValue(int range);

const int ARRAY_SIZE = 100000;
const int NUM_TESTS  = 1000;

// Global variables used as counters for experiment
int numTestsLin = 0;    // To count number of tests for linear search
int numTestsBin = 0;    // To count number of tests for binary search

int main()
{
    int list[ARRAY_SIZE];
    int target, testReturn;
    
    // Set random number seed to current time
    time_t seconds;
    time(&seconds);
    srand( (unsigned int) seconds);

GenerateArray(list);
    
    for (int i = 1; i <= NUM_TESTS; i++)
    {
        // Get search value
        target = randomValue(ARRAY_SIZE);
        
        // Perform linear search
        testReturn = searchList(list, target);
        
        // Perform binary search
        testReturn = binarySearch(list, target);
    }

    cout << "Average comparisons for:" << endl;
    
    cout << "Linear search: " << numTestsLin/double(NUM_TESTS) << endl;
    cout << "Binary search: " << numTestsBin/double(NUM_TESTS) << endl;


    return 0;
}

//*****************************************************************
// This function generates a basic array with data                *
// data 1,2,3, ..., (ARRAY_SIZE) to be used in this simulation.   *
//*****************************************************************
void GenerateArray(int theList[])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
theList[i] = i+1;
}


//*****************************************************************
// The searchList function performs a linear search on an         *
// integer array. The array list, which has a maximum of numElems *
// elements, is searched for the number stored in value. If the   *
// number is found, its array subscript is returned. Otherwise,   *
// -1 is returned indicating the value was not in the array. *
//*****************************************************************
int searchList(int list[],int value)
{
    int index = 0;            // Used as a subscript to search array
    int position = -1;        // To record position of search value
    bool found = false;       // Flag to indicate if the value was found

    while (index < ARRAY_SIZE && !found)
    {
        numTestsLin++;               // <=== INCREMENT COMPARISION COUNTER
        if (list[index] == value)    // If the value is found
        {
            found = true;            // Set the flag
            position = index;        // Record the value's subscript
        }
        index++;                     // Go to the next element
    }
    return position;                 // Return the position, or -1
}

//***************************************************************
// The binarySearch function performs a binary search on an     *
// integer array. array, which has a maximum of numelems        *
// elements, is searched for the number stored in value. If the *
// number is found, its array subscript is returned. Otherwise, *
// -1 is returned indicating the value was not in the array. *
//***************************************************************
int binarySearch(int array[], int value)
{
    int first = 0,                 // First array element
        last = ARRAY_SIZE - 1,     // Last array element
        middle,                    // Mid point of search
        position = -1;             // Position of search value
    bool found = false;            // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2;     // Calculate mid point
        if (array[middle] == value)      // If value is found at mid
        {
            numTestsBin++;               // <=== INCREMENT COMPARISION COUNTER
            found = true;
            position = middle;
        }
        else if (array[middle] > value)  // If value is in lower half
        {
            numTestsBin++;               // <=== INCREMENT COMPARISION COUNTER
            last = middle - 1;
        }
        else
            first = middle + 1;          // If value is in upper half
    }
    return position;
}

// This function returns a random number selected between 1 and the
// given range passed in as a parameter
int randomValue(int range)
{
    return (rand() * rand()) % range + 1;
} 
