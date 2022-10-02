#pragma GCC optimize("Ofast")
#pragma GCC target("arch=skylake")

#include <iostream>
#include <vector>

using namespace std;

#define ull unsigned long long

inline ull fib(ull n) {
    vector<ull> lut = {0, 1};

    for (ull i = 2; i <= n; ++i) {
        lut.push_back((lut[i - 1] + lut[i - 2]) % 1000000007);
    }
    return lut[n];
}
int main() {
    int cases;

    cin >> cases;

    for (int _ = 0; _ < cases; _++) {
        ull n;
        cin >> n;
        cout << fib(n) << endl;
    }
    return 0;
}
