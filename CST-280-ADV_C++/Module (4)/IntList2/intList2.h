// This file defines the class for storage and management of a list
// of integers

const int MAX_LIST = 200;

class IntList
{
    private:
        int list[MAX_LIST];  // Array of list elements
        int size;            // Actual number of items in list (last is index size-1)
        
        int currPos;         // Index of current position within list (used by iterators)
        
    public:
        IntList();                      // Constructor - initializes list to size = 0
        int BuildList(char file[]);     // Create list from integer data in a file
        void ListInsert(int newint);    // Add integer item to end of list
        int ListSearch(int item);       // Return position index of integer in list
        void ListDelete(int badint);    // Search for & delete int in list 
        int ListSize();                 // Return current size of list
        void SortList();                // Sort list using bubble sort
        void PrintList();               // Write list to console output
        
        void ResetList();               // Reset current pos indicator to first position    
        int GetNextItem();              // Advance to next pos and return item
        bool atEnd();                   // Check if at end of list (currPos == size)
};


