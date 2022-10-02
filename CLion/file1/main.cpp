// Name: Randy Zhu
// 2021-11-22
// Purpose: Capitalize the letters in a file

#include <iostream>
#include <fstream>

int main() {
    std::ifstream in("file1.in")
    std::ofstream out("randyzhu.out")

    char c;
    if (!in.fail()) {
        while (in.get(c)) {
            if (c <= 'z' && c >= 'a') {
                out << (unsigned char) (c - 32);
            } else {
                out << c;
            }
        }
    } else {
        std::cout << "error with file" << std::endl;
    }
    return 0;
}
