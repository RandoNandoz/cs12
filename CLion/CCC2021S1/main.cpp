#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int cases;
    std::cin >> cases;
    std::vector<int> heights = {};
    std::vector<int> widths = {};
    double area = 0;

    for (int i = 0; i < (cases + 1); ++i) {
        int input;
        std::cin >> input;
        heights.push_back(input);
    }

    if (heights.size() <= 1) {
        return 1;
    } else {
        for (int i = 0; i < cases; ++i) {
            int input;
            std::cin >> input;
            widths.push_back(input);
        }
    }

    for (int i = 0; i < heights.size() - 1; ++i) {
        area += (static_cast<double>(heights[i]) + static_cast<double>(heights[i + 1]) / 2.0) * widths[i];
        double left_side = heights[i];
        double right_side = heights[i + 1];
        width = widths[i];

        area +=
    }

    std::cout << area << std::endl;
    return 0;
}
