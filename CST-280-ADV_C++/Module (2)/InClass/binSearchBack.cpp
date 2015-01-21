// This program performs an experiment to demonstrate the relative
// efficiency of the binary search versus the linear search.  The
// number of comparisons (if statements) performed for each search
// is counted as a measure of the "work" performed

// In this experiment, the list is sorted in a descending order.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
int binarySearch(int array[], int numelems, int value);
int searchList(int list[], int numElems, int value);
int randomValue(int range);

const int ARRAY_SIZE = 100;
const int NUM_TESTS  = 5;

int main()
{
    int list[ARRAY_SIZE] 
        = {100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,
           80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,
           60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,
           40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,
           20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int target, testReturn;
    
    // Set random number seed to current time
    time_t seconds;
    time(&seconds);
    srand( (unsigned int) seconds);
    
    for (int i = 1; i <= NUM_TESTS; i++)
    {
        // Get search value
        target = randomValue(ARRAY_SIZE);
        cout << "Search target: " << target << endl;
        
        // Perform linear search
        testReturn = searchList(list, ARRAY_SIZE, target);
        cout << "LinSearch - Found at position: " << testReturn << endl;
        
        // Perform binary search
        testReturn = binarySearch(list, ARRAY_SIZE, target);
        cout << "BinSearch - Found at position: " << testReturn << endl << endl;
    }
	system("pause");
    return 0;
}

//*****************************************************************
// The searchList function performs a linear search on an         *
// integer array. The array list, which has a maximum of numElems *
// elements, is searched for the number stored in value. If the   *
// number is found, its array subscript is returned. Otherwise,   *
// -1 is returned indicating the value was not in the array.      *
//*****************************************************************
int searchList(int list[], int numElems, int value)
{
    int index = numElems;            // Used as a subscript to search array
    int position = -1;        // To record position of search value
    bool found = false;       // Flag to indicate if the value was found

    while (index > 0 && !found)
    {
        if (list[index] == value)    // If the value is found
        {
            found = true;            // Set the flag
            position = index;        // Record the value's subscript
        }
        index--;                     // Go to the next element
    }
    return position;                 // Return the position, or -1
}

//***************************************************************
// The binarySearch function performs a binary search on an     *
// integer array. array, which has a maximum of numelems        *
// elements, is searched for the number stored in value. If the *
// number is found, its array subscript is returned. Otherwise, *
// -1 is returned indicating the value was not in the array.    *
//***************************************************************
int binarySearch(int array[], int numelems, int value)
{
    int first = 0,                 // First array element
        last = numelems - 1,       // Last array element
        middle,                    // Mid point of search
        position = -1;             // Position of search value
    bool found = false;            // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2;     // Calculate mid point
        if (array[middle] == value)      // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (array[middle] < value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;          // If value is in upper half
    }
    return position;
}

// This function returns a random number selected between 1 and the
// given range passed in as a parameter
int randomValue(int range)
{
    return rand() % range + 1;
}
