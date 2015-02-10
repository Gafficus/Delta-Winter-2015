// This program demonstrates the use of record structures to replace
// parallel arrays.  It reads information from a file into an array
// of structs.  The data elements on each input line are of differing
// types.  The format of a line is:
//        ID number (int)    Hours worked (int)    Pay rate (double)
// This program reads the data into arrays and prints salary as output.

#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

const int MAXARRAY = 20;
const char inFilename[] = "parallel.txt";

// Record structure for one student
struct employRec
{
    int id;
    int hours;
    double rate;
};

int main()
{
    employRec employees[MAXARRAY];
    double grossPay;
    
    // Input the payroll data file and validate existence.
    ifstream fileIn;
    fileIn.open("parallel.txt"); 
    
    if (fileIn.fail() )         
    {
       cout <<  "Problem opening file";
       exit(-1);
    }

    int numEmployees = 0;  // Counter for total "records" of data
    int currRec = 0;       // Pointer to current data record
    
    // Priming read
    fileIn >> employees[currRec].id >> employees[currRec].hours 
           >> employees[currRec].rate;            
    while( ! fileIn.eof() && currRec < MAXARRAY)
    {
        currRec++;                                                    
        fileIn >> employees[currRec].id >> employees[currRec].hours     
               >> employees[currRec].rate;            
    }
    
    // Get number of elements in file
    numEmployees = currRec;
                     
   // Write summary using formatted output
   cout << "  ID     GROSS PAY" << endl;   // Write output report headings
   for (currRec = 0; currRec < numEmployees; currRec++)
   {
      grossPay = employees[currRec].hours * employees[currRec].rate;
      cout << employees[currRec].id;
      cout << "    $" << setw(7) << setprecision(2) << fixed << grossPay << endl;
   }
             
    return 0;
} 