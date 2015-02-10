//----------------------------------------------------------------------
//  SPECIFICATION FILE (digset.h)
//  This module exports a digit set ADT.  A more general ADT
//  would include additional set operations.
//----------------------------------------------------------------------
// DOMAIN: A DigitSet instance is a set of single-digit integers
//         (i.e., a set from the universe 0, 1, 2, ..., 9)

class DigitSet 
{
    private:  
        unsigned int bitStr;

    public:
        bool IsEmpty(); 
        bool IsFull();
        void Insert( int someDig ); 
        void Delete( int someDig );
        bool IsElt( int someDig );
        void Write();
        DigitSet operator*( DigitSet set2 );
        DigitSet operator+( DigitSet set2 );
        bool operator==( DigitSet set2 );
        DigitSet();
 };

