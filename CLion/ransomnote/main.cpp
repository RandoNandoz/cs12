#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main() {
    std::ifstream newspaper("./newspaper.txt");
    std::ifstream ransom_note("./ransom_note.txt");
    std::stringstream str_stream_newspaper;
    str_stream_newspaper << newspaper.rdbuf();
    std::stringstream str_stream_ransom_note;
    str_stream_ransom_note << ransom_note.rdbuf();
    std::string str_newspaper = str_stream_newspaper.str();
    std::string str_ransom_note = str_stream_ransom_note.str();

    std::cout << str_newspaper << std::endl;
    std::cout << str_ransom_note << std::endl;
    return 0;
}
