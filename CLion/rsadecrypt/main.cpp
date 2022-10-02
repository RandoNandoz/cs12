/*
 * Randy Zhu
 * 2021-12-15
 * Decrypt RSA cipher with values r and t, where (r, t) is the private key.
 */

#include <iostream>
#include <fstream>
#include <string>

typedef long long ull;

using std::cout;
using std::cin;
using std::endl;
using std::string;

ull modularPower(ull base, ull exp, const ull &mod) {
    // result is one
    ull res = 1;

    // while the exponent is not zero, if it's even, square it, then mod.
    while (exp != 0) {
        // if it's odd, we gotta factor out the a^1 and multiply it, then mod.
        if (exp % 2 != 0) {
            res *= base;
            res %= mod;
        }
        exp = exp / 2;
        base *= base;
        base %= mod;
    }
    return res;
}
int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    ull readString;
    if (in.fail() || out.fail()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    ull r;
    ull t;

    cout << "Enter the value for r: ";
    cin >> r;

    cout << "Enter the value for t: ";
    cin >> t;

    while (in >> readString) {
//        ull readStringValue = std::stoll(readString, nullptr, 10);
        out << static_cast<char>(modularPower(readString, t, r));
    }

    return 0;
}
