/****************************************************************/ 
/*  This program builds a sunrise/sunset table for the          */ 
/*  Tri-Cities area for any month of any year.                  */ 
/*              Input:  month, year                             */ 
/*              Output: Table written to console output         */ 
/*  Author:  T. Klingler                                        */ 
/****************************************************************/ 
#include <iostream> 
#include <iomanip> 
using namespace std; 

#include "sun.h" 

double const MBS_LAT = 43.53; 
double const MBS_LON = 84.08; 
  
// Function prototypes 
void InputDate(int&,int&,char&, bool&); 
void BuildTable(int, int, char, bool); 
int dayMonth(int,int); 
double Deg_Rad(double); 
bool LeapYr(int); 

int main () 
{ 
    // Local variables 
    int  mon, year; 
    char zone = 'E';                    // Assume eastern time zone for this demo 
	bool dstOn;                         // For daylight savings time 

    InputDate(mon,year,zone,dstOn);     // Get date and time zone from user 
    BuildTable(mon,year,zone,dstOn);    // Create sunrise/sunset table 
         
    return 0; 
} 

/******************************************************************/ 
/*      This function prompts the user to input a month, year and */ 
/*  time zone.                                                    */ 
/******************************************************************/       
void InputDate(int& month, int& yr, char& tzone, bool& dstON) 
{ 
    char DST_answer; 

    cout << "Enter month (1..12) and year (19xx or 20xx) separted by a blank" << endl; 
    cin >> month >> yr; 
    cout << endl;                         // Blank line 
         
    do                                    // Prompt user for daylight savings time 
    { 
        cout << "Daylight savings time active? (y or n) "; 
        cin >> DST_answer; 
        cout << endl;                           
    } 
    while (!(DST_answer == 'y' || DST_answer == 'Y'  
          || DST_answer == 'n' || DST_answer == 'N')); 

	if (DST_answer == 'y' || DST_answer == 'Y') 
	dstON = true; 
	else 
	dstON = false; 

    cout << endl;                         // Blank line 
} 

/****************************************************************/ 
/*  This function accepts a month/year and time zone code       */ 
/*  and builds a table of sunrise/set values to console output. */ 
/****************************************************************/ 
void BuildTable(int mon, int year, char zone, bool dst) 
{ 
    cout.setf(ios::fixed, ios::floatfield);         // Set up doubling 
    cout.setf(ios::right);                          //   output format 
    cout.setf(ios::showpoint);                               

    int day, maxday; 
    TextTime rise,set; 
                 
    maxday = dayMonth(mon,year);          // Get max days in month 
         
    // Title 
    cout << "MBS Sunrise/sunset for " << mon << "/" << year << endl << endl; 
         
    // Headings 
    cout << "    Day Sunrise Sunset" << endl; 
         
    for (day = 1; day <= maxday; day++) 
    { 
        Sun_Rise_Set(MBS_LAT,MBS_LON,mon,day,year,zone,dst,rise,set); 
        cout << setw(6) << day << "  " << rise << "  " << set << endl; 
    } 
} 

/**********************************************************************/ 
/*  This function accepts a month (1-12), and a year.  It returns     */ 
/*  the number of days in the month.  Leap years are tested using     */ 
/*  the required function LeayYr().                                   */ 
/**********************************************************************/ 
int dayMonth(int mo,int yr) 
{ 
    int days; 
    switch(mo) 
    { 
         case 2:                 // February 
         { 
            if (LeapYr(yr)) 
               days = 29; 
            else 
               days = 28; 
            break; 
         } 
         case 4:                 // 30-day months 
         case 6: 
         case 9: 
         case 11: 
            days = 30; break; 
         default:                // 31-day months 
            days = 31; 
        }; 
    return days; 
} 

/****************************************************************/ 
/*  This function receives a four-digit year and returns a      */ 
/*  bool value:  TRUE for a leap year, FALSE otherwise.         */ 
/****************************************************************/ 
bool LeapYr(int year) 
{ 
    if ((year % 400 == 0) || (year % 4 == 0) && !(year % 100 == 0)) 
        return true; 
    else 
        return false; 
} 

