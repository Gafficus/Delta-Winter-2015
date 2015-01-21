// This file defines the functions for unordered list management
// ItemType is a generic data type and must be defined

// Build list from file
// Precondition: list is ordered
void GetList(char inFile[], ItemType inList[],
             int& listsize, int maxlistsize);

// Display contents of list in console
void DisplayList(ItemType theList[],int listsize);

// Delete from an ordered list
void OrdListInsert(ItemType list[], int& numElems, ItemType newItemType);

// Insert into an ordered list
void OrdListDelete(ItemType list[], int& numElems, ItemType oldItemType);

// Binary search of an ordered list
int binarySearch(ItemType array[], int numelems, ItemType value);

