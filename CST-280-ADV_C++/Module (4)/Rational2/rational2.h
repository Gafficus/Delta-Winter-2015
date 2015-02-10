// This class defines a data type allowing a user to store
// a fraction (integer numerator and denominator).
class Rational
{
    private:
        int numerator;
        int denominator;
        
        // Find greatest common divisor of numerator and denominator
        // of fraction.  A utility function; not a class member.
            int GCD(int m, int n);

    public:
        // Default constructor
            Rational();
        // Parameterized constructor
            Rational(int num, int denom);
        // Write current fraction to console output
            void Write();
        // Simplify current fraction by dividing numerator and denominator
        // by greatest common divisor
            void Reduce();
        // Return decimal equivalent of current fraction. If the denominator
        // is zero, boolean flag turned off, otherwise on.
            void FractToDec(double& outDec, bool& valid);
        // MULTIPLY current fraction by another object passed in
        // as parameter.  Result returned as fraction object.
            Rational operator* (Rational oper);
        // DIVIDE current fraction by another object passed in
        // as parameter.  Result returned as fraction object.
            Rational operator/ (Rational oper);
        // ADD current fraction by another object passed in
        // as parameter.  Result returned as fraction object.
            Rational operator+ (Rational oper);
        // SUBTRACT current fraction by another object passed in
        // as parameter.  Result returned as fraction object.
            Rational operator- (Rational oper);
        // Return numerator 
            int GetNum();
        // Return denominator
            int GetDenom();
};
 
 
