//----------------------------------------------------------------------
//  SPECIFICATION FILE (charSet2.h)
//  This module exports a character set ADT.  A more general module
//  would include additional set operations.
//
// DOMAIN: A CharSet instance is a set of ASCII characters
//         (i.e., any set with elements of type char)
//
// Operators '+' and '*' are overloaded for set union and intersection
//----------------------------------------------------------------------

class CharSet 
{
    private:
        bool inSet[128];
        
    public:
        CharSet();
            // Constructor
            // POST: Created(set)  &&  set == {}
            
        bool IsEmpty();
            // POST: FCTVAL == (set == {})

        bool IsFull();
            // POST: FCTVAL == (set is full)

        void Insert( char ch );
            // PRE:  Assigned(ch)  &&  NOT IsFull()
            // POST: set == set<entry> UNION {ch}

        void Delete( char ch );
            // PRE:  Assigned(ch)
            // POST: set == set<entry> - {ch}

        bool IsElt( char ch );
            // PRE:  Assigned(ch)
            // POST: FCTVAL == (ch is an element of the set)

        CharSet operator*( CharSet set2 );
            // POST: FCTVAL == (this set) INTERSECT set2

        CharSet operator+( CharSet set2 );
            // POST: FCTVAL == (this set) UNION set2

        void Write();
            // POST: if (inSet[i]) for any 0<=i<=127 char written

        int numElems();
            // POST: return value is number of elements in set

};


