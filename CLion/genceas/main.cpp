#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
// randy zhu
// 2021-11-23
// encrypts an affine cipher of any rotation and shift, where: ciphertext = (rotation * plaintext + s) mod 26

#include <iostream>
#include <fstream>

// literal magic lol
int gcf(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// checks if two numbers are coprime
bool isCoprime(int a, int b) {
    int g = gcf(a, b);
    if (g == 1) {
        return true;
    }
    return false;
}

int main() {
    std::ifstream in(
            R"(./input.txt)");
    std::ofstream out(
            R"(./output.txt)");
    int rotate = -1;
    int shift = -1;

    if (in.fail() || out.fail()) {
        std::cout << "I/O Failure" << std::endl;
        return 1;
    }

    while (!isCoprime(rotate, 26)) {
        std::cin >> rotate;
        std::cin >> shift;
    }
    char c;
    while (in.get(c)) {
        if ('A' <= c && c <= 'Z') {

            c = (rotate * (c - 'A') + shift) % 26 + 'A';
        }
        out << c;
    }

    return 0;
}

#pragma clang diagnostic pop