#include <iostream>
#define ull unsigned long long

inline ull iterative_factorial(const ull &n) {
    ull res = 1;

    for (int i = 2; i <= n; ++i) {
        res *= i;
    }

    return res;
}

inline ull recursive_factorial(const ull &n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return recursive_factorial(n - 1) * n;
    }
}

int main() {
    ull n;
    std::cin >> n;
//    std::cout << iterative_factorial(n) / 2 << std::endl;
    std::cout << recursive_factorial(n) << std::endl;
    return 0;
}
