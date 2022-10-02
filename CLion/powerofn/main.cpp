#include <iostream>

int pow(int base, int power) {
    if (power == 0) {
        return 1;
    } else {
        return base * pow(base, power - 1);
    }
}

int main() {
    int n;
    int exp;

    std::cin >> n;
    std::cin >> exp;
    std::cout << pow(n, exp) << std::endl;
    return 0;
}
