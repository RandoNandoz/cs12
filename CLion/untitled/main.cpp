#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

bool isSorted(const char arr[], const int len) {
    for (int i = 0; i < len - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    // declare an array of chars
    char arr[5];

    // take input of chars
    for (auto &i: arr) {
        cin >> i;
    }

    if (!isSorted(arr, 5)) {
        for (int i = 0; i < 5; ++i) {
            if (arr[0] > arr[i]) {
                // Bubble sort
                for (int j = 0; j < i; ++j) {
                    for (int k = 0; k < i - j; ++k) {
                        if (arr[k] > arr[k + 1]) {
                            char buf = arr[k];
                            arr[k] = arr[k + 1];
                            arr[k + 1] = buf;
                        }

                    }
                }
                // why do you not work :(
                std::for_each(std::begin(arr), std::end(arr), [](auto &&x) { cout << x; });
                cout << endl;
            }
        }
    } else {
        std::for_each(std::begin(arr), std::end(arr), [](auto &&x) { cout << x; });
        cout << endl;
    }
    return 0;
}