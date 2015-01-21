//*****************************************************************
// This program searches a "database" of student information
// Student info from a file in the format of:
//     KEY: ID number (int)   Letter grade (char)   GPA (double)
// are entered into parallel arrays.  Users are prompted for an
// ID number and writes the corresponding letter grade and GPA
//*****************************************************************

#include<fstream>
#include<iostream>
using namespace std;

int searchList(int list[], int numElems, int value);
void writeStudentInfo(int id[], char grade[], double gpa[], int key);                  

const int MAX_ARRAY_SIZE = 20;   // Max number of students in DB
const int FAILED_SEARCH = -1;    // Code for failed search

//*****************************************************************

int main()
{
    int id[MAX_ARRAY_SIZE];
    char grade[MAX_ARRAY_SIZE];
    double gpa[MAX_ARRAY_SIZE];
    
    ifstream theData;
    char contPrompt;         // Continuation prompt
    int targetID;            // Student ID to search for
    int searchOutcome;       // Index code resulting from search
    
    // Set up file
    theData.open("gradeInfo.txt");
    if (theData.fail() )         // Test for file existence
    {
      cout <<  "Problem opening file";
      exit(-1);
    }

    // Input parallel records from file of unknown length
    int totalRecs = 0;    // Counter for total "records" of data
    int currRec = 0;      // Pointer to current data record
    
    // Priming read
    theData >> id[currRec] >> grade[currRec] >> gpa[currRec];
    while( ! theData.eof() && currRec < MAX_ARRAY_SIZE )
    {
        currRec++;                                                 // Add one to pointer
        theData >> id[currRec] >> grade[currRec] >> gpa[currRec];  // Subsequent reads
    }
    // Capture final index pointer as number of elements
    // (one index past last good element)
    totalRecs = currRec;
    
    // Process user requests
    do
    {
      // Prompt for student ID (key) to search for
      cout << endl << "Enter student ID: ";
      cin >> targetID;
      
      // Search for student
      searchOutcome = searchList(id, totalRecs, targetID);
      
      // Print student summary (if found in list; error msg otherwise)
      if (searchOutcome != FAILED_SEARCH)                 
          writeStudentInfo(id, grade, gpa, searchOutcome);
      else                                                  
          cout << "Student ID not found" << endl << endl;
  
      // Prompt for continuation
      cout << "Do you wish to continue (y or n)?: ";
      cin >> contPrompt;       
    
    } while (contPrompt == 'y' || contPrompt == 'Y'); 
    
    return 0;
}

//*****************************************************************
// The searchList function performs a linear search on an     
// integer array. The array list, which has a maximum of numElems
// elements, is searched for the number stored in value. If the
// number is found, its array subscript is returned. Otherwise,  
// -1 is returned indicating the value was not in the array.
//*****************************************************************
int searchList(int list[], int numElems, int value)
{
    int index = 0;            // Used as a subscript to search array
    int position = -1;        // To record position of search value
    bool found = false;       // Flag to indicate if the value was found

    while (index < numElems && !found)
    {
        if (list[index] == value)    // If the value is found
        {
            found = true;            // Set the flag
            position = index;        // Record the value's subscript
        }
        index++;                     // Go to the next element
    }
    return position;                 // Return the position, or -1
}

//*****************************************************************
// This function writes a student summary message directly to the
// console.  
// Precondition:   key value matches a value in id[] array
// Postconditions: no arrays are changed in this action
//*****************************************************************
void writeStudentInfo(int id[], char grade[], double gpa[], int key)                  
{
    cout << endl;
    cout << "Student ID: "   << id[key]    << endl;
    cout << "   Grade: "     << grade[key] << "   GPA: " 
         << gpa[key] << endl << endl;
}
