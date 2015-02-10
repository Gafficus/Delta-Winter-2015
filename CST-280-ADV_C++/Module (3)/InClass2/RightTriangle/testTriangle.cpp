// This program calculates various parameters of a
// right triangle.

#include <iostream>
using namespace std;

#include "rightTriangle.h"

int main()
{     
    // Declaration
    double base,height;
    RightTriangle aTriangle;    
    
    // Input
    cout << "Enter the base of the triangle: ";
    cin  >> base;
    cout << "Enter the height of the triangle: ";
    cin  >> height;
    
    // Move data to object
    aTriangle.setBase(base);
    aTriangle.setHeight(height);
    
    // Calculations and output
    cout << endl;
    cout << "Length of hypotenuse: " 
         << aTriangle.calcHypotenuse() << endl;
     
    return 0;
    
}  // end main function

