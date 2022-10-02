#include <iostream>

// climb fn
int climb(int n) {
    if (n > 1) {
        // base cases
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        // you can either skip or go
        return climb(n - 1) + climb(n - 2);
    }
    return 0;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << climb(n) << "\n";
    return 0;
}
