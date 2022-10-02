#include <iostream>
#include <fstream>

// unsigned modular exponentiation on scalars
inline unsigned int us_pow_mod(unsigned int base, unsigned int exp, unsigned mod)
{
    // result is one
    unsigned int res = 1;

    // while the exponent is not zero, if it's even, square it, then mod.
    while (exp != 0)
    {
        // if it's odd, we gotta factor out the a^1 and multiply it, then mod.
        if (exp % 2 != 0)
        {
            res *= base;
            res %= mod;
        }
        exp = exp / 2;
        base *= base;
        base %= mod;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    std::ifstream inFile(R"(C:\Users\1257035\OneDrive - Board of Education of SD 39 (Vancouver)\Documents\Computer Science 12\Public Key Encryption\diffie hellman\decryptrsa\ciphertext.txt)");
    std::ofstream outFile(R"(C:\Users\1257035\OneDrive - Board of Education of SD 39 (Vancouver)\Documents\Computer Science 12\Public Key Encryption\diffie hellman\decryptrsa\plaintext.txt)");
    if (inFile.fail() || outFile.fail()) {
        std::cout << "I/O Error" << std::endl;
    }
    std::string cipherValueOfChar;

    int t;
    int r;

    std::cin >> t;
    std::cin >> r;

    while (inFile >> cipherValueOfChar)
    {
        int cipherValueAsInt = std::stoi(cipherValueOfChar);
        outFile << static_cast<char>(us_pow_mod(cipherValueAsInt, t, r));
    }
    std::cout << std::endl;
    
    return 0;
}