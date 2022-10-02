/*
    Name: Randy Zhu
    Date: 2021-09-27
    Purpose: Find the GCF of two numbers, factorOne and factorTwo.
    */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Get the two numbers to factor.
    int factorOne;
    int factorTwo;

    // Variable to store the factor.
    int gcf = 0;

    // Get input for two vars.
    cin >> factorOne;
    cin >> factorTwo;

    // Take the average of the two numbers plus one to get the upper bound for the search for GCFs.
    // This upperbound allows us to run the program at O(1/2n + 1) time.
    // Thanks Simone!
    auto upperBound = (factorOne + factorTwo) / 2 + 1;

    // Now, search through all the numbers from 1 to the upper bound to find the GCF.
    // This is because any number greater than the average of the two numbers will not be a GCF.
    for (auto search = 1; search <= upperBound; search++)
    {
        // Also, no need for a comparison, because the bigger number always gets displayed because of the forwards
        // iteration of the for loop.

        // Check if the search variable is a divisor of the two numbers.
        if (factorOne % search == 0 && factorTwo % search == 0)
        {
            // If it is the new GCF is the search variable!
            gcf = search;
        }
    }

    // Print the GCF.
    cout << gcf;
    return 0;
}
