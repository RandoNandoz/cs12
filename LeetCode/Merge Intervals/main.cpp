#include <iostream>
#include <vector>


std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
    top:
    for (unsigned int i = 0; i < intervals.size() - 1; ++i) {
        int differenceBetweenEndOfIntervalAndNextStartOfInterval = intervals[i][1] - intervals[i + 1][0];
        if ((differenceBetweenEndOfIntervalAndNextStartOfInterval >= 0) && (intervals[i][0] <= intervals[i + 1][1])) {
            intervals[i] = {std::min(intervals[i][0], intervals[i + 1][0]),
                            std::max(intervals[i][1], intervals[i + 1][1])};
            intervals.erase(intervals.begin() + (i + 1));
//            merge(intervals);
            goto top;
        }
    }
    return intervals;
}

int main() {
    std::vector<std::vector<int>> inputOne = {{1,  3},
                                              {2,  6},
                                              {8,  10},
                                              {15, 18}};
    auto resOne = merge(inputOne);
    std::vector<std::vector<int>> inputTwo = {{1, 4},
                                              {0, 0}};
    auto resTwo = merge(inputTwo);

    for (auto &&interval: resOne) {
        for (auto &&elem: interval) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (auto &&interval: resTwo) {
        for (auto &&elem: interval) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
