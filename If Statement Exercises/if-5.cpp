/*
    Name: Randy Zhu

    Date: 2021-09-18

    Purpose: Check a user input against a plaintext variable in memory.
    */

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    // Store the password in a string.
    string password = "abcdefg";
    
    // Create a variable to store the user's password response.
    string response;

    // Ask the user for their password.
    cout << "Please input the password: ";
    // Store it in the response variable.
    cin >> response;

    // If the response matches the password, thank the user for their usage of the program.
    if (password == response)
    {
        cout << "Thank you for using me!" << endl;
    }
    
    // If it doesn't match, then tell them to go away.
    else
    {
        cout << "Go away!" << endl;
    }
    
    return 0;
}
