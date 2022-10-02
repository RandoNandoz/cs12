/*
 * Randy Zhu
 * 2021-12-15
 * Encrypts RSA cipher with values r and s, where the public key is the pair (r, s).
 * */

#include <iostream>
#include <fstream>

typedef long long ull;

using std::cout;
using std::cin;
using std::endl;

ull modularPower(ull base, ull exp, const ull &mod) {
    // base^exp mod mod
    ull result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
}

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    if (in.fail() || out.fail()) {
        cout << "Failed to open file" << endl;
        return 1;
    }

    ull r;
    ull s;
    char readChar;

    cout << "Enter r: ";
    cin >> r;
    cout << "Enter s: ";
    cin >> s;

    while (in.get(readChar)) {
        out << modularPower(readChar, s, r) << " ";
    }

    return 0;
}
