
#include "stdafx.h"
/*************************************************************/ 
/* This program demonstrates reads two ordered lists, merges */ 
/* the lists together, and displays the results.             */ 
/* The lists will not contain duplicates.                    */ 
/* Author:  T. Klingler                                      */ 
/*************************************************************/ 

#include <iostream> 
#include <fstream> 
#include "Header1.h"
using namespace std; 

const int MAX_LIST_SIZE = 100;                // Max list size 
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

