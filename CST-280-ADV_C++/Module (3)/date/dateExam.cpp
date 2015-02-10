// Date class test driver
// This program demonstrates a various utility methods related
// to manipulation of calendar dates and the use of library files
// for functions.

#include <iostream>
using namespace std;

#include "Date.h"

int main()
{     
    int theYear,theMon,theDay;
    char dayOfWeek[4];     
    char monthName[15]; 
    Date theDate;            
    
    cout << "Enter month,day,year (mm dd yyyy) separated by spaces" << endl;
    cin >> theMon >> theDay >> theYear;
    
    // Store values in the object data members
    theDate.setMonth(theMon);
    theDate.setDay(theDay);
    theDate.setYear(theYear);
    
    if (theDate.validDate())            // If a valid date, summarize about it
    {
        // Echo print the date
        cout << endl << endl;
        theDate.monthCode(monthName);
        cout << monthName << " " << theDate.getDay() << ", "
             << theDate.getYear() << endl;
    
        // Write if leap year or not
        if (theDate.leapYear())
           cout << "The year is a LEAP YEAR" << endl;
        else
           cout << "The year is NOT a LEAP YEAR" << endl;
        
        // Write Julian date
        cout << "The julian date is: " << theDate.julianDate() << endl;
        
        // Write Julian date
        cout << "There are " << theDate.daysInMonth() 
             << " days in this month" << endl;
        
        // Write actual day-of-week from code
        cout << "The date falls on a ";
        theDate.dayCode(dayOfWeek);       // Get day of week description string
        cout << dayOfWeek << endl;
        
    }  // end if valid date
    else
    {
       // Handle an invalid date
        cout << theDate.getMonth()  << "/" << theDate.getDay() << "/" 
             << theDate.getYear() << " is not valid" << endl;
    }  // end else
    
    return 0;
    
}  // end main

