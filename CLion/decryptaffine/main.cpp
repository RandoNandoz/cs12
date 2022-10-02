// randy zhu
// 2021-11-23
// decrypts affine cipher of any rotation and shift, where: ciphertext = (rotation * plaintext + s) mod 26
// basically does the reverse lmao

#include <iostream>
#include <fstream>

using namespace std;

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
bool is_coprime(int a, int b) {
    int g = gcf(a, b);
    if (g == 1) {
        return true;
    }
    return false;
}

// gets the modular inverse of a and b
int get_modular_inverse(int a, int b) {
    for (int i = 1; i < b; ++i) {
        if (((a % b) * (i % b)) % b == 1) {
            return i;
        }
    }
    return 0;
}


int main() {
    ifstream in("./input.txt");
    ofstream out("./output.txt");

    int rotate = 2;
    int shift = 0;

    while (!is_coprime(rotate, 26)) {
        cout << "please input a rotate value: ";
        cin >> rotate;
    }

//    cout << get_modular_inverse(3, 26);

    cout << "please input a shift value: ";
    cin >> shift;
    char c = -1;
    while (in.get(c)) {
//        if ('A' <= c && c <= 'Z') {
//            int pos_char_in_alphabet = c - 'A';
//            pos_char_in_alphabet -= shift;
//            while (pos_char_in_alphabet % rotate != 0 || pos_char_in_alphabet < 0) {
//                pos_char_in_alphabet += 26;
//            }
//            c = (pos_char_in_alphabet / rotate) % 26 + 'A';
//        }
        if ('A' <= c && c <= 'Z') {
            int pos_char_in_alphabet = c - 'A';
            c = ((get_modular_inverse(rotate, 26) * (pos_char_in_alphabet - shift)) % 26);

            if (c < 0) {
                c += (26 + 'A');
            } else {
                c += 'A';
            }
        }
        out << c;
    }

    return 0;
}

