// This file define a class to store information about
// an hourly employee

typedef char nameStr[40];                // To store name character strings

class Employee
{
    private:
        nameStr name;
        long ID;
        double hoursWorked;
        double payRate;
        double grossPay;
        double tax;
        double netPay;

    public:        
        Employee();                      // Default constructor
        void setName(nameStr inName);    // Set name
        void setID(long inID);           // Set employee ID
        void setRate(double rate);       // Store hourly pay rate
        void setHours(double hours);     // Store hours worked
        void calculatePay();             // Calculate pay
        double getGross();               // Return calculated gross pay amount
        double getTax();                 // Return tax amount
        double getNet();                 // Return calculated net pay amount
        void write();                    // Write info to console output
};