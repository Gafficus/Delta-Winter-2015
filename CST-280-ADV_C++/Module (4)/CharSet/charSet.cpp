//----------------------------------------------------------------------
//  IMPLEMENTATION FILE (charSet.cpp)
//  This module exports a character set ADT.
//----------------------------------------------------------------------
#include <iostream>
using namespace std;

#include "charSet.h"

// Private members of class:
//    bool inSet[128];     One array element per ASCII char

CharSet::CharSet()
    // Constructor
    //..............................................................
    // POST: inSet[0..127] == false
    //..............................................................
{
    int i;
    for (i = 0; i < 128; i++)
        inSet[i] = false;
}

bool CharSet::IsFull()
    // Observer function to test if a set is full.  With this implementation
    // a "full state" can never occur.
    //..............................................................
    // POST: FCTVAL == false
    //       (With the 128-element vector preallocated, it cannot overflow)
    //..............................................................
{
    return false;
}

bool CharSet::IsEmpty()
    // Observer function to test if a set is empty
    //..............................................................
    // POST: FCTVAL == true, if (NOT inSet[i]) for all 0<=i<=127
    //              == false, otherwise
    //..............................................................
{ 
    int i = 0;
    while (i < 128) 
    { 
       if (inSet[i])
          return false;
       i++;
    }
    return true;
}

void CharSet::Insert( char ch )
    // Insert a member into a set
    //..............................................................
    // PRE:  Assigned(ch)
    // POST: inSet[ch] == true
    //..............................................................
{
    inSet[int(ch)] = true;
}

void CharSet::Delete( char ch )
    // Delete a member from a set
    //..............................................................
    // PRE:  Assigned(ch)
    // POST: inSet[ch] == false
    //..............................................................
{
    inSet[int(ch)] = false;
}

bool CharSet::IsElt( char ch )
    // Observer function to test if an element is a member of a set
    //..............................................................
    // PRE:  Assigned(ch)
    // POST: FCTVAL == inSet[ch]
    //..............................................................
{
    return inSet[int(ch)];
}

CharSet CharSet::Intersect( CharSet set2 )
    // Determine intersection of two sets
    //..................................................................
    // POST: For all i, (0 <= i <= 127),
    //       FCTVAL.inSet[i] == (inSet[i] && set2.inSet[i])
    //..................................................................
{
    CharSet result;
    int     i;

    for (i = 0; i < 128; i++)
        result.inSet[i] =(inSet[i] && set2.inSet[i]);
    return result;
}

CharSet CharSet::Union( CharSet set2 )
    // Determine union of two sets
    //..................................................................
    // POST: For all i, (0 <= i <= 127),
    //       FCTVAL.inSet[i] == (inSet[i] || set2.inSet[i])
    //..................................................................
{
    CharSet result;
    int     i;

    for (i = 0; i < 128; i++)
        result.inSet[i] = (inSet[i] || set2.inSet[i]);
    return result;
}

void CharSet::Write()
    // Write the set members to the console
    //..................................................................
    // POST: if (inSet[i]) for any 0<=i<=127
    //       char written to console
    //..................................................................
{
    CharSet result;
    int     i;

    for (i = 0; i < 128; i++)
        if (inSet[i] == true)
            cout << char(i) << ' ';
    cout << endl;
}


