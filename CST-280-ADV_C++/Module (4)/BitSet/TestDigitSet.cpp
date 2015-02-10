/*  This program is a test driver to demonstrate the set    */
/*  operations of the DigitSet class.                       */

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "DigitSet.h"

int main()
{
    // Build test set 1: { 1, 2 } 
    DigitSet set1;
    set1.Insert(1);
    set1.Insert(2);
    cout << "Set 1: ";
    set1.Write();
    
    if (set1.IsFull())
        cout << "Set is FULL" << endl;
    else
        cout << "Set is not full" << endl;
    
    // Build test set 2: { 2, 3 } 
    DigitSet set2;
    set2.Insert(2);
    set2.Insert(3);
    cout << "Set 2: ";
    set2.Write();

    // Union of sets 1 & 2:  { 1, 2, 3 }
    DigitSet set3;
    set3 = set1 + set2;
    cout << "Set 1 union Set 2: ";
    set3.Write();
    
    // Intersection of sets 1 & 2:  { 2 }
    DigitSet set4;
    set4 = set1 * set2;
    cout << "Set 1 intersection Set 2: ";
    set4.Write();
        
    // Test deleting element 2 from { 1, 2, 3 }
    set3.Delete(2);
    cout << "Union (Set 3) of sets 1 and 2 with element 2 deleted: ";
    set3.Write();
    
    // Test if 3 is element of Set 3
    if (set3.IsElt(3))
        cout << "Set 3 has 3" << endl;
    else
        cout << "Set 3 does not have 3" << endl;
    
    // Test if 2 is element of Set 3
    if (set3.IsElt(2))
        cout << "Set 3 has 2" << endl;
    else
        cout << "Set 3 does not have 2" << endl;
        
    // Build large set with digits: { 0, 1, 2, ..., 9 } and write it
    DigitSet bigSet;
    for (int i = 0; i <= 9  ; i++)
        bigSet.Insert(i);
    cout << "The big set has: ";
    bigSet.Write();
    
    if (bigSet.IsFull())
        cout << "Large Set is FULL" << endl;
    else
        cout << "Large Set is not full" << endl;
   
    // Build test set 4: { 2, 3 } 
    DigitSet set5;
    set5.Insert(2);
    set5.Insert(3);
    cout << "Set 5: ";
    set5.Write();

	if (set2 == set5)
		cout << "Sets 2 and 5 are equal" << endl;
	else
		cout << "Sets 2 and 5 are not equal" << endl;

	system("pause");
    return 0;
}


