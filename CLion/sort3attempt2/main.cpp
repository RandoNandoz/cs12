#include <iostream>
#include <algorithm>
#include <cstring>

// Function to check if array is sorted
//inline bool isSorted(const char chars[], const int len) {
//    for (int i = 0; i < len; ++i) {
//        if (chars[i] > chars[i + 1]) {
//            return false;
//        }
//    }
//    return true;
//}

inline bool isSorted(const char chars[], const int len) {
    for (int i = 0; i < len - 1; ++i) {
        if (chars[i] > chars[i + 1]) {
            return false;
        }
    }
    return true;
}

// bubble sort fn
inline void sort(char *chars, const int len) {
    // loop through array
    for (int i = 0; i < len - 1; ++i) {
        // loop through length minus i times, as we know that the sorted elements will pop to the top of the array.
        for (int j = 0; j < len - 1 - i; ++j) {
            // if the item in front of the current item is greater than the current item, switch them around.
            if (chars[j] > chars[j + 1]) {
                // swap
                char buf = chars[j];
                chars[j] = chars[j + 1];
                chars[j + 1] = buf;
            }
        }
    }
}

int main() {
    char chars[5];

    for (char &c: chars) {
        std::cin >> c;
    }

    for (int i = 0; i < 5; ++i) {
        // if the array is not sorted, begin the sorting procedure.
        if (!isSorted(chars, 5)) {
            // begin looping through the sub arrays of i, and if from zero to i, it is not sorted.
            if (!isSorted(chars, i)) {
                // sort the array!
                sort(chars, i + 1);
            }
            // also don't print the first iteration
            if (i != 0) {
                // fancy way to print array
                std::for_each(std::begin(chars), std::end(chars), [](char &c) { std::cout << c; });
                std::cout << std::endl;
            }
        } // otherwise, if it is, just print the array.
        else {
            std::for_each(std::begin(chars), std::end(chars), [](char &c) { std::cout << c; });
            std::cout << std::endl;
        }
    }
    return 0;
}
