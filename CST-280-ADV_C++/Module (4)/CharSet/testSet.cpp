/*  This program is a test driver to demonstrate the set    */
/*  operations of the Set class.                            */

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "charSet.h"

int main()
{
    // Set 1 is {A,B}
    CharSet set1;
    set1.Insert('A');
    set1.Insert('B');
    cout << "Set 1: ";
    set1.Write();
    
    // Set 2 is {B,C}
    CharSet set2;
    set2.Insert('B');
    set2.Insert('C');
    cout << "Set 2: ";
    set2.Write();

    // Determine Set 3 as the union of sets 1 and 2
    CharSet set3;
    set3 = set1.Union(set2);
    cout << "Set 1 union Set 2: ";
    set3.Write();
    
    // Determine Set 4 as the interscetion of sets 1 and 2
    CharSet set4;
    set4 = set1.Intersect(set2);
    cout << "Set 1 intersection Set 2: ";
    set4.Write();
        
    // Remove element B from Set 3
    set3.Delete('B');
    cout << "Set 3 with 'B' deleted: ";
    set3.Write();
    
    // Test if C is element of Set 3
    if (set3.IsElt('C'))
        cout << "Set 3 has 'C'" << endl;
    else
        cout << "Set 3 does not have 'C'" << endl;
    
    // Test if B is element of Set 3
    if (set3.IsElt('B'))
        cout << "Set 3 has 'B'" << endl;
    else
        cout << "Set 3 does not have 'B'" << endl;
        
    // Generate a big set of all upper and lower case letters and write it
     CharSet bigSet;
    int i;
    for (i=65;i<=90;i++)
        bigSet.Insert(char(i));
    cout << "The big set has: ";
    bigSet.Write();
    for (i=97;i<=122;i++)
        bigSet.Insert(char(i));
    cout << "The big set now has: ";
    bigSet.Write();
    system("pause");
    return 0;
}


