// randy zhu
// 2021-11-23
// encrypts caesar cipher of any shift

#include <iostream>
#include <fstream>

int main() {
    std::ifstream in("./input.txt");
    std::ofstream out("./output.txt");
    char c = -1;
    int shift = -1;

    while (!((shift >= 0) && (shift <= 26))) {
        std::cin >> shift;
    }

    while (in.get(c)) {
        char write;
        if ('A' <= c && c <= 'Z') {
            write = (char) ((c + shift) % ('Z' + 1));
            if (write < 'A') {
                write += ('A');
            }
            out << write;
        } else {
            out << c;
        }
    }
}
