// This file includes implementations for date functions associated
// with the Date class

#include <iostream>
#include <string>
using namespace std;

#include "date2.h"

//-----------------------------------------------------------------  
// Default constructor; initialize to 1/1/1990
Date::Date()
{
     month= 1;
     day = 1;
     year = 1990;
}  // end default constructor

//-----------------------------------------------------------------  
// Parameterized constructor
Date::Date(int m, int d, int y)
{
     month= m;
     day = d;
     year = y;
}  // end constructor

//-----------------------------------------------------------------  
// Parameterized constructor for coded string form mm/dd/yyyy
Date::Date(string codedDate)
{
   int start, ptr;                       // To mark positions for substring actions
   char tempCharArray[5];                // For text to number conversions
   string tempStr;                       // Temporary holding string   
      
   // Get birth month      
   ptr = codedDate.find('/',0);                  // Find first slash
   tempStr = codedDate.substr(0,ptr);   
   strcpy(tempCharArray,tempStr.data()); 
   month = atoi(tempCharArray);                  // Assign month
   start = ptr + 1;
      
   // Get birth day      
   ptr = codedDate.find('/',start);              // Find last slash
   tempStr = codedDate.substr(start,ptr-start);   
   strcpy(tempCharArray,tempStr.data());         // Assign day
   day = atoi(tempCharArray);  
   start = ptr + 1;
      
   // Get birth year      
   ptr = codedDate.length();                    // Find end of string
   tempStr = codedDate.substr(start,ptr-start);   
   strcpy(tempCharArray,tempStr.data());
   year = atoi(tempCharArray);                  // Assign year

} 

//-----------------------------------------------------------------  
// SET functions
void Date::setMonth(int m)
{
     month = m;
}  

void Date::setDay(int d)
{
     day = d;
}  

void Date::setYear(int y)
{
     year = y;
}  

//-----------------------------------------------------------------  
// GET functions
int Date::getMonth()  // Return current month value
{
    return month;
}

int Date::getDay()    // Return current day value
{
    return day;
}

int Date::getYear()   // Return current year value
{
    return year;
}
//-----------------------------------------------------------------  
// This function returns true if the year is a leap year and false
// otherwise.

bool Date::leapYear()
{
  if ( year % 400 == 0 ||
     ( year % 4 == 0 && year % 100 != 0 ) )
     return true;
  else
     return false;
     
}  // end function leapYear

//-----------------------------------------------------------------  
// This function returns an integer of the number of days in the
// month.  Leap years are considered.

int Date::daysInMonth()
{
  int days = 0;
  
  // 31 Day theMonths
  if (month== 1 || month== 3 || month== 5  ||
      month== 7 || month== 8 || month== 10 ||
      month== 12 ) 
         days = 31;
            
  // 30 Day theMonths
  else if (month== 4 || month== 6 || 
           month== 9 || month== 11 ) 
         days = 30;
            
  // February
  else  // month== 2
     if ( leapYear() )
        days = 29;
     else 
        days = 28; 

  return days;
    
}  // end function DaysInMonth

//-----------------------------------------------------------------  
// This function returns the Julian date (the day number of the date
// in that year).

int Date::julianDate()
{
  int dayCnt = 0;
  int the_mon;
  
  int FebDays;
  if ( leapYear() )
     FebDays = 29;
  else
     FebDays = 28;

  for (the_mon= 1; the_mon < month; the_mon++)            
    switch(the_mon)
    {
        case 2:     dayCnt +=FebDays; break;
        case 4:
        case 6:
        case 9:
        case 11:    dayCnt +=30; break;
        default:    dayCnt +=31; 
    };
  dayCnt += day;
    
  return dayCnt;
  
}  // end function julianDate

//-----------------------------------------------------------------  
// This method returns a boolean value defining the validity of the
// date.  
bool Date::validDate()
{
   bool valDate = true;   // Assume a good date
   
   // Test for conditions that would make the date validity false
   if (year < 1900)
      valDate = false;
   if ((month< 1) || (month> 12) || (day < 1) || (day > 31))
      valDate = false;
   else if (((month== 4) || (month== 6) || (month== 9) || (month== 11)) && (day == 31))
      valDate = false;
   else if ((month== 2)  && leapYear() && (day > 29))
     valDate = false;
   else if ((month== 2)  && ! leapYear() && (day > 28))
     valDate = false;
      
  return valDate;
}  // end function validDate
   
//-----------------------------------------------------------------  
// This function returns a date code for the day of the week.  It
// counts the number of days since 1/1/1900 which was on a Sunday.
// Output is: 0=Sun,1=Mon, ..., 6=Sat.

int Date::weekDay()
{        
    int DayCnt;
    int daynum,i;

    DayCnt = (year - 1900) * 365;    
    DayCnt += ((year - 1900) / 4) + 1;
    for (i = 1; i <= month-1; i++)
    switch(i)
    {
        case 2:     DayCnt +=28; break;
        case 4:
        case 6:
        case 9:
        case 11:    DayCnt +=30; break;
        default:    DayCnt +=31; 
    };
    
    if (((year - 1900) % 4 == 0) && (month<= 2))
        DayCnt--;
    DayCnt += day;
    daynum = (DayCnt - 1) % 7;
    
    return daynum;
} // end function weekDay 
       
//-----------------------------------------------------------------  
// This function returns (via the parameter list) the 3-character
// descriptor for the day of the week the date represents
string Date::dayCode()
{        
   int code = weekDay();   // Get week day code for THIS date
   string descript;        // Outut value

   switch(code)
   {
      case 0: descript =  "SUN"; break;
      case 1: descript =  "MON"; break;
      case 2: descript =  "TUE"; break;
      case 3: descript =  "WED"; break;
      case 4: descript =  "THU"; break;
      case 5: descript =  "FRI"; break;
      case 6: descript =  "SAT"; break;
   }; // end switch
   
   return descript;
}


//-----------------------------------------------------------------  
// This function returns (via the parameter list) the string
// descriptor for the month the date represents
string Date::monthCode()
{
   string descript;   // Outut value

   switch(month)
   {
       case 1:  descript =  "January";   break;
       case 2:  descript =  "February";  break;
       case 3:  descript =  "March";     break;
       case 4:  descript =  "April";     break;
       case 5:  descript =  "May";       break;
       case 6:  descript =  "June";      break;
       case 7:  descript =  "July";      break;
       case 8:  descript =  "August";    break;
       case 9:  descript =  "September"; break;
       case 10: descript =  "October";   break;
       case 11: descript =  "November";  break;
       case 12: descript =  "December";  break;
   }; // end switch
   
   return descript;
}

//-----------------------------------------------------------------  
// Comparison operation for equality; returns true if dates identical
bool Date::operator==(Date secondDate)
{
    if ( (month == secondDate.month) && (day == secondDate.day) &&
         (year == secondDate.year) )
        return true;
    else
        return false;
}  // end function EqualTo

//-----------------------------------------------------------------  
// Comparison operation for less than; returns true referencing date
// (1st date) is less than date in parameter
bool Date::operator<(Date secondDate)
{
    bool outcome = false;                // Assume date not less than
    if (year < secondDate.year)
        outcome = true;
    else if (year == secondDate.year)
        if (month < secondDate.month)
            outcome = true;
        else if (month == secondDate.month)
            if (day < secondDate.day)
                outcome = true;
    return outcome;
}  // end function LessThan


//-----------------------------------------------------------------  
// Overload the insertion operator to enable console output
ostream& operator<< (ostream &strm, Date &theObj)
{
   strm << theObj.month << "/" << theObj.day << "/" << theObj.year;
   return strm;
}


