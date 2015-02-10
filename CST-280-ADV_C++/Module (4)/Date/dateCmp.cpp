// This program reads a list of calendar dates and compares
// them all individually with the first date

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "date.h"

void writeComparisons(Date mainDate, Date newDate);       

int main()
{     
    int mon,day,yr;
    ifstream InFile;
                  
    // File Work
    InFile.open("dateList.txt");   
    if (InFile.fail() )        
    {
      cout <<  "Problem opening file";
      exit(-1);
    }
    
    // First date in list 
    InFile >> mon >> day >> yr;
    Date mainDate(mon,day,yr);     // Construct date object
    
    // Read and compare to subsequent dates     
           
    InFile >> mon >> day >> yr;
    while ( !InFile.eof() )
    {
       Date newDate(mon,day,yr);            // Construct date object
       writeComparisons(mainDate,newDate);  // Compare
       InFile >> mon >> day >> yr;           // Get next date
    }            
    system("pause");
    return 0;
    
}  // end main

// This function compares two date objects and writes a message to the
// console about their relationship
void writeComparisons(Date mainDate, Date newDate)       
{
    // Write out first date in coded form
    cout << mainDate.getMonth() << "/"
         << mainDate.getDay()   << "/"
         << mainDate.getYear();
    
    // Write relationship
    if (mainDate.lessThan(newDate))
       cout << " is less than ";
    else if (mainDate.equalTo(newDate))
       cout << " is equal to ";
    else 
       cout << " is greater than ";
       
    // Write out second date in coded form
    cout << newDate.getMonth() << "/"
    << newDate.getDay()   << "/"
    << newDate.getYear();
    
    cout << endl << endl;
    
}


