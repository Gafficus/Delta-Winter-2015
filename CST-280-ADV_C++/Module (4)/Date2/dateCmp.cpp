// This program reads a list of calendar dates and compares
// them all individually with the first date

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "date2.h"

void writeComparisons(Date mainDate, Date newDate);       

int main()
{     
    string dateInput;
    ifstream InFile;
                  
    // File Work
    InFile.open("dateList.txt");   
    if (InFile.fail() )        
    {
      cout <<  "Problem opening file";
      exit(-1);
    }
    
    // First date in list 
    InFile >> dateInput; 
    Date mainDate(dateInput);     // Construct date object  
    
    // Read and compare to subsequent dates     
           
    InFile >> dateInput;                    // Get next date
    while ( !InFile.eof() )        
    {
       Date newDate(dateInput);             // Construct date object
       writeComparisons(mainDate,newDate);  // Compare
       InFile >> dateInput;                 // Get next date
    }            
    system("pause");
    return 0;
    
}  // end main

// This function compares two date objects and writes a message to the
// console about their relationship
void writeComparisons(Date mainDate, Date newDate)       
{
    // Write out first date in coded form
    cout << mainDate;
         
    // Write relationship
    if (mainDate < newDate)
       cout << " is less than ";
    else if (mainDate == newDate)
       cout << " is equal to ";
    else 
       cout << " is greater than ";
       
    // Write out second date in coded form
    cout << newDate << endl;
         
}


