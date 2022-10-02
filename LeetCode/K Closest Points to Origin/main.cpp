#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<vector<int>> kClosest(const vector<vector<int>> &points, const int k) {
    vector<vector<int>> resultingPairs;
    resultingPairs.reserve(k * sizeof(int) * 2);
    vector<double> distances;
    map<double, vector<int>> distancePointMap;
    for (auto &&point: points) {
        distancePointMap[sqrt(pow(point[0], 2) + pow(point[1], 2))] = point;
    }
    distances.reserve(k * sizeof(double));

    for (auto &&pair: distancePointMap) {
        if (distances.size() != k) {
            distances.emplace_back(pair.first);
        } else {
            break;
        }
    }

    for (int i = 0; i < k; ++i) {
        resultingPairs.emplace_back(distancePointMap[distances[i]]);
    }

    return resultingPairs;
}

int main() {
    vector<vector<int>> x = {{0, 1},
                             {1, 0}};
    auto res = kClosest(x, 2);
    for (auto &&v: res) {
        for (auto &&e: v) {
            cout << e << endl;
        }
    }

    return 0;
}
