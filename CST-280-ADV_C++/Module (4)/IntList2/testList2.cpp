/************************************************************/
/* This program acts as a driver program to test the        */
/* IntList class.                                           */
/* Author:  T. Klingler                                     */
/************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

#include "intList2.h"

int main()
{     
    IntList testList;
    int returnCode;
    int anItem;
    
    // Open file - If bad return code, then exit program
    returnCode = testList.BuildList("ListFile.txt");
        
    // Demonstrate list processing features
    testList.PrintList();
    
    // Perform inserts and test list size
    cout << "List size: " << testList.ListSize() << endl;
    testList.ListInsert(79);    
    testList.PrintList();   
      
    cout << "List size: " << testList.ListSize() << endl;  
    cout << "Item 66 is at position: " << testList.ListSearch(66) << endl;
    
    // Perform deletes; test and print list size
    testList.ListDelete(66);
    testList.ListDelete(79);
              
    cout << "List size: " << testList.ListSize() << endl;
    
    // Sort and display list
    testList.SortList();
    testList.PrintList();   
    
    // Print list using iterators
    cout << "List elements: ";    
    testList.ResetList();  
    while( ! testList.atEnd() )
    {
       anItem = testList.GetNextItem();
       cout << anItem << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}


