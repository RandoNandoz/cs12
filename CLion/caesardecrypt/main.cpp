// randy zhu
// 2021-11-23
// decrypts a caesar cipher of any shift

#include <iostream>
#include <fstream>

int main() {
    std::ifstream in("./ciphertext.txt");
    std::ofstream out("./plaintext.txt");
    char c = -1;
    int shift = -1;

    while (!((shift >= 0) && (shift <= 26))) {
        std::cin >> shift;
    }

    while (in.get(c)) {
        char write;
        if ('A' <= c && c <= 'Z') {
            write = (char) ((c - shift) % ('Z' + 1));
            if (write < 'A') {
                write += 26;
            }
            out << write;
        } else {
            out << c;
        }
    }
    return 0;
}
