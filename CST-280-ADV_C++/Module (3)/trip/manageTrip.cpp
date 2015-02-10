// Trip class test driver
// This program demonstrates a various methods related to the 
// general trip class.

#include <iostream>
using namespace std;

#include "trip.h"

int main()
{     
    // -----------------------------------------------------------
    // TEST GENERAL CLASS USAGE
    
    
    Trip theTrip;    // Trip is the CLASS; theTrip is the OBJECT    
    
    double dist,gal,hrs  ;        // Work variables within main
    
    // Prompt user for dimensions of circle
    cout << "Enter distance of trip: ";
    cin >> dist;
    cout << "Enter fuel used on trip: ";
    cin >> gal;
    cout << "Enter time required for trip: ";
    cin >> hrs;
    
    // Set data in the object
    theTrip.setDistance(dist);
    theTrip.setFuel(gal);
    theTrip.setTime(hrs);
  
    // Calculate average mileage and speed values
    cout << endl;
    cout << "For a trip of:" << endl;
    cout << "of        " << theTrip.getDistance()  << " miles"      << endl;
    cout << "using     " << theTrip.getFuel()      << " gallons"    << endl;
    cout << "requiring " << theTrip.getTime()      << " hours"      << endl;
    cout << "yields:       " << theTrip.calcMPG()   << " miles/gal" << endl;
    cout << "and moved at: " << theTrip.calcSpeed() << " mph"       << endl;
    cout << endl << endl;
    
    // -----------------------------------------------------------
    // TEST CONSTRUCTORS
    
    Trip tripObj1;              // 1st object: call default constructor
    Trip tripObj2(200,10,4);    // 2nd object: call parameterized constructor
    
    // View first object
    cout << "Data for object instantiated using default constructor: " << endl;
    cout << "Distance: " << tripObj1.getDistance() << endl;
    cout << "Fuel:     " << tripObj1.getFuel() << endl;
    cout << "Time:     " << tripObj1.getTime() << endl;
    
    // For second object
    // Calculate mileage and speed and write results to console
    cout << endl;
    cout << "For a trip of:" << endl;
    cout << "of        " << tripObj2.getDistance()  << " miles"      << endl;
    cout << "using     " << tripObj2.getFuel()      << " gallons"    << endl;
    cout << "requiring " << tripObj2.getTime()      << " hours"      << endl;
    cout << "yields:       " << tripObj2.calcMPG()   << " miles/gal" << endl;
    cout << "and moved at: " << tripObj2.calcSpeed() << " mph"       << endl;
    cout << endl << endl;
    
    system("pause");
    return 0;
    
}  // end main function

