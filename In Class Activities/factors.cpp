/*
    Name: Randy Zhu
    Date: 2021-09-27
    Purpose: Find the numberOfFactors factors of number numberToGetFactorsOf.
    */
#include <iostream>


using namespace std;

int main(int argc, char const *argv[])
{
    // Two variables, one to get the factors of, and the second, the number of factors.
    int numberToGetFactorsOf, numberOfFactors;

    // Get input for both.
    cin >> numberToGetFactorsOf;

    cin >> numberOfFactors;

    // Print the factors of the number by multiplying by the number of factors to get.
    for (auto i = 0; i <= numberOfFactors; i++)
    {
        cout << i * numberToGetFactorsOf << " ";
    }
    
    cout << endl;
    return 0;
}
