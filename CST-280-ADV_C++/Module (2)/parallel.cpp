// This program processes employee pay using arrays for
// id, hours worked, and pay rate

// PRECONDITION: No more than 20 employee lines exist in
// external data file

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAXARRAY = 20;

int main()
{
   int id[MAXARRAY];      
   int hours[MAXARRAY];      
   double rate[MAXARRAY];
   
   int numEmployees, i;   
   double grossPay;           

   // Input the payroll data file and validate existence.
   ifstream fileIn;
   fileIn.open("parallel.txt"); 
    
   if (fileIn.fail() )         
   {
       cout <<  "Problem opening file";
       exit(-1);
   }
    
   // Read data file into parallel arrays
   i = 0;
   fileIn >> id[i] >> hours[i] >> rate[i];                
   while (!fileIn.eof() && i < MAXARRAY)    // Test for end of file and array    
   {
      i++;        
      fileIn >> id[i] >> hours[i] >> rate[i];                
   }            
   numEmployees = i;                         // Capture number of employees in file

   // Write summary using formatted output
   cout << "  ID     GROSS PAY" << endl;   // Write output report headings
   for (i = 0; i < numEmployees; i++)
   {
      grossPay = hours[i] * rate[i];
      cout << id[i];
      cout << "    $" << setw(7) << setprecision(2) << fixed << grossPay << endl;
   }
   
   return 0;
} 
