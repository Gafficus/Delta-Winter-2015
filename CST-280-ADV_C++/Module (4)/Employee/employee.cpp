// This file implements functions for the employee class
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "employee.h"

// Default constructor - initialize to "dummy" values
Employee::Employee()
{    
    strcpy(name,"");
    ID = 0;
    hoursWorked = 0.0;
    payRate = 0.00;
    
    grossPay = 0.00;
    tax = 0.00;
    netPay = 0.00;
}                

// Method to set name data member
void Employee::setName(nameStr inName)
{
    strcpy(name,inName);     
}

// Method to set employee ID data member
void Employee::setID(long inID)
{
    ID = inID;    
}

// Method to set hourly pay rate
void Employee::setRate(double rate)
{
    payRate = rate;
}

// Method to set hours worked
void Employee::setHours(double hours)
{
    hoursWorked = hours;
}

// Method to calculate gross pay, tax, and net pay
// Precondition:  hours worked and pay rate are valid values
void Employee::calculatePay()
{
    // Get and store gross pay; "time-and-a-half" is paid for hours over 40
    if (hoursWorked <= 40.0)
        grossPay = payRate * hoursWorked;
    else
        grossPay = payRate * 40.0 + (hoursWorked - 40.0) * 1.5 * payRate;

    // Get and store tax
    if (grossPay < 200.0)          // Tax is 10% for under $200
        tax = .10 * grossPay;
    else if (grossPay <= 500.0)    // Tax is 15% for $200 - $500
        tax = .15 * grossPay;
    else 
        tax = .20 * grossPay;      // Tax is 20% for over $500

    // Get and store net pay
    netPay = grossPay - tax;
}

// Method to return gross pay
// Precondition:  pay amounts have been calculated
double Employee::getGross()
{
    return grossPay;
}

// Method to calculate and return hours worked
// Precondition:  pay amounts have been calculated
double Employee::getTax()
{
    return tax;
}

// Method to return net pay
// Precondition:  pay amounts have been calculated
double Employee::getNet()
{
    return netPay;
}

// Method to write basic employee info to console output
// Aligns output values for columned output; no labels written
void Employee::write()
{
    // Set up for formatted output
    cout.setf(ios::fixed,ios::floatfield);   
    cout.setf(ios::showpoint);                
    cout.setf(ios::left);          // Left-justify for name field    
    cout << setw(12)  << name;
    cout.unsetf(ios::left);        // Right-justify for numbers (turn left-justify off)
    cout << setw(8)   << ID 
         << setw(6)   << setprecision(2) << hoursWorked 
         << setw(7)   << setprecision(2) << payRate 
         << setw(9)   << setprecision(2) << grossPay 
         << setw(9)   << setprecision(2) << tax 
         << setw(9)   << setprecision(2) << netPay  
         << endl;

}


