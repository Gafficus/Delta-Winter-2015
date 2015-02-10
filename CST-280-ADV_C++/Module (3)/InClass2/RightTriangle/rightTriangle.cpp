// This file includes implementations for functions of the right
// triangle class.

#include <iostream>
#include <cmath>
using namespace std;

#include "rightTriangle.h"

// Default constructor
RightTriangle::RightTriangle()
{
    base = 0;
    height = 0;
}

// SET functions (for storing data in private data members)
void RightTriangle::setHeight(double h)
{
    height = h;
}
 
void RightTriangle::setBase(double b)
{
    base = b;
}

// Calculate length of hypotenuse using
// Pythagorean Theorem
double RightTriangle::calcHypotenuse()
{
    return sqrt (base * base + height * height);
}

