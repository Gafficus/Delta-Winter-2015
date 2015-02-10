#include "stdafx.h"
//******************************************************************
// CST 280 In-Class List Algorithm Practice 
//******************************************************************
#include <iostream>
#include <fstream>
#include "Header1.h"
using namespace std;

const int MAX_LIST_SIZE = 100;                // Max list size

// Function prototypes
void GetList(int inList[],int& listsize,int maxlistsize, ifstream& inFile);
void DisplayList(int theList[],int listsize);
void ReverseList(int theList[],int& numItems);
void removeDuplicates(int theList[], int& numItems);

int main()
{
    cout << "Assignment 7: Zach and Nathan" << endl << endl;
   
    int List1[MAX_LIST_SIZE], List2[MAX_LIST_SIZE], List3[MAX_LIST_SIZE];   
    int list1_size, list2_size, list3_size;                
    
    // Read both input lists from files                                    
    ifstream inList1("list1.txt");
    GetList(List1, list1_size ,MAX_LIST_SIZE, inList1);

    ifstream inList2("list2.txt");
    GetList(List2, list2_size, MAX_LIST_SIZE, inList2);
    
    // Display list 1 
    cout << "List 1 (initial): " << endl;
    DisplayList(List1, list1_size);
    
    // Display list 2 
    cout << "List 2 (initial): " << endl;
    DisplayList(List2, list2_size);


    // ==================================================

    ReverseList(List1, list1_size);
	cout << endl << "Reversed List: ";
	DisplayList(List1, list1_size);

	cout << endl << "Duplicates Removed: ";
	removeDuplicates(List2, list2_size);
	DisplayList(List2, list2_size);

	cout << endl << "List 1: ";
	DisplayList(List1, list1_size);

	cout << endl << "List 2: ";
	DisplayList(List2, list2_size);

	UnOrdInsert(List1, list1_size, 14);
	UnOrdInsert(List1, list1_size, 24);
	UnOrdDelete(List1, list1_size, 11);
	MergeLists(List1, list1_size, List2, list2_size, List3, list3_size);
	DisplayList(List3, list3_size);


    
    
    // ==================================================

    system("pause");
    return 0;
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
void GetList(int inList[],int& listsize,int maxlistsize, ifstream& inFile)
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
    for (int i = 0;i < listsize; i++)
        cout << theList[i] << " ";
    cout << endl << endl;
}

/************************************************************/
/* This function reverses the order of an unordered list    */
/* Strategy:  As list is traversed one way, path the other  */
/* direction is calculated arithmetically.                  */
/************************************************************/
void ReverseList(int theList[],int& numItems)
{
   int temp;

   for (int i = 0; i < numItems / 2; i++)     // Traverse half-way across list
   {
      temp = theList[i];                      // Swap element with its counterpart
      theList[i] = theList[numItems-i-1];
      theList[numItems-i-1] = temp;
   }
}

/**********************************************************/
/*This function receives an ordered list of integers and  */
/*removes duplicate values(in adjacent storage elements)  */
/**********************************************************/
void removeDuplicates(int theList[], int& listSize)
{
	int i, j;
	i = 0;
	while(i < listSize - 1)
	{
		if (theList[i] == theList[i+1])
		{
			for (j = 1; j < listSize - 1; j++)
				theList[j] = theList[j+1];
			listSize--;
		}
		else
			i++;
	}
}
