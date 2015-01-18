// These functions include various date manipulation algorithms 

//-----------------------------------------------------------------   
// This function receives an integer year and returns true if the 
// year is a leap year and false otherwise. 
bool leapYear(int theYear); 

//-----------------------------------------------------------------   
// This function receives an integer month and year and returns an  
// integer of the number of days in the month.  Leap years are 
// considered. 
int DaysInMonth(int theMonth, int theYear); 

//-----------------------------------------------------------------   
// This function receives a valid calendar date and returns the Julian 
// date (the day number of the date in that year). 
int julianDate(int theMonth, int theDay, int theYear); 

//-----------------------------------------------------------------   
// This method receives a calendar date and returns a boolean value 
// defining the validity of the date.   
bool validDate(int mon, int day, int yr); 

//-----------------------------------------------------------------   
// This function receives a valid date and returns a date code for the 
// day of the week.  It counts the number of days since 1/1/1900 
// which was on a Sunday.  Output is: 0=Sun,1=Mon, ..., 6=Sat. 
int weekDay(int mon, int day, int year); 
    
//-----------------------------------------------------------------   
// This function receives a day code and returns the string (2nd 
// parametere with the three-character day of the week descriptor 
// (0=Sun,1=Mon, ..., 6=Sat) 
void dayCode(int code, char descript[]); 

