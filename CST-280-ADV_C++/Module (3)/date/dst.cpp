// This program receives an integer year and returns the
// first and last day of daylight savings time in the U.S.
// Rule: daylight savings time:
//    ==> begins at 2:00 a.m. on the second Sunday of March
//    ==> ends at 2:00 a.m. on the first Sunday of November

#include <iostream>
using namespace std;

#include "date.h"

int main()
{     
    int theYear;
    int month,day;
    Date dstStartDate,dstEndDate;
    bool done;
    
    cout << "Enter year: ";
    cin >> theYear;
    cout << endl << endl;
    
    dstStartDate.setYear(theYear);   // Set objects to desired year
    dstEndDate.setYear(theYear);     
    
    // FIND DST Start Date
    // Assert: Second Sunday of a month falls between day 8...14
    dstStartDate.setMonth(3);       // Set object month to March
    day = 8;
    done = false;
    while (day <= 14 && !done)
    {
        dstStartDate.setDay(day);
        if (dstStartDate.weekDay() == 0)
            done = true;
        else
            day++;
    }
        
    // FIND DST End Date
    // Assert: First Sunday of a month falls between day 1...7
    dstEndDate.setMonth(11);       // Set object month to November
    day = 1;
    done = false;
    while (day <= 7 && !done)
    {
        dstEndDate.setDay(day);
        if (dstEndDate.weekDay() == 0)
            done = true;
        else
            day++;
    }

    // Report results
    cout << "In " << theYear << endl;
    cout << "  DST begins: "
         << dstStartDate.getMonth() << "/"
         << dstStartDate.getDay()   << "/"
         << dstStartDate.getYear()  << endl;
    
    cout << "  DST ends:   "
         << dstEndDate.getMonth() << "/"
         << dstEndDate.getDay()   << "/"
         << dstEndDate.getYear()  << endl;
        
    return 0;
    
}  // end main

