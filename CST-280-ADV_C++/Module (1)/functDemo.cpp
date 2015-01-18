/*******************************************************************/ 
/* This program demonstrates the various types of functions in C++ */ 
/* Author:  T. Klingler                                            */ 
/*******************************************************************/ 
#include <iostream> 
#include <cmath> 
using namespace std; 

double const pi = 3.141592; 

// Function prototypes 
int sum(int num1, int num2, int num3); 
void DeltaAddr(); 
void CartToPolar(double x, double y, double& r, double& theta); 

int main() 
{     
     // Test function 1 
     int value1 = 20, value2 = 40, value3 = 60,    
        total;          

    total = sum(value1, value2, value3); 
    
    cout << "The sum is " << total << endl << endl; 

    // Test function 2 
    DeltaAddr(); 
     
    // Test function 3 
    double x = 3.0; 
    double y = 5.0; 
    double theta,radius; 
    CartToPolar(x,y,radius,theta); 
    cout << "(" << x << "," << y << ") in cartesian coordinates is " 
         << "(" << theta << "," << radius << ") in polar coordinates"; 
    cout << endl << endl; 
     
    return 0;     
} 

/**********************************************************************/ 
// This value return function receives 3 numbers and returns their sum. 
int sum(int num1, int num2, int num3) 
{ 
   return num1 + num2 + num3; 
} 

/**********************************************************************/ 
// This void function prints the Delta College address 
// It is a VOID FUNCTION with NO PARAMETERS 
void DeltaAddr() 
{ 
    cout << "Delta College" << endl; 
    cout << "1961 Delta Road" << endl; 
    cout << "University Center, MI  48710" << endl; 
    cout << endl; 
} 

/**********************************************************************/ 
// This void function receives a cartesian coordinate and 
// returns the equivalent point in polar coordinates 
// It is a VOID FUNCTION with VALUE and REFERENCE PARAMETERS 
void CartToPolar(double x, double y, double& r, double& theta) 
{ 
    r = sqrt(x*x + y*y); 
    theta = atan(y/x); 
} 

