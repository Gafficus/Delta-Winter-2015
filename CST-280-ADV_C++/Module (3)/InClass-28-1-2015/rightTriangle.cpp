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
RightTriangle::RightTriangle(double a, double b)
{
    base = a;
    height = b;
}

// SET functions (for storing data in private data members)
void RightTriangle::setHeight(double h)
{
    height = h;
}
double RightTriangle::getHeight()
{
	return height;
}
 
void RightTriangle::setBase(double b)
{
    base = b;
}
double RightTriangle::getBase()
{
	return base;
}

// Calculate length of hypotenuse using
// Pythagorean Theorem
double RightTriangle::calcHypotenuse()
{
    return sqrt (base * base + height * height);
}
double RightTriangle::calcArea()
{
    return (1.0/2.0)*(base*height);
}