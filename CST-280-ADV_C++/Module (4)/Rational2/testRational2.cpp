// This program is a test driver for the Rational class
#include <iostream>
using namespace std;

#include "Rational2.h"

int main()
{     
    double answer;
    bool OK;

    Rational fract;                     // Invoke default constructor
    fract.Write();
    
    Rational fract2(6,8);               // Invoke parameterized constructor
    fract2.Write();    
    
    fract2.Reduce();                    // Reduce 6/8 to 3/4
    fract2.Write();
    fract2.FractToDec(answer,OK);       // Write 3/4 as a decimal
    if (OK)
       cout << "As a decimal: " << answer << endl;
    else
       cout << "Zero denominator" << endl;
    
    Rational fract3(6,1);               // Test writing 6/1 as just 6
    cout << fract3.GetNum() << "/" << fract3.GetDenom() << " written as ";
    fract3.Write();    
    
    Rational fract4(6,0);               // Test error feature for zero denominators
    cout << fract4.GetNum() << "/" << fract4.GetDenom() << " written as ";
    fract4.Write();    
    fract4.FractToDec(answer,OK);       // Write 6/0 as a decimal; test zero feature
    if (OK)
       cout << "As a decimal: " << answer << endl;
    else
       cout << "Zero denominator" << endl;
    
    Rational fract5(2,3);               // Write 2/3 to a decimal
    fract5.FractToDec(answer,OK);       
    if (OK)
       cout << "As a decimal: " << answer << endl;
    else
       cout << "Zero denominator" << endl;
     
    Rational fract6(8,10);              // Set new fraction to 8/10    
    Rational fract7;
    
    // Test multiplying 2/3 by 8/10
    fract7 = fract5 * fract6;           
    fract7.Write();
    
    // Test dividing 2/3 by 8/10
    fract7 = fract5 / fract6;           
    fract7.Write();
    
    // Test adding 2/3 to 8/10
    fract7 = fract5 + fract6;           
    fract7.Write();
    
    // Test adding 2/3 minus 8/10
    fract7 = fract5 - fract6;           
    fract7.Write();
    system("pause");
    return 0;
}


