/*************************************************************/
/* This program demonstrates reads two ordered lists, merges */
/* the lists together, and displays the results.             */
/* The lists will not contain duplicates.                    */
/* Author:  T. Klingler                                      */
/*************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LIST_SIZE = 100;                // Max list size

// Function prototypes
void GetList(int inList[],int& listsize,int maxlistsize,
             ifstream& inFile);
void DisplayList(int theList[],int listsize);
void MergeLists(int list1[],   int list1Elems, 
                int list2[],   int list2Elems,
                int outList[], int& outListElems);

int main()
{
    int  List1[MAX_LIST_SIZE], List2[MAX_LIST_SIZE]; 
    int outList[MAX_LIST_SIZE];   
    int list1_size, list2_size, outList_size;                
    
    // Read and display list 1                               
    ifstream inList1("list1.txt");
    GetList(List1, list1_size, MAX_LIST_SIZE, inList1);
    cout << "List 1:" << endl;
    DisplayList(List1, list1_size);

    // Read and display list 2                               
    ifstream inList2("list2.txt");
    GetList(List2, list2_size, MAX_LIST_SIZE, inList2);
    cout << "List 2:" << endl;
    DisplayList(List2, list2_size);
    
    // Merge and display combined list
    MergeLists(List1, list1_size, List2, list2_size, 
               outList, outList_size);    
    cout << "Combined list after merger:" << endl;
    DisplayList(outList, outList_size);
    
    return 0;
}

/****************************************************************/
/* This function receives an two ordered lists of integers and  */
/* merges them into one combined ordered list.                  */
/* Predconditions:  There are no duplicates in lists or between */
/* lists.  Lists are not empty.  Combined list does not exceed  */
/* max lists size.                                              */
/****************************************************************/
void MergeLists(int list1[],   int list1Elems, 
                int list2[],   int list2Elems,
                int outList[], int& outListElems)
{
   int ptr1, ptr2, outPtr;
   ptr1 = 0;
   ptr2 = 0;
   outPtr = 0;
   
   // While neither list empty, merge lists
   while (ptr1 < list1Elems && ptr2 < list2Elems)
   {
      if (list1[ptr1] < list2[ptr2])
      {
         outList[outPtr] = list1[ptr1];
         ptr1++;
      }
      else
      {
         outList[outPtr] = list2[ptr2];
         ptr2++;
      }
      outPtr++;   
   }

   // While items remain in list 1, fill end of output list
   while (ptr1 < list1Elems)
   {
      outList[outPtr] = list1[ptr1];
      ptr1++;
      outPtr++;
   }

   // While items remain in list 2, fill end of output list
   while (ptr2 < list2Elems)
   {
      outList[outPtr] = list2[ptr2];
      ptr2++;
      outPtr++;
   }
   
   outListElems = outPtr;    // Capture number of items in final list
}

/************************************************************/
/* This function opens a file to retrieve a list of integer */
/* values.  Values are stored in an array and passed to the */
/* calling routine.                                         */
/*   Parameters:                                            */
/*        list            array of integers to build        */
/*        listsize        number of integers in list        */
/*        maxlistsize     max size allowable for list array */
/*        inFile          file containing list              */
/************************************************************/
void GetList(int inList[], int& listsize, int maxlistsize, 
             ifstream& inFile)
{
    int ListElement;
    
    int i = 0;
    inFile >> ListElement;
    while(inFile && i < maxlistsize)
    {    
        inList[i] = ListElement;
        i++;
        inFile >> ListElement;
    }
    listsize = i;        // Size of list is lastindex + 1
}

/************************************************************/
/* This function writes a list to console output:  one list */
/* item at a time.                                          */
/************************************************************/
void DisplayList(int theList[],int listsize)
{
    for (int i = 0; i < listsize; i++)
        cout << theList[i] << " ";
    cout << endl << endl;
} 
