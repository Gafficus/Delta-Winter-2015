// This program is a test driver for the Rational class
#include <iostream>
using namespace std;

#include "Rational.h"

int main()
{     
    double answer;

    Rational fract;                     // Invoke default constructor
    fract.Write();
    
    Rational fract2(6,8);               // Invoke parameterized constructor
    fract2.Write();    
    
    fract2.Reduce();                    // Reduce 6/8 to 3/4
    fract2.Write();
    
    if (fract2.IsValidFract() )         // Write 3/4 as a decimal
    {
       answer = fract2.FractToDec();    
       cout << "As a decimal: " << answer << endl;
    }
    else
       cout << "Zero denominator" << endl;
    
    Rational fract3(6,1);               // Test writing 6/1 as just 6
    cout << fract3.GetNum() << "/" << fract3.GetDenom() << " written as ";
    fract3.Write();    
    
    Rational fract4(6,0);               // Test error feature for zero denominators
    cout << fract4.GetNum() << "/" << fract4.GetDenom() << " written as ";
    fract4.Write(); 
    
    if (fract4.IsValidFract() )         // Write 6/0 as a decimal; test zero feature
    {
       answer = fract4.FractToDec();    
       cout << "As a decimal: " << answer << endl;
    }
    else
       cout << "Zero denominator" << endl;
        
    Rational fract5(2,3);              
    if (fract5.IsValidFract() )         // Write 2/3 as a decimal
    {
       answer = fract5.FractToDec();    
       cout << "As a decimal: " << answer << endl;
    }
    else
       cout << "Zero denominator" << endl;
     
    Rational fract6(8,10);      
    Rational fract7;
    fract7 = fract5.Multiply(fract6);   // Test multiplying 2/3 by 8/10
    fract7.Write();
    fract7.Reduce();                    // Reduce result of multiplication
    fract7.Write();
    system("pause");
    return 0;
}


