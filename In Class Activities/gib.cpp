/*
    Name: Randy Zhu
    Date: 2021-09-27
    Purpose: Find g(n), where g(n) = g(n-1) + g(n-2) + 2.
    */
#include <iostream>

using namespace std;

int main()
{
    
    // Four vars to store the function input, g(0), and g(1).
    int funcinput;
    int g_zero = 42;
    int g_one = 5;
    int g_n;

    // Take n.
    cin >> funcinput;

    // If the function's input is positive, iterate from 2 until the function input/
    if (funcinput > 1)
    {
        // Start at g(2).
        for (auto index = 2; index <= funcinput; index++)
        {
            // Assign g of n, to the zero and one.

            // This is our first line, of g(n -1), g(n-2), plus two.
            g_n = g_zero + g_one + 2;

            // Then, make the zero of the function equal to the one of the function.
            // This is because 
            g_zero = g_one;
            // Then make the one of the function the n.
            g_one = g_n;
        }
    }
    else if (funcinput == 0)
    {
        g_n = g_zero;
    }
    else
    {
        g_n = g_one;
    }

    cout << g_n;
    return 0;
}
