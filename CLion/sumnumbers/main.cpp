#include <iostream>

int main() {
    long long t;
    std::cin >> t;
    long long i = 0;
    while (i < t) {
        long long upto;
        long long sum;
        std::cin >> upto;
        sum = (upto * (upto + 1)) / 2;
        std::cout << sum << std::endl;
        ++i;
    }
}
