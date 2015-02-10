//----------------------------------------------------------------------------
// This program uses record structures with value-return functions
// to demonstrate passing groups of related data elements as one 
// data entity
//----------------------------------------------------------------------------                   
#include <iostream>  // For console output
#include <iomanip>   // For formatted output
#include <fstream>   // For file input
using namespace std;

typedef char nameString[16];                   // Max length for names: 15 chars

const char inputFileName[] = "studentIn.txt";  // Input file name
const int MAX_STUDENTS = 100;                  // Max number of students to process

struct StudentRecord                           // Student record
{
   nameString firstName;
   nameString lastName;
   int id;
   double gpa;
   int currentHours;
   int totalHours;
};

// Function prototypes
void getStudentInfo(StudentRecord theStudents[], ifstream& fileIn, int& numStudents);
void sortByGPA(StudentRecord theStudents[], int numStudents);
void writeStudentInfo(StudentRecord theStudents[], int numStudents);

//----------------------------------------------------------------------------
int main()
{   

   StudentRecord students[MAX_STUDENTS];             // Declare array of students  
   int totalStudents = 0;                            // To store total students entered     
   ifstream inputFile;
   
   getStudentInfo(students,inputFile,totalStudents); // Get student data from file
   sortByGPA(students,totalStudents);                // Sort student data
   writeStudentInfo(students,totalStudents);         // Write student summary report
   
   return 0;
}

//----------------------------------------------------------------------------
// This function builds an array of student records from a file provided
// as a parameter.  
void getStudentInfo(StudentRecord theStudents[], ifstream& fileIn, int& numStudents)
{
   StudentRecord aStudent;
   int currStudent;

   fileIn.open(inputFileName);                // Open input file
  
   // Build array of student records
   currStudent = 0;
   
   // Priming read
   fileIn >> aStudent.lastName >> aStudent.firstName     >> aStudent.id
          >> aStudent.gpa      >> aStudent.currentHours  >> aStudent.totalHours;
   while(! fileIn.eof() )
   {
      theStudents[currStudent] = aStudent;   // Assign student rec to array element
      currStudent++;                         // Point to next array element

      // Continuation read
      fileIn >> aStudent.lastName >> aStudent.firstName     >> aStudent.id
             >> aStudent.gpa      >> aStudent.currentHours  >> aStudent.totalHours;
   }
   numStudents = currStudent;     // Get number students input from file
     
   fileIn.close();    // Close input file

}  // end getStudentInfo

//----------------------------------------------------------------------------
// This performs a descending sort of an array of student records based on the GPA
// data field.  The Bubble Sort algorithm is utilized.
// Precondition:  Number of students parameter contains the exact number of valid
//                student records stored in the array of records
// Postcondition: Array of student records is reordered, descending by GPA
void sortByGPA(StudentRecord theStudents[], int numStudents)
{
    int         placePtr;   // Index for comparing adjacent elements
    int         endIndex;   // Index of stopping point for one pass
    StudentRecord    temp;  // Needed for swapping contents

    for (endIndex = numStudents-1; endIndex >= 0; endIndex--)        
    {
        for (placePtr = 0; placePtr < endIndex; placePtr++)    
           if (theStudents[placePtr].gpa < theStudents[placePtr+1].gpa)        
           {                                            
                temp =  theStudents[placePtr+1];                
                theStudents[placePtr+1] = theStudents[placePtr];        
                theStudents[placePtr] = temp;
           }
    }
}

//----------------------------------------------------------------------------
// This function writes student information from an array of student records
// to the console
void writeStudentInfo(StudentRecord theStudents[], int numStudents)
{
    // Set up formatted output
    cout.setf(ios::fixed,ios::floatfield);   
    cout.setf(ios::showpoint);                
    cout.setf(ios::left);
    
   // Write heading
   cout << "Last Name      First Name   Student ID    GPA   Curr Hrs  Tot Hrs"  << endl;
   
   // Write student data line-by-line
   for (int i = 0; i < numStudents; i++)
   {
       cout << setw(15) << theStudents[i].lastName;
       cout << setw(15) << theStudents[i].firstName;
       cout << setw(12) << theStudents[i].id;
       cout << setw(9) << setprecision(2) << theStudents[i].gpa;
       cout << setw(9) << theStudents[i].currentHours;
       cout << setw(9) << theStudents[i].totalHours;
       cout << endl;   
   }
   
} 