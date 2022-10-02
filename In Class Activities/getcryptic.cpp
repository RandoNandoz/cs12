    /*
        Name: Randy Zhu
        Date: 2021-09-27
        Purpose: Obfuscate a string by moving it -27 in terms of ascii characters.
        */
    #include <iostream>
    #include <string>

    using std::cout;
    using std::cin;
    using std::string;

    // Absolute value function.
    int abs(int x)
    {
        // Pretty straightforward.
        int abs;
        
        // If x is negative, make it positive by multiplying it by -1.
        if (x < 0)
        {
            abs = -x;
        }
        // Otherwise it'll be positive, so just return the value of x.
        else
        {
            abs = x;
        }

        return abs;
    }

    int main(int argc, char const *argv[])
    {
        // Value for lower case a as an ASCII value minus 1. We need this for moving the number of characters.
        const int ASCII_A_SUB_ONE = 96;

        // Value for the length of the alphabet plus one. 27 in this case.
        const int LEN_ALPHA_PLUS_ONE = 27;

        // Use it to store the hackerrank var.
        int stringLen;
        // Var for the string to obfuscate.
        string stringToObfuscate;

        // Take the first variable from hackerrank, and discard it due to it being useless.
        cin >> stringLen;

        // Then take the string to obfuscate.
        cin >> stringToObfuscate;

        // Foreach through the string to obfuscate.
        for (int i = 0; i < stringLen; i++)
        {
            // Get the position of the character on the alphabet. In this case, we subtract by the location of a on the alphabet minus 1, as ASCII starts counting from 0.
            int alphabetPosition = stringToObfuscate[i] - ASCII_A_SUB_ONE;

            // Then, calculate the new position of the variable by adding the length of the alphabet plus one to the old position.
            // Take the absolute value of the new position, as the new character, if un abs'ed, would be negative.
            int newAlphabetPosition = abs(alphabetPosition - LEN_ALPHA_PLUS_ONE);

            // Find the new character by adding the new position to the ASCII value of a plus one.
            char newCharacter = newAlphabetPosition + ASCII_A_SUB_ONE;

            // Print the new character!
            cout << newCharacter;
        }
        return 0;
    }
