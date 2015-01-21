//*****************************************************************
// This program loads a "database" of student information
// Student info from a file in the format of:
//     KEY: ID number (int)   Letter grade (char)   GPA (double)
// are entered into parallel arrays.  The program then sorts the
// arrays using the ID fields as the key.
//*****************************************************************

#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

void buildArrays(int id[], char grade[], double gpa[], int& totalRecs);
void sortLists(int id[], char grade[], double gpa[], int elems);
void writeStudentData(int id[], char grade[], double gpa[], int numElems);              

const int MAX_ARRAY_SIZE = 20;   // Max number of students in DB

//*****************************************************************

int main()
{
    // Declare primary arrays
    int id[MAX_ARRAY_SIZE];
    char grade[MAX_ARRAY_SIZE];
    double gpa[MAX_ARRAY_SIZE];
    
    int totalRecs;
     
    // Build arrays from file
    buildArrays(id, grade, gpa, totalRecs);
    
    // Build arrays from file
    sortLists(id, grade, gpa, totalRecs);
     
    // Write list of students
     writeStudentData(id, grade, gpa, totalRecs);      
                        
    return 0;
}

//*****************************************************************
// This function builds the set of parallel student arrays from
// the input file.
//*****************************************************************
void buildArrays(int id[], char grade[], double gpa[], int& totalRecs)
{
   // Set up file
    ifstream theData;
    theData.open("gradeInfo.txt");
    if (theData.fail() )         // Test for file existence
    {
      cout <<  "Problem opening file";
      exit(-1);
    }

    // Input parallel records from file of unknown length
    totalRecs = 0;    // Counter for total "records" of data
    int currRec = 0;      // Pointer to current data record
    
    // Priming read
    theData >> id[currRec] >> grade[currRec] >> gpa[currRec];
    while( ! theData.eof() && currRec < MAX_ARRAY_SIZE )
    {
        currRec++;                                                   
        theData >> id[currRec] >> grade[currRec] >> gpa[currRec];     
    }
    // Capture final index pointer as number of elements
    // (one index past last good element)
    totalRecs = currRec;
}

//*****************************************************************
// This function uses the bubble sort strategy to sort a set of
// parallel arrays storing student data.  The student ID field
// is used as the key.
//*****************************************************************
void sortLists(int id[], char grade[], double gpa[], int elems)
{
   int end;
   int tempID;
   double tempGPA;
   char tempGrade;

   for (end = elems - 1; end >= 0; end--)
   {
       for (int count = 0; count < end; count++)
       {
          // Compare key value to determine ordering
          if (id[count] > id[count + 1])
          {
             // Swap all arrays together
             tempID = id[count];
             id[count] = id[count + 1];
             id[count + 1] = tempID;
             tempGrade = grade[count];
             grade[count] = grade[count + 1];
             grade[count + 1] = tempGrade;
             tempGPA = gpa[count];
             gpa[count] = gpa[count + 1];
             gpa[count + 1] = tempGPA;
         }
       }
   }
}

//*****************************************************************
// This function writes the contens of the student info arrays 
// directly to the console.
///*****************************************************************
void writeStudentData(int id[], char grade[], double gpa[], int numElems)                  
{
   // Write column headings
   cout << " ID    Grade   GPA " << endl;
   for (int i=0; i < numElems; i++)
       cout << setw(5) << id[i] 
            << setw(5) << grade[i] 
            << setw(8) << gpa[i] 
            << endl;
           
    cout << endl;
}    
