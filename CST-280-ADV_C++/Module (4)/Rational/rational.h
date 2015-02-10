// This class defines a data type allowing a user to store
// a fraction (integer numerator and denominator).

class Rational
{
    private:
        int numerator;
        int denominator;

    // Utility to find greatest common divisor of two integers
    // Used by function to reduce fraction
        int GCD(int, int);
        
    public:
    // Constructors  
        Rational();                   // Default constructor
        Rational(int num, int den);   // Parameterized constructor
            
    // Set/get functions
        int GetNum();
        int GetDenom();
        void SetNum(int num);
        void SetDenom(int dem);
            
    // Fraction work functions
        void Reduce();                         // Simplify current fraction     
        bool IsValidFract();                   // Test for non-zero denominator
        double FractToDec();                   // Return decimal equiv of current fract
        Rational Multiply(Rational operand2);  // Multiply another fraction by this fraction
        void Write();                          // Write current fraction to console output
};


