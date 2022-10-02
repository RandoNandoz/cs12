#include <iostream>

#define ull unsigned long long
inline ull us_pow_mod(ull n, ull p, const ull m) {
    ull res = 1;
    while (p != 0) {
        if (p % 2 != 0) {
            res *= n;
            res %= m;
        }
        p = p / 2;
        n *= n;
        n %= m;
    }
    return res;
}

int main() {
    [[maybe_unused]] const ull ONE_MILLION_AND_SEVEN = 1000000007;
    ull t;
    std::cin >> t;
//    for (ull _ = 0; _ < t; ++_) {
        ull base;
        ull exp;
        ull out;
        ull mod;
        std::cin >> base;
        std::cin >> exp;
        std::cin >> mod;
        out = us_pow_mod(base, exp, mod);
        std::cout << (out) << "\n";
//    }

    return 0;
}
