/*
    Name: Randy Zhu
    Date: 2021-09-27
    Purpose: Find whether a number, inputted is prime.
    */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Input number variable.
    int inputNumber;

    // A boolean variable to store whether the input is prime. It is true by default so that the program runs to check whether it's false.
    bool isPrime = true;

    // Take input.
    cin >> inputNumber;

    // A prime number is number where its only divisors are 1 and itself.

    // We do an exclusion for loop through the value of the number, starting from 2 and up to the number itself, but not including the number itself.
    // x = I btw
    for (auto search = 2; search < inputNumber; search++)
    {
        // If there's no remainder, then the number has a factor.
        if (inputNumber % search == 0)
        {
            // Set isPrime to false, and then break out of the loop.
            isPrime = false;
            // This makes our program faster!
            // Thanks Kayla!
            break;
        }
    }

    // If ispPrime is false, then say it isn't prime.
    if (isPrime == false)
    {
        cout << "NOT PRIME" << endl;
    }
    else
    {
        cout << "PRIME" << endl;
    }

    return 0;
}
