//***********************************************************
// This program demonstrates functions that insert and      
// delete items from an ordered list of ItemTypeegers            
// Author:  T. Klingler                                     
//***********************************************************
#include <iostream>
#include <fstream>
using namespace std;

#include "ItemType.h"
#include "ListType.h"

char inputFile[] = "orderCharList.txt";

int main()
{
    ItemType InList[MAX_ITEMS];     // Array of list elements
    int ListSize;                   // Index of last list element
                                        
    GetList(inputFile, InList, ListSize, MAX_ITEMS);
    cout << endl << "Initial list:" << endl;
    DisplayList(InList, ListSize);

    OrdListInsert(InList, ListSize, 'C');    
    DisplayList(InList, ListSize);
    
    OrdListDelete(InList, ListSize, 'J');    
    DisplayList(InList, ListSize);
    system("pause");
    return 0;
}

