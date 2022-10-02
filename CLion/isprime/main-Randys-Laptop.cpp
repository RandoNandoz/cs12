#include <iostream>

#define ull unsigned long long

int main() {
    ull cases;
    std::cin >> cases;
    for (ull i = 0; i < cases; ++i) {
        bool is_prime = true;
        ull num;
        std::cin >> num;
        if ((num % 2 != 0) && num != 1 && num != 2) {
            for (ull j = 3; j * j < num; j += 2) {
                if (num % j == 0) {
                    is_prime = false;
                    break;
                }
            }
        } else if (num == 1 || num == 2) {

        } else {
            is_prime = false;
        }
        if (is_prime) {
            std::cout << "Prime" << std::endl;
        } else {
            std::cout << "Not Prime" << std::endl;
        }
    }

    return 0;
}
