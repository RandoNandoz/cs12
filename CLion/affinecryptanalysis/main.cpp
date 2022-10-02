/*
 *  Randy Zhu
 *  2021-12-07
 *  Perform cryptanalysis of the affine cipher, by finding the most common characters in the ciphertext, which
 *  represent E and T, respectively, and solving for the shift and rotation values.
 * */

#include <iostream>
#include <fstream>
#include <limits>

// Define the length of the alphabet as 26.
#define LENGTH_ALPHABET 26

// Find the first, and second most common characters in the ciphertext
int *findFirstAndSecondMostCommonCharactersInCharArrayOfAlphabeticCharacters(const char chars[], const int len) {
    // The length of the alphabet.`

    // Declare an array of the length of the alphabet, to track the indices.
    int alphabetCounter[LENGTH_ALPHABET] = {0};

    // The largest, and second-largest indices of the array.
    int largestIndex = 0;
    int secondLargestIndex = 0;

    // The result, an array with two elements, the first element being the greatest and the second being the second greatest.
    static int res[2] = {0};
    // Iterate through the array, and increment the counter for each character.
    for (int i = 0; i < len; ++i) {
        if ('A' <= chars[i] && chars[i] <= 'Z') {
            int posInAlphabet = chars[i] - 'A';
            alphabetCounter[posInAlphabet]++;
        }
    }

    // Iterate through the counter array, and if the array at the position of the largest index is less than the current index,
    // then set the largest index to the current index.
    for (int i = 0; i < LENGTH_ALPHABET; ++i) {
        if (alphabetCounter[largestIndex] < alphabetCounter[i]) {
            largestIndex = i;
        }
    }

    // Set the counter at the largest index equal to the minimum value for type int, so it cannot be the greatest.
    alphabetCounter[largestIndex] = std::numeric_limits<int>::min();


    // Now that the greatest is set to the int minimum, iterate through the array again, and find the new greatest number.
    // That number is the second-largest index.
    for (int i = 0; i < LENGTH_ALPHABET; ++i) {
        if (alphabetCounter[secondLargestIndex] < alphabetCounter[i]) {
            secondLargestIndex = i;
        }
    }

    // Assign the result's indices to the indices of the alphabetCounter array, and increment the value of 'A' to convert
    // the raw positions in the alphabet into chars.
    res[0] = largestIndex + 'A';
    res[1] = secondLargestIndex + 'A';

    return res;
}

// Find the modular multiplicative inverse of a number, using guess and check.
inline int getModularMultiplicativeInverse(const int a, const int b) {
    // Iterate through 1 to the value of b, and if the remainder of a and the current value is 0, then return the current value.
    for (int i = 1; i < b; ++i) {
        if (((a % b) * (i % b)) % b == 1) {
            return i;
        }
    }
    // Otherwise, if there is no modular multiplicative inverse as the two n values are not coprime, return -1.
    return -1;
}


int main() {

    // The input and output files, named ciphertext.txt and plaintext.txt.
    std::ifstream fileIn(R"(ciphertext.txt)");
    std::ofstream fileOut(R"(plaintext.txt)");

    // Record the length of characters in the ciphertext.
    int numberOfCharsInFile = 0;

    // Create a character pointer to store the characters in the file as an array once we determine the length of the file.
    char *inputChars;

    // The current character that the file streams are reading.
    char readChar;

    // If neither files are readable, alert the user and stop execution, returning 1.
    if (fileIn.fail() || fileOut.fail()) {
        std::cout << "I/O Error" << std::endl;
        return 1;
    }

    // Count the number of characters in the file.
    while (fileIn.get(readChar)) {
        numberOfCharsInFile++;
    }

    // Create an array of length of the file
    inputChars = new char[numberOfCharsInFile];

    // Reset the file read header.
    fileIn.clear();
    fileIn.seekg(0);

    // Read the file, placing each character into the array.
    for (int i = 0; i < numberOfCharsInFile; ++i) {
        fileIn.get(readChar);
        inputChars[i] = readChar;
    }

    // Find the pairs in the array with our function defined above
    int *pair = findFirstAndSecondMostCommonCharactersInCharArrayOfAlphabeticCharacters(inputChars,
                                                                                        numberOfCharsInFile);
    // Delete the array once we're done with it.
    delete[] inputChars;


    // calculate the rotation with (P_t - P_e)_inv * (C_t - C_e)
    int rotate = (pair[1] - pair[0]) * getModularMultiplicativeInverse('T' - 'E', LENGTH_ALPHABET) % LENGTH_ALPHABET;
    // The value may be negative, so we add the length of the alphabet repeatedly to make it positive.
    while (rotate < 0) {
        rotate += LENGTH_ALPHABET;
    }
    rotate %= LENGTH_ALPHABET;

    // Calculate the shift.
    // C_e = rP_e + s
    // ergo,
    // s = C_e + rP_e
    int shift = (pair[0] - (rotate * 'E')) % LENGTH_ALPHABET;

    // Again, this value may be negative, so we'll just make it positive.
    while (shift < 0) {
        shift += LENGTH_ALPHABET;
    }

    shift %= LENGTH_ALPHABET;

    std::cout << "Rotate is: " << rotate << std::endl;
    std::cout << "Shift is: " << shift << std::endl;

    // Reset the file position.
    fileIn.clear();
    fileIn.seekg(0);

    // Read the file again, and decrypt
    // C = rP + s
    // C - s = rP
    // (C - s) * r_inv = P
    int rotationModularInverse = getModularMultiplicativeInverse(rotate, LENGTH_ALPHABET);
    while (fileIn.get(readChar)) {
        if ('A' <= readChar && readChar <= 'Z') {


            int posCharInAlphabet = readChar - 'A';
            readChar = rotationModularInverse * (posCharInAlphabet - shift) % LENGTH_ALPHABET; // NOLINT(cppcoreguidelines-narrowing-conversions)
            if (readChar < 0) {
                readChar += (LENGTH_ALPHABET + 'A');
            } else {
                readChar += 'A';
            }
        }
        fileOut << readChar;
    }
    return 0;
}
