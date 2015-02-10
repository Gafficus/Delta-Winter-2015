/************************************************************/
/* This program acts as a driver program to test the        */
/* IntList class.                                           */
/* Author:  T. Klingler                                     */
/************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

#include "intList.h"

int main()
{     
    IntList testList;
    int returnCode;
    
    // Open file - If bad return code, then exit program
    returnCode = testList.BuildList("listFile.txt");
        
    // Demonstrate list processing features
    testList.PrintList();
    
     
    // Perform inserts and test list size
    cout << "List size: " << testList.ListSize() << endl;
    testList.ListInsert(79);
    testList.PrintList();   
    cout << "List size: " << testList.ListSize() << endl;  
    cout << "Item 66 is at position: " << testList.ListSearch(66) << endl;
    cout << "Item 79 is at position: " << testList.ListSearch(79) << endl;
    cout << "Item 15 is at position: " << testList.ListSearch(15) << endl;
    cout << "Item 17 is at position: " << testList.ListSearch(17) << endl;
    
    // Perform deletes; test and print list size
    testList.ListDelete(66);
    testList.ListDelete(79);
    testList.PrintList();        
    cout << "List size: " << testList.ListSize() << endl;
    
    // Sort ans display list
    testList.SortList();
    testList.PrintList();
    system("pause");
    return 0;
}

