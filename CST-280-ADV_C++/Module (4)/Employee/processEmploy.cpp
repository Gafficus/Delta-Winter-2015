// This program demonstrates the creation of an array of 
// employee objects.  Functionality:
//    1) Calculate total payroll and tax amounts
//    2) Sort to list employees from highest paid to lowest
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#include "employee.h"

void BubbleSort(Employee employList[],int length);

int main()
{    
    Employee peopleList[10];        // Array of OBJECTS

    double hours,rate,tot_gross,tot_net,tot_tax;
    nameStr name;
    long ID;
    int ptr,size;

    // Initializes totals
    tot_gross=0;
    tot_net=0;
    tot_tax=0;

    // read employee info from file and build array values
    ifstream infile("inpay2.txt");    
    
    ptr = 0;
    infile >> name >> ID >> hours >> rate;        // Priming read
    while( !infile.eof() )
    {
        // Store information from file in current array object
        peopleList[ptr].setName(name);
        peopleList[ptr].setID(ID);            
        peopleList[ptr].setRate(rate);        
        peopleList[ptr].setHours(hours);        

        // Send message to object to calcualte pay
        peopleList[ptr].calculatePay();            
        
        // Update totals
        tot_gross += peopleList[ptr].getGross();;
        tot_net += peopleList[ptr].getNet();
        tot_tax += peopleList[ptr].getTax();
        
        infile >> name >> ID >> hours >> rate;    // Continuation read
        ptr++;
    }    
    size = ptr;
    
    // Perform bubble sort to order employees from highest paid to lowest
    // and write list of employees
    BubbleSort(peopleList,size);

    
    // Write report headings
    cout << "     NAME       ID   HOURS   RATE   GROSS     TAX      NET" << endl;
    
    // Write employee data line-by-line
    for (int i=0; i < size; i++)
        peopleList[i].write();
    
    // Write totals
    cout.setf(ios::fixed,ios::floatfield);       // Set up for formatted output
    cout.setf(ios::showpoint);    
                
    cout << endl;
    cout << "TOTALS                            ";
    cout << setw(8) << setprecision(2) << tot_gross << " ";
    cout << setw(8) << setprecision(2) << tot_tax   << " ";
    cout << setw(8) << setprecision(2) << tot_net   << endl;
    system("pause");
    return 0;
}

// This version of the bubble sort receives a list of employee objects
// and its length.  It returns the list in descending order of amount
// each employee is paid
void BubbleSort(Employee employList[],int length)
{
    int            placePtr;    // Index for comparing adjacent elements
    int            endIndex;    // Index of stopping point for one pass
    Employee    temp;        // Needed for swapping contents

    for (endIndex = length-1; endIndex >= 0; endIndex--)        
    {
        for (placePtr = 0; placePtr <= endIndex; placePtr++)    
           if (employList[placePtr].getNet() < employList[placePtr+1].getNet())        
           {                                            
                temp =  employList[placePtr+1];                
                employList[placePtr+1] = employList[placePtr];        
                employList[placePtr] = temp;
           }
    }
}



