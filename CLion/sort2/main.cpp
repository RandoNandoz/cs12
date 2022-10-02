#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    // Array of integers to be sorted.
    double doubles[6];

    for (double &i: doubles) {
        cin >> i;
    }

    // Loop through the array.
    for (int i = 0; i < 6; i++) {

        int pos = i;
        // Search starting from the index.
        for (int j = i; j < 6; j++) {
            // Find the smallest index.
            if (doubles[j] < doubles[pos]) {
                pos = j;
            }
        }
        double buf = doubles[i];
        doubles[i] = doubles[pos];
        if (i < 5) {
            doubles[pos] = buf;
            for (auto &&item: doubles) {
                cout << item << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
