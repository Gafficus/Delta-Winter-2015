// This file specifies the details of the Trip class

class Trip
{
    private:          // PRIVATE data members
        double distance;   // miles
        double fuel;       // gallons
        int    time;       // hours;

    public:           // PUBLIC member functions
        Trip();                           // Default constructor 
        Trip(double d, double f, int t);  // Parameterized constructor
       
        void   setDistance(double d);
        double getDistance();
        void   setFuel(double f);
        double getFuel();
        void   setTime(int t);
        int    getTime();
        
        double calcMPG();
        double calcSpeed ();
};
