// This file includes implementations of functions for managing
// an ordered list

#include<iostream>
#include<fstream>
using namespace std;

#include "ItemType.h"
#include "ListType.h"

//***********************************************************
// This function opens a file to retrieve a list of ItemType 
// values.  Values are stored in an array and passed to the
// calling routine.                                         
//***********************************************************
void GetList(char inFileName[], ItemType inList[],
             int& listsize, int maxlistsize)
{
   ifstream InFile (inFileName);
   ItemType ListElement;
    
   int i = 0;
   InFile >> ListElement;
   while( !InFile.eof() && i < maxlistsize)
   {
      inList[i] = ListElement;
      i++;
      InFile >> ListElement;
   }
   listsize = i;     // Size of list is number of elements
}

//***********************************************************
// This function writes a list to console output:  one list 
// item at a time.                                          
//***********************************************************
void DisplayList(ItemType theList[],int listsize)
{
   for (ItemType i = 0;i < listsize; i++)
      cout << theList[i] << " ";
   cout << endl;
}

//***********************************************************
// This function receives an ItemTypeeger, an array containing   
// an ordered list, and the size of the list.  It inserts    
// a new item at appropriate position in the list.  
// Note:  Possibility of array overflow not checked         
//***********************************************************
void OrdListInsert(ItemType list[], int& numElems, ItemType newItemType)
{
   // Locate position to insert value at - index ptr
   ItemType ptr = 0;
   while (newItemType > list[ptr] && ptr < numElems)    
      ptr++;
               
   // Move all successors down one array position:  bottom-up
   for (ItemType i = numElems; i > ptr; i--)
      list[i] = list[i-1];
   
   // Insert net item   
   list[ptr] = newItemType;
     
   // Adjust number of elements in list  
   numElems++;                                 
}

//***********************************************************
// This function receives an ItemTypeeger, an array containing   
// an ordered list, and the size of the list.  It deletes   
// the item from the list and adjusts the list order     
//***********************************************************
void OrdListDelete(ItemType list[], int& numElems, ItemType oldItemType)
{
   // Locate item to delete
   ItemType ptr = 0;
   while (oldItemType != list[ptr] && ptr < numElems)    
      ptr++;
   
   // Move all successors up one position - deleting target value           
   for (ItemType i = ptr; i < numElems - 1; i++)
      list[i] = list[i+1];
           
   // Adjust number of elements in list  
   numElems--;                                 
}

//***************************************************************
// The binarySearch function performs a binary search on an     *
// array. The array, which has a maximum of numelems            *
// elements, is searched for the number stored in value. If the *
// number is found, its array subscript is returned. Otherwise, *
// -1 is returned indicating the value was not in the array. *
//***************************************************************
int binarySearch(ItemType array[], int numelems, ItemType value)
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
        else if (array[middle] > value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;          // If value is in upper half
    }
    return position;
} 
