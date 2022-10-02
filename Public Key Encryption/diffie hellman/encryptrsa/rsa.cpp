#include <iostream>
#include <fstream>
#include <limits>

typedef unsigned long long int ull;
// literal magic lol
ull gcf(ull a, ull b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// checks if two numbers are coprime
bool isCoprime(const ull &a, const ull &b)
{
    int g = gcf(a, b);
    if (g == 1)
    {
        return true;
    }
    return false;
}

ull getPublicKey(const ull &p, const ull &q)
{
    for (int i = 1; i <= std::numeric_limits<ull>::max(); i++)
    {
        if (isCoprime(i, (p - 1) * (q - 1)))
        {
            return i;
        }
    }
}
// unsigned modular exponentiation on scalars
inline ull us_pow_mod(ull base, ull exp, ull mod)
{
    // result is one
    ull res = 1;

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
    std::ifstream inFile(R"(C:\Users\Randy\OneDrive - Board of Education of SD 39 (Vancouver)\Documents\Computer Science 12\Public Key Encryption\diffie hellman\encryptrsa\plaintextrsaencrypt.txt)");
    std::ofstream outFile(R"(C:\Users\Randy\OneDrive - Board of Education of SD 39 (Vancouver)\Documents\Computer Science 12\Public Key Encryption\diffie hellman\encryptrsa\ciphertextrsaoutput.txt)");

    if (inFile.fail() || outFile.fail())
    {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    // p is 10039
    // q = 10037
    ull p;
    ull q;
    ull r;
    ull s;
    char readChar;
    // std::cin >> r;
    // std::cin >> s;
    
    std::cin >> p;
    std::cin >> q;
    r = p * q;
    s = getPublicKey(p, q);
    while (inFile.get(readChar))
    {
        ull positionInAlphabet = static_cast<int>(readChar);
        outFile << us_pow_mod(positionInAlphabet, s, r);
        outFile << " ";
    }

    return 0;
}
