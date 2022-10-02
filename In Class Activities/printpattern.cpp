/*
    Name: Randy Zhu
    Date: 2021-09-27
    Purpose: Print a pattern with a provided number of lengths and a provided character.
    */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Two vars, one for the times to print, and the second for the character to print.
    int timesToPrint;
    char characterToPrint;

    // Capture the user input.
    cin >> timesToPrint;
    cin >> characterToPrint;

    // Iterate through the times to print.
    for (auto index = 1; index <= timesToPrint; index++)
    {
        // For each iteration, print the character <index> times.
        for (auto jindex = 1; jindex <= index; jindex++)
        {
            cout << characterToPrint;
        }
        // Newline because why not.
        cout << endl;        
    }
    
    return 0;
}

