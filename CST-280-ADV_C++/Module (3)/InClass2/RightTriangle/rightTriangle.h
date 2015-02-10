// This file defines the specifications for a class to store
// attributes of a right triangle

class RightTriangle
{
    private:                // PRIVATE data members
        double base;
        double height;
        
    public:                 // PUBLIC member functions
        
        RightTriangle();                    // Default constructor
        
        void setHeight(double h);       // SET functions
        void setBase(double b);
        
        // Calculate length of hypotenuse
        double calcHypotenuse();        
        
};