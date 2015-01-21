// This program demonstrates overloaded functions by
// including multiple functions for summing values as
// well as swapping values

#include <iostream>
using namespace std;

// Function prototypes
void swap (int& x, int& y);
void swap (double& x, double& y);
void swap (char& x, char& y);
int sum(int num1, int num2);
int sum(int num1, int num2, int num3);
int sum(int num1, int num2, int num3, int num4);

int main()
{
   // Demonstrate swapping
   int val1 = 3;
   int val2 = 5;   
   cout << "Value 1: " << val1 << "   Value 2: " << val2 << endl;
   
   swap(val1,val2);
   cout << "Value 1: " << val1 << "   Value 2: " << val2 << endl;

   cout << "The sum of 2+3+4+5 is: " << sum(2,3,4,5) << endl << endl;
   
   return 0;
}


// This swaps the contents of two integers
void swap (int& x, int& y)
{ 
   int temp = x;
   x = y;
   y = temp;
}

// This swaps the contents of two floating point values
void swap (double& x, double& y)
{ 
   double temp = x;
   x = y;
   y = temp;
}

// This swaps the contents of two character values
void swap (char& x, char& y)
{ 
   char temp = x;
   x = y;
   y = temp;
}

// Summing 2 values
int sum(int num1, int num2)
{
   return num1 + num2;
}

// Summing 3 values
int sum(int num1, int num2, int num3)
{
   return num1 + num2 + num3;
}

// Summing 4 values
int sum(int num1, int num2, int num3, int num4)
{
   return num1 + num2 + num3 + num4;
} 
