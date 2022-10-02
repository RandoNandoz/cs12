#include <iostream>
#include <vector>

using namespace std;

vector<int> shuffle(vector<int> &nums, int n) {
    vector<int> shuffled(2 * n);

    int x = 0;
    // for all the x's, move into the even parts of the array.
    for (int i = 0; i < n; ++i) {
        shuffled[x] = nums[i];
        x += 2;
    }

    x = 0;
    for (int i = n; i < 2 * n; ++i) {
        shuffled[x + 1] = nums[i];
        x += 2;
    }

    return shuffled;
}

int main() {
    vector<int> v = {1, 2, 3, 4};
    vector<int> res = shuffle(v, 2);
    for (const int x: res) {
        cout << x << endl;
    }
}