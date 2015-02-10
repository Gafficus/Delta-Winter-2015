// Date.h
// This file defines the specifications for the Date class.  This class
// is a utility for any work with calendar dates.

class Date
{
    private:
        int month;
        int day;
        int year;
        
    public:
        // Default constructor; initialize to 1/1/1990
        Date();
        
        //-----------------------------------------------------------------  
        // Parameterized constructor
        Date(int m, int d, int y);

        //-----------------------------------------------------------------  
        // Set functions
        void setMonth(int m);
        void setDay(int d);
        void setYear(int y);

        //-----------------------------------------------------------------  
        // Get functions
        int getMonth();
        int getDay();
        int getYear();

        //-----------------------------------------------------------------  
        // This function returns true if the year is a leap year and false
        // otherwise.
        bool leapYear();

        //-----------------------------------------------------------------  
        // This function returns an integer of the number of days in the
        // month.  Leap years are considered.
        int daysInMonth();

        //-----------------------------------------------------------------  
        // This function returns the Julian date (the day number of the date
        // in that year).
        int julianDate();

        //-----------------------------------------------------------------  
        // This method returns a boolean value defining the validity of the
        // date.  
        bool validDate();

        //-----------------------------------------------------------------  
        // This function returns a date code for the day of the week.  It
        // counts the number of days since 1/1/1900 which was on a Sunday.
        // Output is: 0=Sun,1=Mon, ..., 6=Sat.
        int weekDay();
        
        //-----------------------------------------------------------------  
        // This function returns (via the parameter list) the 3-character
        // descriptor for the day of the week the date represents
        void dayCode(char descript[]);
        
        //-----------------------------------------------------------------  
        // This function returns (via the parameter list) the string
        // descriptor for the month the date represents
        void monthCode(char descript[]);
};

