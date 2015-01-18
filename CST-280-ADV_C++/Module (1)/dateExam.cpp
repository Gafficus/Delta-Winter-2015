// This program demonstrates a various utility methods related 
// to manipulation of calendar dates 

#include <iostream> 
#include <string> 
using namespace std; 

// Function prototypes (descriptions below) 
bool leapYear(int theYear); 
int DaysInMonth(int theMonth, int theYear); 
int julianDate(int theMonth, int theDay, int theYear); 
bool validDate(int mon, int day, int yr); 
int weekDay(int mon, int day, int year); 
void dayCode(int code, char descript[]); 

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
     
    return 0; 
     
}  // end main function 

//-----------------------------------------------------------------   
// This function receives an integer year and returns true if the 
// year is a leap year and false otherwise. 
bool leapYear(int theYear) 
{ 
  if ( theYear % 400 == 0 || 
     ( theYear % 4 == 0 && theYear % 100 != 0 ) ) 
     return true; 
  else 
     return false; 
      
}  // end function leapYear 

//-----------------------------------------------------------------   
// This function receives an integer month and year and returns an  
// integer of the number of days in the month.  Leap years are 
// considered. 
int DaysInMonth(int theMonth, int theYear) 
{ 
  int days = 0; 
   
  // 31 Day theMonths 
  if (theMonth == 1 || theMonth == 3 || theMonth == 5  || 
      theMonth == 7 || theMonth == 8 || theMonth == 10 || 
      theMonth == 12 )  
         days = 31; 
             
  // 30 Day theMonths 
  else if (theMonth == 4 || theMonth == 6 ||  
           theMonth == 9 || theMonth == 11 )  
         days = 30; 
             
  // February 
  else  // theMonth == 2 
     if ( leapYear(theYear) ) 
        days = 29; 
     else  
        days = 28;  

  return days; 
     
}  // end function DaysInMonth 

//-----------------------------------------------------------------   
// This function receives a valid calendar date and returns the Julian 
// date (the day number of the date in that year). 
int julianDate(int theMonth, int theDay, int theYear) 
{ 
  int dayCnt = 0; 
  int mon; 
  for (mon = 1; mon < theMonth; mon++)             
     dayCnt += DaysInMonth(mon,theYear);         
  dayCnt += theDay; 
   
  return dayCnt; 
   
}  // end function julianDate 

//-----------------------------------------------------------------   
// This method receives a calendar date and returns a boolean value 
// defining the validity of the date.   
bool validDate(int mon, int day, int yr) 
{ 
   bool valDate = true;   // Assume a good date 
    
   // Test for conditions that would make the date validity false 
   if (yr < 1900) 
      valDate = false; 
   if ((mon < 1) || (mon > 12) || (day < 1) || (day > 31)) 
      valDate = false; 
   else if (((mon == 4) || (mon == 6) || (mon == 9) || (mon == 11)) && (day == 31)) 
      valDate = false; 
   else if ((mon == 2)  && leapYear(yr) && (day > 29)) 
     valDate = false; 
   else if ((mon == 2)  && ! leapYear(yr) && (day > 28)) 
     valDate = false; 
       
  return valDate; 
}  // end function validDate 
    
//-----------------------------------------------------------------   
// This function receives a valid date and returns a date code for the 
// day of the week.  It counts the number of days since 1/1/1900 
// which was on a Sunday.  Output is: 0=Sun,1=Mon, ..., 6=Sat. 
int weekDay(int mon, int day, int year) 
{         
    int DayCnt; 
    int daynum,i; 

    DayCnt = (year - 1900) * 365;     
    DayCnt += ((year - 1900) / 4) + 1; 
    for (i=1;i<=mon-1;i++) 
    switch(i) 
    { 
        case 2:     DayCnt +=28; break; 
        case 4: 
        case 6: 
        case 9: 
        case 11:     DayCnt +=30; break; 
        default:    DayCnt +=31;  
    }; 
     
    if (((year - 1900) % 4 == 0) && (mon <= 2)) 
        DayCnt--; 
    DayCnt += day; 
    daynum = (DayCnt - 1) % 7; 
     
    return daynum; 
} // end function weekDay  

    
//-----------------------------------------------------------------   
// This function receives a day code and returns the string (2nd 
// parametere with the three-character day of the week descriptor 
// (0=Sun,1=Mon, ..., 6=Sat) 
void dayCode(int code, char descript[]) 
{         
     switch(code) 
     { 
          case 0: strcpy(descript, "SUN"); break; 
          case 1: strcpy(descript, "MON"); break; 
          case 2: strcpy(descript, "TUE"); break; 
          case 3: strcpy(descript, "WED"); break; 
          case 4: strcpy(descript, "THU"); break; 
          case 5: strcpy(descript, "FRI"); break; 
          case 6: strcpy(descript, "SAT"); break; 
     }; // end switch 
} 


