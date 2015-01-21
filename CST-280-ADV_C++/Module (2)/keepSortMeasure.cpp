/************************************************************/
// This program measures the amount of algorithm "work" beging
// performed for ordered list insertion.  Competing are 
//  1) Insert onto end of list and sort (bubble sort)
//  2) Insert in order as you go
//  3) Insert all onto beginning of list and sort once
// 100 values 1...1000 are selected at random and are inserted
// into a list without duplication.  Both "comparisions" and
// "assignments" are counted in the experiment.
/************************************************************/
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

const int LIST_ARRAY_SIZE = 100;    // Max list size
const int NUMRANGE        = 1000;   // Range of numbers picked randomly

// GLOBAL VARIABLES (for this demo only to more easily count
// required measurement parameters.
int compares1 = 0;
int assigns1  = 0;
int compares2 = 0;
int assigns2  = 0;
int compares3 = 0;
int assigns3  = 0;

// Function prototypes
void OrdListInsert(int list[], int& numElems, int newint);
void sortArray2(int array[], int elems);
void sortArray3(int array[], int elems);
void UnOrdInsert2(int list[], int& numElems, int newint);
void UnOrdInsert3(int list[], int& numElems, int newint);
int randomValue(int range, bool usedValue[]);

int main()
{
    int list1[LIST_ARRAY_SIZE];
    int list2[LIST_ARRAY_SIZE];
    int list3[LIST_ARRAY_SIZE];
    int ListSize1 = 0;
    int ListSize2 = 0;
    int ListSize3 = 0;
    
    // Set random number seed to current time
    time_t seconds;
    time(&seconds);
    srand( (unsigned int) seconds);

    // Set up marker array (needed to prevent duplication
    // of random numbers).
    bool usedValue[NUMRANGE];
    for (int i=0; i < NUMRANGE; i++)
      usedValue[i] = false;
    
    int valToAdd;
     
    for (int i = 0; i < LIST_ARRAY_SIZE; i++)
    {
        // Pick random value
        valToAdd = randomValue(NUMRANGE,usedValue);
        
        // Test 1: Insert into ordered list
        OrdListInsert(list1,ListSize1,valToAdd);  
         
        // Test 2: Insert into unordered list and sort
        UnOrdInsert2(list2,ListSize2,valToAdd);  
        sortArray2(list2,ListSize2);  
         
        // Test 3: Insert into unordered list
        UnOrdInsert3(list3,ListSize3,valToAdd);  
    }
     
    // Test 3: Sort once after unordered inserts complete
    sortArray3(list3,ListSize3);  

    cout << "Summary:" << endl << endl;
    
    cout << "Test1 (insert ordered list as you go): "  << endl;
    cout << "Assignments: " << assigns1 << "  ";
    cout << "Comparisons: " << compares1 << endl << endl;
    
    cout << "Test2 (insert at list end and sort): "  << endl;
    cout << "Assignments: " << assigns2 << "  ";
    cout << "Comparisons: " << compares2 << endl << endl;
    
    cout << "Test3 (insert at list end; sort once after): "  << endl;
    cout << "Assignments: " << assigns3 << "  ";
    cout << "Comparisons: " << compares3 << endl << endl;

    return 0;
}


/************************************************************/
/* This function receives an integer, an array containing   
/* an ordered list, and the size of the list.  It inserts   
/* a new integer item at appropriate position in the list.  
/* Note:  Possibility of array overflow not checked         
/************************************************************/
void OrdListInsert(int list[], int& numElems, int newint)
{
   // Locate position to insert value at - index ptr
   int ptr = 0;
   while (newint > list[ptr] && ptr < numElems)  
   {  
      compares1++;
      ptr++;
   }
               
   // Move all successors down one array position:  bottom-up
   for (int i = numElems; i > ptr; i--)
   {
      assigns1++;
      list[i] = list[i-1];
   }
   
   // Insert net item   
   assigns1++;
   list[ptr] = newint;
     
   // Adjust number of elements in list  
   numElems++;                                 
}

//************************************************************/
/* This function receives a list of values of type int     
/* as an array.  The function performs a bubble sort and   
/* returns the list in ascending order.                  
/* Note:  elems is number of elements in list              
/************************************************************/
void sortArray2(int array[], int elems)
{
    int temp, end;

   for (end = elems - 1; end >= 0; end--)
   {
       for (int count = 0; count < end; count++)
       {
          compares2++;
          if (array[count] > array[count + 1])
          {
             assigns2 += 3;
             temp = array[count];
             array[count] = array[count + 1];
             array[count + 1] = temp;
          }
       }
   }
}
void sortArray3(int array[], int elems)
{
    int temp, end;

   for (end = elems - 1; end >= 0; end--)
   {
       for (int count = 0; count < end; count++)
       {
          compares3++;
          if (array[count] > array[count + 1])
          {
             assigns3 += 3;
             temp = array[count];
             array[count] = array[count + 1];
             array[count + 1] = temp;
          }
       }
   }
}

/************************************************************/
/* This function receives an integer, an array containing   */
/* an unordered list, and the size of the list.  It inserts */
/* a new integer item at the end of the list.               */
/************************************************************/
void UnOrdInsert2(int list[], int& numElems, int newint)
{  
   assigns2++;    
   list[numElems] = newint;                       // Insert new element at end of list 
   numElems++;                                    // Increment size of list    
}

void UnOrdInsert3(int list[], int& numElems, int newint)
{  
   assigns3++;    
   list[numElems] = newint;                       // Insert new element at end of list 
   numElems++;                                    // Increment size of list    
}

//************************************************************/
// This function returns a random number selected between 1 and the
// given range passed in as a parameter
//************************************************************/
int randomValue(int range, bool usedValue[])
{
    // Pick a candiate value 1...range.  Test boolean "used"
    // marker array to see if it has been used you.  Keep
    // picking until unused value arrived at and return.
    int value;
    do
    {
        value = rand() % range + 1;   
    } while (usedValue[value] == true);
    
    return value;
} 
