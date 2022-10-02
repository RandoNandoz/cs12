#include <iostream>
#include <fstream>
#include <string>

int main() {
    // i stands for input
    // o stands for output
    // hence, i/o is input/output.

    std::ofstream outFile("output.txt");  // create an output file uwu

    std::ifstream inFile("input.txt");
    char symbol;
    std::string str;

    if (inFile.fail()) {
        std::cout << "Sorry, but could not open the input file" << std::endl;
        // stops execution.
        return 0;
    }

//    while (inFile >> symbol) {
//        std::cout << symbol;
//    }
//
//    while (inFile.get(symbol)) {
//        std::cout << symbol;
//    }

    while (inFile >> str) {
        std::cout << str << "";
    }
//    std::cout << "The first character in the file is: " << symbol << std::endl;
    outFile << "It is raining outside" << "\n"; // write to the output file.
    return 0;

    // assignment
    // save as file1.cpp
    // input file: file1.in
    // output username.out
    // capital all the letters of the input file

    /// assignment number 2
    // save as file2.cpp
    // input file: file2.in
    // outputfile: file2.out
    // count number of chars in the file, and the number of words.
    // a word is a sequence of characters separated by a space.
}
