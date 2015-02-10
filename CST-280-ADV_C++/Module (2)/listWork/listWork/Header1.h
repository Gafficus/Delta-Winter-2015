#include "stdafx.h"
#include <iostream>

using namespace std;

void GetList(int inList[],int& listsize,int maxlistsize);
void DisplayList(int theList[],int listsize);
void UnOrdInsert(int list[], int& numElems, int newint);
void UnOrdDelete(int list[], int& numElems, int oldint);
void UnOrdInsertFrontRand(int list[], int& numElems, int newint);
void UnOrdInsertFrontFixed(int list[], int& numElems, int newint);

void MergeLists(int list1[],   int list1Elems,  
                int list2[],   int list2Elems, 
                int outList[], int& outListElems); 