// This file implements member functions for the integer list 
// class.  The insert and delete operations assume an unordered
// list.

#include <iostream>
#include <fstream>
using namespace std;

#include "intList.h"

/************************************************************/
/* List constructor - set list size to zero                 */
/************************************************************/
IntList::IntList()
{
    size = 0;
}

/************************************************************/
/* This method receives a file name and builds the list     */
/* from the file.  The list size is adjusted appropriately. */
/* Precondition: File exists and is valid.                  */
/************************************************************/
int IntList::BuildList(char file[])
{
    ifstream InFile;            // Input file identifier   
    InFile.open(file);          // Open file     
    
    int count = 0;              // Start index at first array value
    InFile >> list[count];      // Priming read
    while( ! InFile.eof() )
    {
        count++;                // Increment counter for list index
        InFile >> list[count];  // Continuation read
    }
    
    size = count;               // Count is number of elements in list (last_index+1)
    
    return 0;                   // Return good code
}

/************************************************************/
/* This method receives an integer and adds it to the end   */
/* of the list                                              */
/************************************************************/
void IntList::ListInsert(int newint)
{
    list[size] = newint;        // Add new integer to next index of list
    size++;                     // Increment size of list
}

/************************************************************/
/* This method performs a linear search on the integer list.*/
/*   The list position (index) is returned if the item is   */
/*   found (0.. size -1)                                    */
/*     If item not in list, a value of -1 is returned.      */
/************************************************************/
int IntList::ListSearch(int item)
{
    int index = 0;
    int found = -1;              // Assume item will not be found
    while (index < size && item != list[index])
        index++;
    if (index < size)
        found = index;           // If found, 
    return found;                //     return index value
}

/************************************************************/
/* This method receives an integer and deletes if from the  */
/* list.  The list size is decremented                      */
/************************************************************/
void IntList::ListDelete(int badint)
{
    int whereIndex = ListSearch(badint);    // Search list for item to delete
    if (whereIndex >= 0)
    {
        list[whereIndex] = list[size-1];    // Move last list element
        size--;                             //  to position of item to delete
    }                                       //  Decrement list size
}            

/************************************************************/
/* This method returns the current size of the list.        */
/************************************************************/
int IntList::ListSize()
{
    return size;
}            

/************************************************************/
/* This method performs a bubble sort on the integer list.  */
/*The sort is ASCENDING.  Nothing is returned.              */
/************************************************************/
void IntList::SortList()
{
    int            placePtr;    // Index for comparing adjacent elements
    int            endIndex;    // Index of stopping point for one pass
    int            temp;        // Needed for swapping contents

   for (endIndex = size - 1; endIndex >= 0; endIndex--)
   {
       for (placePtr = 0; placePtr < (size - 1); placePtr++)
       {
          if (list[placePtr] > list[placePtr + 1])
          {
             temp = list[placePtr];
             list[placePtr] = list[placePtr + 1];
             list[placePtr + 1] = temp;
          }
       }
   }
}            

/************************************************************/
/* This method prints the contents of the list                */
/************************************************************/
void IntList::PrintList()
{
    cout << "List elements: ";
    for (int i = 0; i < size; i++)
        cout << list[i] << "  ";
    cout << endl;
}            

