/************************************************************/
/* This program demonstrates functions that insert and      */
/* delete items from an ordered list of integers            */
/* Author:  T. Klingler                                     */
/************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LIST_SIZE = 100;                // Max list size

// Function prototypes
void GetList(int inList[],int& listsize,int maxlistsize);
void DisplayList(int theList[],int listsize);
void OrdListDelete(int list[], int& numElems, int oldint);
void OrdListInsert(int list[], int& numElems, int newint);

int main()
{
    int InList[MAX_LIST_SIZE];      // Array of list elements
    int ListSize;                   // Index of last list element
                                        
    GetList(InList,ListSize,MAX_LIST_SIZE);
    cout << endl << "Initial list:" << endl;
    DisplayList(InList,ListSize);

    OrdListInsert(InList,ListSize,10);    // Insert value of 10
    cout << endl << "After inserting 10:" << endl;
    DisplayList(InList,ListSize);
    
    OrdListDelete(InList,ListSize,13);    // Insert value of 13
    cout << endl << "After deleting 13:" << endl;
    DisplayList(InList,ListSize);
    
    return 0;
}

/************************************************************/
/* This function opens a file to retrieve a list of integer */
/* values.  Values are stored in an array and passed to the */
/* calling routine.                                         */
/************************************************************/
void GetList(int inList[],int& listsize,int maxlistsize)
{
   ifstream InFile ("orderList.txt");
   int ListElement;
    
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
/* This function receives an integer, an array containing   */
/* an ordered list, and the size of the list.  It inserts   */
/* a new integer item at appropriate position in the list.  */
/* Note:  Possibility of array overflow not checked         */
/************************************************************/
void OrdListInsert(int list[], int& numElems, int newint)
{
   // Locate position to insert value at - index ptr
   int ptr = 0;
   while (newint > list[ptr] && ptr < numElems)    
      ptr++;
               
   // Move all successors down one array position:  bottom-up
   for (int i = numElems; i > ptr; i--)
      list[i] = list[i-1];
   
   // Insert net item   
   list[ptr] = newint;
     
   // Adjust number of elements in list  
   numElems++;                                 
}

/************************************************************/
/* This function receives an integer, an array containing   */
/* an ordered list, and the size of the list.  It deletes   */
/* the integer from the list and adjusts the list order     */
/************************************************************/
void OrdListDelete(int list[], int& numElems, int oldint)
{
   // Locate item to delete
   int ptr = 0;
   while (oldint != list[ptr] && ptr < numElems)    
      ptr++;
   
   // Move all successors up one position - deleting target value           
   for (int i = ptr; i < numElems - 1; i++)
      list[i] = list[i+1];
           
   // Adjust number of elements in list  
   numElems--;                                 
} 
