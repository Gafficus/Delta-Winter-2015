// This program demonstrates C++ random numbers.  It writes
// 10 random numbers to console output and then 10 random
// numbers in range 1...100
// File:  rnd.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
   // Get and report system clock time 
   time_t seconds;
   time(&seconds);
   cout << "System clock value: " << seconds << endl << endl;
   
   // Identify what constant RAND_MAX is
   cout << "10 random numbers from 1 to " << RAND_MAX << endl;
   
   // Set random number generator seed value to system clock
   srand( (unsigned int) seconds);
   
   // Generate 10 random numbers using random number generator function
   for (int i = 1; i <= 10; i++)
      cout << rand() << ' ';
      
   cout << endl << endl;    // Blank lines
   cout << "10 random numbers from 1 to 100" << endl;
   
   // Generate 10 random numbers 1...100
   for (int i = 1; i <= 10; i++)
      cout << rand() % 100 + 1 << ' ';
      
   cout << endl << endl;    // Blank line
   
   return 0;
} 
