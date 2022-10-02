/*
    Name: Randy Zhu

    Date: 2021-09-18

    Purpose: Compare the inputs of two numbers and print out the larger one.
    */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Get two numbers from the user.
    int firstNumber;
    int secondNumber;
    // cout << "Enter two numbers and I will tell you which one is greater." << endl;
    // cout << "Enter the first number now: ";
    cin >> firstNumber;
    // cout << endl
    //  << "Enter the second number: ";
    cin >> secondNumber;

    // If the first number is equal to the second number, tell the user.
    if (firstNumber == secondNumber)
    {
        cout << "SAME" << endl;
    }
    // If the first number is greater than the second, tell them that the first number is greater.
    else if (firstNumber > secondNumber)
    {
        cout << firstNumber;
    }
    // If the second number is greater than the first, tell them that the second number is greater.
    else if (secondNumber > firstNumber)
    {
        cout << secondNumber;
    }

    return 0;
}
