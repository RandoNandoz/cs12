#include <iostream>

double square_root(double x) {
    double guess = x;
    double new_guess = 1.0;
    while (new_guess != guess) {
        guess = new_guess;
        new_guess = (guess + x / guess) / 2.0;
    }
    return new_guess;
}

int main() {
    std::cout << square_root(50) << std::endl;
    return 0;
}
