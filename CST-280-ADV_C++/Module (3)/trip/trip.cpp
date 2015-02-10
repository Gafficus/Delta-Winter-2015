// This file implements the member functions of the Trip class

#include "trip.h"

// Default constructor
Trip::Trip()
{
    distance = 0;
    fuel     = 0;
    time     = 0;
}

// Parameterized constructor
Trip::Trip(double d, double f, int t)
{
    distance = d;
    fuel     = f;
    time     = t;
}

// "Get" and "Set" functions
void Trip::setDistance(double d)
{
    distance = d;
}

double Trip::getDistance()
{
    return distance;
}

void Trip::setFuel(double f)
{
    fuel = f;
}

double Trip::getFuel()
{
    return fuel;
}

void Trip::setTime(int t)
{ 
    time = t;
}

int Trip::getTime()
{
    return time;
}

// This method returns the average miles per gallon
double Trip::calcMPG()
{
    return distance/fuel;
}

// This method returns the average speed
double Trip::calcSpeed ()
{
    return distance/time;
}


