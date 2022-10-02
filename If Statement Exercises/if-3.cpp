/*
    Name: Randy Zhu

    Date: 2021-09-18

    Purpose: Calculate whether a student has passed, or failed a series of courses, by a certain criteria.
    That criteria, is that the student must either: Pass all three of the courses, which is getting >=40%,
    or get an average of 50%, with no more than 1 course under 40% (failling).
    */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // Create three variables for the marks.
    int markOne;
    int markTwo;
    int markThree;

    // Then a boolean variable to determine if the student will pass.
    bool passOrFail = false;

    // Ask the user to enter the marks.
    // cout << "Input the three percentage marks below." << endl;

    // cout << "Please input mark one: ";
    cin >> markOne;
    // cout << "Please input mark number two: ";
    cin >> markTwo;
    // cout << "Please input the last (third) mark: ";
    cin >> markThree;

    // If the marks are all greater than or equal to 40, the student will pass.
    if ((markOne >= 40) && (markTwo >= 40) && (markThree >= 40))
    {
        // Set passOrFail to true.
        passOrFail = true;
    }
    // Otherwise, we will check if the average of the three marks are greater than or equal to 50.
    else if (((markOne + markTwo + markThree) / 3) >= 50)
    {
        // If they are, we now need to check if any of the marks are less than 40, as that will cause them to fail.
        if (markOne <= 40)
        {
            // If one of the marks are lesser than forty, the other ones must be greater than or equal to 40, for the student to pass.
            if ((markTwo >= 40) && (markThree >= 40))
            {
                // Therefore, we need to set passOrFail to true.
                passOrFail = true;
            }
        }
        // Repeat for all other cases.
        else if (markTwo <= 40)
        {
            if ((markOne >= 40) && (markThree >= 40))
            {
                passOrFail = true;
            }
        }
        else if (markThree <= 40)
        {
            if ((markOne >= 40) && (markTwo >= 40))
            {
                passOrFail = true;
            }
        }
    }

    // Final check, if the user passes, then tell "Pass".
    if (passOrFail)
    {
        cout << "PASS" << endl;
    }
    // Otherwise tell them they fail.
    else
    {
        cout << "FAIL" << endl;
    }
    return 0;
}