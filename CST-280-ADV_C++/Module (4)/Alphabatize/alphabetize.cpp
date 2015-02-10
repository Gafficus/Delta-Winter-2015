// This program reads a series of character strings from a text file
// and sorts them in alphabetical order
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_ARRAY_SIZE    = 50;               // Dimension of array for strings

void GetList(string inList[], int& listsize, int maxlistsize);
void alphabetizeList(string StringList[], int elems);
void DisplayList(string inList[],int listsize);

int main()
{
   string StringList[MAX_ARRAY_SIZE];   
   int numInList;     
       
   // Build list from file
   GetList(StringList, numInList, MAX_ARRAY_SIZE);  
    
   // Alphabetize list 
   alphabetizeList(StringList, numInList);          
               
   // Display list
   DisplayList(StringList, numInList);
   
   return 0;
}

/************************************************************/
/* This function opens a file to retrieve a list of string  */
/* values.  Values are stored in an array and passed to the */
/* calling routine.                                         */
/************************************************************/
void GetList(string inList[], int& listsize, int maxlistsize)
{
   ifstream InFile ("StateList.txt");
   string ListElement;

    if (InFile.fail() )             // Test for file existence
    {
      cout <<  "Problem opening file";
      exit(-1);
    }
    
   int i = 0;
   getline(InFile,ListElement);
   while( !InFile.eof() && i < maxlistsize)
   {
      inList[i] = ListElement;
      i++;
      getline(InFile,ListElement);
   }
   listsize = i;     // Size of list is number of elements
}

/************************************************************/
/* This function receives an array of strings and returned  */
/* the list in alphabetical order.  The bubble sort is      */
/* utilized.  Variable elems stores the number of good data */
/* elements in the string list.                             */
/************************************************************/
void alphabetizeList(string StringList[], int elems)
{
   int end;
   string temp;
   
   for (end = elems - 1; end >= 0; end--)
   {
       for (int count = 0; count < end; count++)
       {
          if (StringList[count] > StringList[count + 1] )  // Compare adjacent values
          {                                                        
             temp = StringList[count];                     // Swap if out of order
             StringList[count] = StringList[count + 1];
             StringList[count + 1] = temp;
          }
       }
   }
}

/************************************************************/
/* This function writes a list to console output:  one list */
/* item at a time.                                          */
/************************************************************/
void DisplayList(string inList[],int listsize)
{
   for (int i = 0;i < listsize; i++)
      cout << inList[i] << endl;
   cout << endl;
}



