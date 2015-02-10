// This program demonstrates various bitwise operations

#include <iostream>
#include <cmath>
using namespace std;

void dec_to_bin(int val);

int main()
{
    int val1 = 1235;
    int val2 = 19877;
    int val3;

    // Write binary values of test data
    cout << "Value 1: " << val1 << "  or "; 
    dec_to_bin(val1);
    cout << "Value 2: " << val2 << " or ";
    dec_to_bin(val2);
    
    // Test bitwise OR
    val3 = val1 | val2;
    cout << "1234 bitwise-or 19876 is: " << val3 << " or ";
    dec_to_bin(val3);
    
    // Test bitwise AND
    val3 = val1 & val2;
    cout << "1234 bitwise-and 19876 is: " << val3 << " or ";
    dec_to_bin(val3);
    
    // Test bitwise XOR (Exclusive OR)
    val3 = val1 ^ val2;
    cout << "1234 bitwise-XOR 19876 is: " << val3 << " or ";
    dec_to_bin(val3);
    
    // Test bitwise shift right
    val3 = val2 >> 1;
    cout << "19876 shift right is: " << val3 << " or ";
    dec_to_bin(val3);    
    
    // Test bitwise shift left
    val3 = val2 << 1;
    cout << "19876 shift left is: " << val3 << " or ";
    dec_to_bin(val3);    
    
    // Test bitwise shift complement
    val3 = ~val2;
    cout << "Complement of 19876 is: " << val3 << endl;
	system("pause");
    return 0;
}

// This function receives an integer and writes the binary equivalent
// to console output.  The strategy includes dividing by successive powers
// of 2 from to build binary number from high-order to low-order digits.
// Precondition:    0  < input value < 32,767 (or 2^16-1)
// Postcondition:   Input value unchanged
void dec_to_bin(int val)
{
    int digit;
        
    for (int ex = 15; ex >=0; ex--)
    {
        digit = val / int(pow(2.0,ex));   // Divide by current power of 2
        cout << digit;
        val = val % int(pow(2.0,ex));     // Extract remainder for next pass
    }
    cout << endl;
}

