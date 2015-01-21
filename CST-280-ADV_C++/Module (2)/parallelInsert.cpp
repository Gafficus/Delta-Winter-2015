// This program processes employee pay using arrays for
// id, hours worked, and pay rate.  It reads an existing file
// and writes a report.  Then, it opens a second file and adds
// employees that are ultimately ordered by ID number.

// PRECONDITION: No more than 20 employee lines exist in
// external data files

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void getStartData( int id[], int hours[], double rate[], int& numEmployees);
void writeReport( int id[], int hours[], double rate[], int numEmployees);
void addEmployees(int id[], int hours[], double rate[], int& numEmployees);
void ordListInsert2(int newID, int newHrs, double newRate,
                    int id[], int hours[], double rate[], int& numEmployees);

const int MAXARRAY = 20;

int main()
{
   int id[MAXARRAY];      
   int hours[MAXARRAY];      
   double rate[MAXARRAY];
   
   int numEmployees = 0;   
  
   // Build initial employee list and write report
   getStartData(id,hours,rate,numEmployees); 
   writeReport(id,hours,rate,numEmployees);
   
   // Add new employess and write updated report
   addEmployees(id,hours,rate,numEmployees);
   writeReport(id,hours,rate,numEmployees);
   
   return 0;
}

// --------------------------------------------------------------------------------
// This function accesses the existing exmployees, ordered by ID number
void getStartData( int id[], int hours[], double rate[], int& numEmployees)
{
   // Input the payroll data file and validate existence.
   ifstream fileIn;
   fileIn.open("parallel.txt"); 
    
   if (fileIn.fail() )         
   {
       cout <<  "Problem opening file";
       exit(-1);
   }
    
   // Read data file into parallel arrays
   int i = 0;
   fileIn >> id[i] >> hours[i] >> rate[i];                
   while (!fileIn.eof() && i < MAXARRAY)    // Test for end of file and array    
   {
      i++;        
      fileIn >> id[i] >> hours[i] >> rate[i];                
   }            
   numEmployees = i;                         // Capture number of employees in file
}

// --------------------------------------------------------------------------------
// This function writes a simple payroll report using formatted output
void writeReport(int id[], int hours[], double rate[], int numEmployees)
{   
   double grossPay;    

   cout << "  ID     GROSS PAY" << endl;   // Write output report headings
   for (int i = 0; i < numEmployees; i++)
   {
      grossPay = hours[i] * rate[i];
      cout << id[i];
      cout << "    $" << setw(7) << setprecision(2) << fixed << grossPay << endl;
   }
   cout << endl;
}
   
// --------------------------------------------------------------------------------
// This function adds employees to a list stored in 3 parallel arrays.  It
// requires a call to a function that inserts into an ordered list
void addEmployees(int id[], int hours[], double rate[], int& numEmployees)
{
   int newID, newHrs;
   double newRate;

   // Input the payroll data file and validate existence.
   ifstream fileIn;
   fileIn.open("parallelAdd.txt"); 
    
   if (fileIn.fail() )         
   {
       cout <<  "Problem opening file";
       exit(-1);
   }
    
   // Read data file and insert into parallel arrays 
   fileIn >> newID >> newHrs >> newRate;                
   while (!fileIn.eof())    // Test for end of file and array    
   {
      ordListInsert2(newID,newHrs,newRate,id,hours,rate,numEmployees);
      fileIn >> newID >> newHrs >> newRate;                
   }            
}

// --------------------------------------------------------------------------------
// This function receives three parallel arrays of employee data as well
// as parameters for a new record.  The record is inserted in the correct
// location based on the 'id' key.
void ordListInsert2(int newID, int newHrs, double newRate,
                    int id[], int hours[], double rate[], int& numEmployees)
{
   // Locate position to insert value at - index ptr
   int ptr = 0;
   while (newID > id[ptr] && ptr < numEmployees)    
      ptr++;
               
   // Move all successors down one array position:  bottom-up
   for (int i = numEmployees; i > ptr; i--)
   {
      id[i]    = id[i-1];
      hours[i] = hours[i-1];
      rate[i]  = rate[i-1];
   }
   
   // Insert net item   
   id[ptr]    = newID;
   hours[ptr] = newHrs;
   rate[ptr]  = newRate;
     
   // Adjust number of elements in list  
   numEmployees++;                                 
} 
