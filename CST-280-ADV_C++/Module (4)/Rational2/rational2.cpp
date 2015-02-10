// This file includes implementations of member functions 
// included in the Rational class (Rational.h)

#include <iostream>
using namespace std;

#include "Rational2.h"

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

// Write current fraction to console output
void Rational::Write()
{
    if (denominator == 1)
        cout << numerator << endl;
    else if (denominator == 0)
        cout << "Invalid fraction" << endl;
    else    
        cout << numerator << '/' << denominator << endl;
}

// Simplify current fraction by dividing numerator and denominator
// by greatest common divisor
void Rational::Reduce()
{
    int factor;

    factor = GCD(numerator,denominator);
    numerator = numerator / factor;
    denominator = denominator / factor;
}

// Return decimal equivalent of current fraction. If the denominator
// is zero, boolean flag turned off, otherwise on.
void Rational::FractToDec(double& outDec, bool& valid)
{
    if (denominator != 0)
    {
        outDec = double(numerator)/double(denominator);
        valid = true;
    }
    else
    {
        outDec = 0;
        valid = false;
    }
}

// FRACTION MULTIPLICATION
// Multiply current fraction by another object passed in
// as parameter.  Result returned as fraction object.
// PRE:  both fraction operands and valid (neither deonminator zero)
// POST: result is reduced fraction
Rational Rational::operator* (Rational oper)
{
    Rational answerFract;
    answerFract.numerator = numerator * oper.numerator;
    answerFract.denominator = denominator * oper.denominator;
    answerFract.Reduce();
    return answerFract;
}

// FRACTION DIVISION
// Divide current fraction by another object passed in
// as parameter.  Result returned as fraction object.
// PRE:  both fraction operands and valid 
//       (neither deonminator nor numerator zero)
// POST: result is reduced fraction
Rational Rational::operator/ (Rational oper)
{
    Rational answerFract;
    answerFract.numerator = numerator * oper.denominator;
    answerFract.denominator = denominator * oper.numerator;
    answerFract.Reduce();
    return answerFract;
}

// FRACTION ADDITION
// Add current fraction by another object passed in
// as parameter.  Result returned as fraction object.
// PRE:  both fraction operands and valid (neither deonminator zero)
// POST: result is reduced fraction
Rational Rational::operator+ (Rational oper)
{
    Rational answerFract;
    int tempNum1,tempDen1,tempNum2,tempDen2;  // Local variables for fraction work
    int commonDenom;                          // Common fraction denominator
    int multiplier1,multiplier2;               // Values needed to elevate fraction 
                                              //   to common denominatorcomponents to
    
    // Get common demominator (not necessarily the lowest); find mulipliers
    commonDenom = denominator * oper.denominator;    
    multiplier1 = commonDenom / denominator;
    multiplier2 = commonDenom / oper.denominator;
    
    // Elevate both fractions to common denominator
    tempNum1 = numerator * multiplier1;
    tempDen1 = denominator * multiplier1;
    tempNum2 = oper.numerator * multiplier2;
    tempDen2 = oper.denominator * multiplier2;
    
    // Perform addition and reduce  
    answerFract.numerator = tempNum1 + tempNum2;
    answerFract.denominator = commonDenom;
    answerFract.Reduce();
    return answerFract;
}

// FRACTION SUBTRACT
// Subtract current fraction by another object passed in
// as parameter.  Result returned as fraction object.
// PRE:  both fraction operands and valid (neither deonminator zero)
// POST: result is reduced fraction
Rational Rational::operator- (Rational oper)
{
    Rational answerFract;
    int tempNum1,tempDen1,tempNum2,tempDen2;  // Local variables for fraction work
    int commonDenom;                          // Common fraction denominator
    int multiplier1,multiplier2;               // Values needed to elevate fraction 
                                              //   to common denominatorcomponents to
    
    // Get common demominator (not necessarily the lowest); find mulipliers
    commonDenom = denominator * oper.denominator;    
    multiplier1 = commonDenom / denominator;
    multiplier2 = commonDenom / oper.denominator;
    
    // Elevate both fractions to common denominator
    tempNum1 = numerator * multiplier1;
    tempDen1 = denominator * multiplier1;
    tempNum2 = oper.numerator * multiplier2;
    tempDen2 = oper.denominator * multiplier2;
    
    // Perform addition and reduce  
    answerFract.numerator = tempNum1 - tempNum2;
    answerFract.denominator = commonDenom;
    answerFract.Reduce();
    return answerFract;
}

// Return numerator 
int Rational::GetNum()
{
    return numerator;
}

// Return denominator
int Rational::GetDenom()
{
    return denominator;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Find greatest common divisor of numerator and denominator
// of fraction
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


