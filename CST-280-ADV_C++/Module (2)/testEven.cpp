// This program uses a function that returns true or false.
#include <iostream>
using namespace std;

// Function prototype
bool isEven(int);

int main()
{
    int val;

    cout << "Enter an integer and I will tell you ";
    cout << "if it is even or odd: ";
    cin >> val;
    if (isEven(val))
        cout << val << " is even.\n";
    else
        cout << val << " is odd.\n";
    return 0;
}

//*****************************************************************
// Definition of function isEven. This function accepts an        *
// integer argument and tests it to be even or odd. The function  *
// returns true if the argument is even or false if the argument  *
// is odd. The return value is an bool.                           *
//*****************************************************************
bool isEven(int number)
{
    bool status;

    if (number % 2)
        status = false;       // number is odd if there's a remainder.
    else
        status = true;        // Otherwise, the number is even.
    return status;
} 
