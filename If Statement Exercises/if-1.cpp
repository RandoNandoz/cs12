/*
    Name: Randy Zhu

    Date: 2021-09-18

    Purpose: To get the absolute value of a user's input.
    */

#include <iostream>

int main(int argc, char const *argv[])
{
    // Get the user's input.

    // First, create a variable
    int userInput;
    int abs;
    // Ask the user for an input.
    std::cout << "Please enter a number to get the absolute value of: ";

    // Insert the user's input into the variable.
    std::cin >> userInput;

    // If the user's input is lesser than zero, turn it positive, by multiplying it by one.
    if (userInput < 0)
    {
        abs = -userInput;
    } else {
        abs = userInput;
    }

    // Print the new number.
    std::cout << std::endl;
    std::cout << userInput << std::endl;

    return 0;
}
