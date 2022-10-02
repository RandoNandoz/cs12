/*
    Name: Randy Zhu

    Date: 2021-09-18

    Purpose: This program will determine whether a quadratic equation's properties, using its coefficients, a, b, and c.
    It takes in a "zeroed" 2nd degree polynomial, in standard form (0 = ax^2 + bx + c), and calculates the discriminant.

    The discriminant is the values under the square root in the quadratic formula. 
    
    The quadratic *formula*, is:
    
    -b +- sqrt(b^2 - 4ac) / 2a.

    The discriminant, is what is under the square root.

    So, it is:

    b^2 - 4ac.

    If it is positive, there are two solutions in the real set.

    If it equals zero, there is only one real solution.

    If it is lesser than zero, or negative, there are only two solutions in the complex space.
    */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Declare three variables for a b and c on the polynomial respectively.
    double a, b, c;
    
    // Create a variable to hold the discriminant, with the discriminant being the value of b squared minus 4 times the value of a times the value of c.
    double discriminant;

    // Ask the user to input the value of a, b, and c.

    // Capture user input for a, b, and c.
    cin >> a;

    cin >> b;

    cin >> c;

    // Now calculate the discriminant.
    discriminant = ((b * b) - 4 * a * c);

    // According to https://en.wikipedia.org/wiki/Discriminant, if the discriminant is positive, then the function has two real roots.
    if (discriminant > 0)
    {
        cout << "2 distinct real roots";
    }
    // If it's equal to zero, the discriminant has one root in the real set.
    else if (discriminant == 0)
    {
        cout << "1 repeated real root";
    }
    // Otherwise, if the discriminant is negative, the function has two roots in the complex plane.
    else if (discriminant < 0)
    {
        cout << "2 distinct complex roots" << endl;
    }
    return 0;
}
