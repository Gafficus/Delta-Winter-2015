/************************************************************/
/* This program demonstrates a bubble sort algorithm        */
/* to sort an unordered list read in from a data file       */
/* Author:  T. Klingler                                     */
/************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LIST_SIZE = 100;      // Max list size
                                    // (for array declaration)
// Function prototypes
void GetList(int inList[],int& listsize,int maxlistsize);
void sortArray(int array[], int elems);
void DisplayList(int theList[],int listsize);

int main()
{
    int    InList[MAX_LIST_SIZE];  // Array of list elements
    int ListSize;                  // Index of last list element
                                        
    GetList(InList,ListSize,MAX_LIST_SIZE);
    
    // Write list prior to sort
    cout << endl << "BEFORE" << endl;
    DisplayList(InList,ListSize);
    
    sortArray(InList,ListSize);
    
    // Write list after sort
    cout << endl << "AFTER" << endl;
    DisplayList(InList,ListSize);
    
    return 0;
}

/************************************************************/
/* This function opens a file to retrieve a list of values  */
/* of a generic type.  Values are stored in an array and    */
/* passed to the calling routine.                           */
/*   Parameters:                                            */
/*        list            array of integers to build        */
/*        listsize        number of elements in list)       */
/*        maxlistsize     max size allowable for list array */
/*   Requires:                                              */
/*        Global type definition of int                     */
/************************************************************/
void GetList(int inList[],int& listsize,int maxlistsize)
{
    ifstream InFile ("listData.txt");
    
    int i = 0;
    InFile >> inList[i];
    while( !InFile.eof() && i < maxlistsize)
    {
        i++;
        InFile >> inList[i];
    }
    listsize = i;        // Size of list is lastindex + 1
}

/************************************************************/
/* This function writes a list to console output:  one list */
/* item at a time.                                          */
/************************************************************/
void DisplayList(int theList[],int listsize)
{
    for (int i = 0;i < listsize; i++)
        cout << theList[i] << " ";
    cout << endl;
}

/************************************************************/
/* This function receives a list of values of type int      */
/* as an array.  The function performs a bubble sort and    */
/* returns the list in ascending order.                     */
/* Note:  elems is number of elements in list               */
/************************************************************/
void sortArray(int array[], int elems)
{
    int temp, end;

   for (end = elems - 1; end >= 0; end--)
   {
       for (int count = 0; count < end; count++)
       {
          if (array[count] > array[count + 1])
          {
             temp = array[count];
             array[count] = array[count + 1];
             array[count + 1] = temp;
          }
       }
   }
}
