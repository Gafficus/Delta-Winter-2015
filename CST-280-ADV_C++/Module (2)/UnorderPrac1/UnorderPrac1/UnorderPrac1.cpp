// UnorderPrac1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/************************************************************/
/* This program demonstrates functions that insert and      */
/* delete items from an unordered list of integers          */
/* Author:  T. Klingler                                     */
/************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LIST_SIZE = 100;                // Max list size

// Function prototypes
void GetList(int inList[],int& listsize,int maxlistsize);
void DisplayList(int theList[],int listsize);
void UnOrdInsert(int list[], int& numElems, int newint);
void UnOrdDelete(int list[], int& numElems, int oldint);
void UnOrdInsertFrontRand(int list[], int& numElems, int newint);
void UnOrdInsertFrontFixed(int list[], int& numElems, int newint);

int main()
{
    int    InList[MAX_LIST_SIZE];   // Array of list elements
    int ListSize;                   // Index of last list element
                                        
    GetList(InList,ListSize,MAX_LIST_SIZE);
    cout << endl << "Initial list:" << endl;
    DisplayList(InList,ListSize);

    UnOrdInsert(InList,ListSize,10);   // Insert value of 10
    cout << endl << "After inserting 10:" << endl;
    DisplayList(InList,ListSize);
    
    UnOrdDelete(InList,ListSize,19);   // Delete value of 19
    cout << endl << "After deleting 19:" << endl;
    DisplayList(InList,ListSize);
     
    UnOrdInsertFrontRand(InList,ListSize,22);   // Insert value of 22
    cout << endl << "After inserting 22 at front:" << endl;
    DisplayList(InList,ListSize);
     
    UnOrdInsertFrontFixed(InList,ListSize,99);   // Insert value of 99
    cout << endl << "After inserting 99 at front:" << endl;
    DisplayList(InList,ListSize);
   
	system("pause");
    return 0;
}

/************************************************************/
/* This function opens a file to retrieve a list of integer */
/* values.  Values are stored in an array and passed to the */
/* calling routine.                                         */
/*   Parameters:                                            */
/*      list            array of integers to build          */
/*      listsize        number of integers in list          */
/*      maxlistsize     max size allowable for list array   */
/************************************************************/
void GetList(int inList[],int& listsize,int maxlistsize)
{
    ifstream InFile ("unorderList.txt");
    int ListElement;
    
    int i = 0;
    InFile >> ListElement;
    while( ! InFile.eof() && i < maxlistsize)
    {
        inList[i] = ListElement;
        i++;
        InFile >> ListElement;
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
/* This function receives an integer, an array containing   */
/* an unordered list, and the size of the list.  It inserts */
/* a new integer item at the end of the list.               */
/************************************************************/
void UnOrdInsert(int list[], int& numElems, int newint)
{      
   list[numElems] = newint;           // Insert new element at end of list   
   numElems++;                        // Increment size of list                                     
}


/************************************************************/
/* This function receives an integer, an array containing   */
/* an unordered list, and the size of the list.  It locates */
/* and deletes the integer integer from the list.           */
/************************************************************/
void UnOrdDelete(int list[], int& numElems, int oldint)
{
  int ptr = 0;                              // Scan list for deletion target
  while (oldint != list[ptr] && ptr < numElems)    
      ptr++;
               
  if (ptr < numElems)                       // If target found, then
  {
      list[ptr] = list[numElems-1];         // Move last list item to overwrite target
      numElems--;                           // Decrement size of list
  }
}

/************************************************************/
/* This function receives an integer, an array containing   */
/* an unordered list, and the size of the list.  It inserts */
/* a new integer item at the beginning of the list.         */
/*                                                          */
/************************************************************/
void UnOrdInsertFrontRand(int list[], int& numElems, int newint)
{      
   list[numElems] = list[0];
   list[0] = newint;
   numElems++;
}


/************************************************************/
/* This function receives an integer, an array containing   */
/* an unordered list, and the size of the list.  It inserts */
/* a new integer item at the beginning of the list.         */
/*                                                          */
/* POSTCONDITION: Order of original list is undisturbed.    */
/************************************************************/
void UnOrdInsertFrontFixed(int list[], int& numElems, int newint)
{      
   int counter;
   
   for (counter = numElems; counter >= 0; counter--)
   {
	   list[counter + 1] = list[counter];
   }
   list[0] = newint;
   numElems++;
						         


					         
}


