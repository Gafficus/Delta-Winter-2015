//----------------------------------------------------------------------
//  IMPLEMENTATION FILE (digset.cpp)
//  This module exports a digit set ADT.  The domain of the set are all
//  digits 0...9
//  Set representation: a bit string.
// 
// NOTE: Bits are numbered such that 0 is the rightmost bit
//----------------------------------------------------------------------
#include "DigitSet.h"
#include <iostream>
#include <iomanip>    // For setw()
using namespace std;

DigitSet::DigitSet()
    // Default constructor.  Set to empty set (zero)
    //..............................................................
    // Constructor
    // POST: bitStr == 0
    //..............................................................
{
    bitStr = 0;
}

bool DigitSet::IsEmpty()
    // Accessor for empty set.  If bit string == integer zero, 
    // then it is empty.
    //..............................................................
    // POST: FCTVAL == (bitStr == 0)
    //..............................................................
{
    return (bitStr == 0);
}

bool DigitSet::IsFull()
    // Domain is contrained to 0...9.  Loop shifts a '1' bit through
    // each position.  If 'and' operation with any position results in
    // '0', then false is returned (i.e. not full)
    //..............................................................
{
    bool fullTest = true;
    for (int i = 0; i < 10; i++)
        if ((bitStr & (1 << i)) == 0 )
            fullTest = false;
    return fullTest;
}

void DigitSet::Insert( int someDig )
    // Insert an element into the set.
    // Strategy is to create a bit string with only one digit.  Shift
    // one to position for given digit to insert and perform bitwise-
    // or with the given set string.
    //..............................................................
    // POST: Bit in position someDig equals 1
    //..............................................................
{
    bitStr = bitStr | (1 << someDig);
}

void DigitSet::Delete( int someDig )
    // Delete an element from the set.
    // Strategy is to create a bit string with only one digit.  Shift
    // one to position for given digit, compliment the bitstring, and
    // perform bitwise-andto remove the digit.
    // or with the given set string.
    //..............................................................
    // POST: Bit in position someDig equals 0
    //..............................................................
{
    bitStr = bitStr & ~(1 << someDig);
}

bool DigitSet::IsElt( int someDig )
    // Accessor to test if a given element is in set.
    //..............................................................
    // POST: FCTVAL == (Bit in position someDig == 1)
    //..............................................................
{
    return ( (bitStr & (1 << someDig)) > 0 );
}

void DigitSet::Write()
    // Write integers currently in set.  Scan bits in set bit string
    // right-to-left and write corresponding integer if bit on.
    //..............................................................
    // POST: Elements of set have been displayed on one line
    //..............................................................
{
    int i;
    for (i = 0; i < 10; i++)
        if ((bitStr & (1 << i)) > 0 )
            cout << setw(2) << i;
    cout << endl;
}

DigitSet DigitSet::operator*( DigitSet set2 )
    // Set intersection
    //..............................................................
    // POST: FCTVAL == new set represented by bit string
    //                 bitStr BITWISE-AND set2.bitStr
    //..............................................................
{
    DigitSet newSet;

    newSet.bitStr = bitStr & set2.bitStr;
    return newSet;
}

DigitSet DigitSet::operator+( DigitSet set2 )
    // Set union
    //..............................................................
    // POST: FCTVAL == new set represented by bit string
    //                 bitStr BITWISE-OR set2.bitStr
    //..............................................................
{
    DigitSet newSet;

    newSet.bitStr = bitStr | set2.bitStr;
    return newSet;
}

bool DigitSet::operator==( DigitSet set2 )
    // Set equivalence
    //..............................................................
    // Tests if integer member values match exactly.
    //..............................................................
{
	if (bitStr == set2.bitStr)
		return true;
	else
		return false;
}

