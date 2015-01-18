// This program demonstrates a various utility methods related 
// to manipulation of calendar dates and the use of library files 
// for functions. 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string> 
using namespace std; 

#include "datefun.h" 

int main() 
{      
    int theYear,theMon,theDay; 
    int daynum;       
    char dayOfWeek[4];       
     
    cout << "Enter month,day,year (mm dd yyyy) separated by spaces" << endl; 
    cin >> theMon >> theDay >> theYear; 
     
    if (validDate(theMon,theDay,theYear))    // If a valid date, summarize about it 
    { 
        // Echo print the date 
        cout << endl << endl; 
        cout << theMon << "/" << theDay << "/" << theYear << endl; 
     
        // Write if leap year or not 
        if (leapYear(theYear)) 
           cout << "Year is a LEAP YEAR" << endl; 
        else 
           cout << "Year is NOT a LEAP YEAR" << endl; 
         
        // Write Julian date 
        cout << "The julian date is: " << julianDate(theMon,theDay,theYear) << endl; 
         
        // Write Julian date 
        cout << "There are " << DaysInMonth(theMon,theYear)  
             << " days in this month" << endl; 
                 
        // Write actual day-of-week from code 
        cout << "The date falls on a "; 
        daynum = weekDay(theMon,theDay,theYear);  // Get day of week code 
        dayCode(daynum,dayOfWeek);                // Get day of week descript string 
        cout << dayOfWeek << endl; 
         
    }  // end if valid date 
    else 
    { 
       // Handle an invalid date 
       cout << theMon << '/' << theDay << '/' << theYear 
            << " is not valid" << endl; 
    }  // end else 
    system("pause"); 
    return 0; 
     
}  // end main function 

