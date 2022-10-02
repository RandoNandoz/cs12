#include <iostream>

#define ull unsigned long long
inline ull unsigned_power(ull &base, ull &exp) {
    ull res = 1;
    while (exp != 0) {
        if (exp % 2 != 0) {
            res *= base;
        }
        exp = exp / 2;
        base *= base;
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    const ull ONE_MILLION_AND_SEVEN = 1000000007;
    ull t;
    std::cin >> t;
    for (ull i = 0; i < t; ++i) {
        ull base;
        ull exp;
        ull out;
        std::cin >> base;
        std::cin >> exp;
        out = unsigned_power(base, exp);
        std::cout << (out % ONE_MILLION_AND_SEVEN) << "\n";
    }

    return 0;
}
