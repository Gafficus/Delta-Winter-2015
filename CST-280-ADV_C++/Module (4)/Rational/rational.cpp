// This file includes implementations of member functions 
// included in the Rational class (Rational.h)

#include <iostream>
using namespace std;

#include "Rational.h"

// Default constructor
Rational::Rational()
{
    numerator = 1;
    denominator = 1;
}

// Parameterized constructor
Rational::Rational(int num, int denom)
{
    numerator = num;
    denominator = denom;
}

//---------------------------------------------------------
// Set/Get functions

int Rational::GetNum()              // Return numerator 
{
    return numerator;
}

int Rational::GetDenom()            // Return denominator
{
    return denominator;
}

void Rational::SetNum(int num)      // Set numerator 
{
    numerator = num;
}

void Rational::SetDenom(int denom)  // Set denominator
{
    denominator = denom;
}

//---------------------------------------------------------
// Fraction work functions

// Simplify current fraction.  Calculate GCD of current
// numerator and denominator and divide by by it.  Replaces
// fraction stored in this object by reduced fraction.
void Rational::Reduce()
{
    int factor;

    factor = GCD(numerator,denominator);
    numerator = numerator / factor;
    denominator = denominator / factor;
}

// Return true if denominator is NOT zero; false otherwise
bool Rational::IsValidFract()
{
    if (denominator == 0)
       return false;
    else
       return true;
}

// Return decimal equivalent of current fraction
// Precondition:  Denominator is NOT zero
double Rational::FractToDec()
{
    return double(numerator)/double(denominator);
}

// Multiply current fraction by another object passed in
// as parameter.  Current fraction object receives product
Rational Rational::Multiply(Rational operand2)
{
    Rational newFract;
    newFract.numerator   = numerator   * operand2.numerator;
    newFract.denominator = denominator * operand2.denominator;
    
    return newFract;
}

// Write current fraction to console output. Writes error message
// if fraction has zero denominator
void Rational::Write()
{
    if (denominator == 1)
        cout << numerator << endl;
    else if (denominator == 0)
        cout << "Invalid fraction" << endl;
    else    
        cout << numerator << '/' << denominator << endl;
}


// Private function to find greatest common divisor of 
// two integers using the Euclidean algorithm.
// Used to reduce numerator and denominator of fraction
int Rational::GCD(int m, int n)
{
    int temp,r;

    if (m < n)
    {
        temp = n;
        n = m;
        m = temp;
    }
    r = m;
    while (r != 0)
    {
        r = m % n;
        if (r != 0)
        {
            m = n;
            n = r;
        }
    }
    return n;
}


