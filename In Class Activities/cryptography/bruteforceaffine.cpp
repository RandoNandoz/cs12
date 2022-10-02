#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;

struct pair
{
    int a;
    int b;
};


int get_modular_inverse(int a, int b) {
    for (int i = 1; i < b; ++i) {
        if (((a % b) * (i % b)) % b == 1) {
            return i;
        }
    }
    return 1;
}


// roses are red
// violets are blue
// i love hash data structures
// and so should you
void get_freqs(char chars[], int len) {
    map <char, int> map;

    for (int i = 0; i < chars[i]; ++i) {
        if (map.find(chars[i]) == map.end()) {
            map[chars[i]] = 1;
        } else {
            map[chars[i]]++;
        }
    }
    
    for (auto &it : map) {
        cout << it.first;
        cout << it.second;

        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    char first_most_common = 'E';
    char second_most_common = 'T';
    ifstream fin(R"(C:\Users\1257035\OneDrive - Board of Education of SD 39 (Vancouver)\Documents\Computer Science 12\In Class Activities\cryptography\cryptanalysis.txt)");
    ofstream fout("plaintextanalysis.txt");
    char *array_of_chars_in_input;
    int file_len = 0;
    char c;
    while (fin.get(c)) {
        file_len++;
    }

    array_of_chars_in_input = new char[file_len];

    fin.clear();
    fin.seekg(0);

    for (int i = 0; i < file_len; ++i) {
        fin.get(c);
        array_of_chars_in_input[i] = c;
    }
    
    get_freqs(array_of_chars_in_input, file_len);
    return 0;
}
