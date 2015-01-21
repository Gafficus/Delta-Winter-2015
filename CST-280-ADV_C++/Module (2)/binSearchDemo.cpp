/************************************************************/
/* This program demonstrates a binary search algorithm      */
/* to verify the manual trace of the search algorithm       */
/* This program if for demonstration purposes only and      */
/* includes some poor programming practices.                */
/* Author:  T. Klingler                                     */
/************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

const int FAILED_SEARCH = -1;        // Binary search return for failed search
const int MAX_LIST_SIZE = 100;       // Max list size
                                     // (for array declaration)
// Function prototypes
int binarySearch(int array[], int numelems, int value);

int main()
{
    int InList[] = {12,26,34,57,61,76,84,91,102,130}; // Array of list elements
    int ListSize = 10;                                // Number of elements in list
    int itemFound;                                    // Item postiion in list

    // Print array for demo
    cout << "The Array: " << endl;
    for (int i = 0; i < ListSize; i++)
        cout << InList[i] << " ";
    cout << endl << endl;
                                        
    // Perform binary search for 102
    itemFound = binarySearch(InList, ListSize, 102);
    if (itemFound != FAILED_SEARCH)
        cout << "List element " << 102 << " found at index " << itemFound << endl;
    else
        cout << "List element " << 102 << " not in list" << endl;
    cout << endl << endl;
                                        
    // Perform binary search for 29
    itemFound = binarySearch(InList, ListSize, 29);
    if (itemFound != FAILED_SEARCH)
        cout << "List element " << 29 << " found at index " << itemFound << endl;
    else
        cout << "List element " << 29 << " not in list" << endl;
    cout << endl << endl;
    
    return 0;
}

//***************************************************************
// The binarySearch function performs a binary search on an     *
// integer array. array, which has a maximum of numelems        *
// elements, is searched for the number stored in value. If the *
// number is found, its array subscript is returned. Otherwise, *
// -1 is returned indicating the value was not in the array. *
//***************************************************************
int binarySearch(int array[], int numElems, int value)
{
    int first = 0,              // First array element
    last = numElems - 1,        // Last array element
    middle,                     // Mid point of search
    position = -1;              // Position of search value
    bool found = false;         // Flag:  false until found

    cout << "Searching for: " << value << endl;
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;     // Calculate mid point

        // WRITE VALUES OF ALGORITHM INDEXES
        cout << "   first: "  << first 
             << "   middle: " << middle 
             << "   last: "   << last    << endl;
        
        if (array[middle] == value)      // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;          // If value is in upper half
    }
    
    // WRITE VALUES OF ALGORITHM INDEXES AT RETURN
    cout << "At return: " 
         << "   first: "  << first 
         << "   middle: " << middle 
         << "   last: "   << last    << endl;
 
    return position;
} 
