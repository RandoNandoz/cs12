// Randy Zhu
// 2021-11-22
// Purpose: count chars and words in file

#include <iostream>
#include <fstream>

int main() {
    std::ifstream in(
            R"(C:\Users\Randy\OneDrive - Board of Education of SD 39 (Vancouver)\Documents\Computer Science 12\CLion\file2\file2.in)");
    std::ofstream out(
            R"(C:\Users\Randy\OneDrive - Board of Education of SD 39 (Vancouver)\Documents\Computer Science 12\CLion\file2\file2.out)");
    int char_counter = 0;
    int word_counter = 1;
    char prev_char = -1;
    if (!in.fail()) {
        char c;
        while (in.get(c)) {
            if ((c == ' ' || c == '\t' || c == '\n') && (prev_char != ' ' && prev_char != '\t' && prev_char != '\n')) {
                word_counter++;
            }

            if (c != '\n') {
                char_counter++;
            }
            prev_char = c;
        }
    } else {
        std::cout << "input output error :(" << std::endl;
    }

    out << "there are: " << word_counter << " words" << std::endl;
    out << "there are: " << char_counter << " chars" << std::endl;
    return 0;
}
