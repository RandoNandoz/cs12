#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int ints[5] = {5, 4, 3, 2, 1};
    // Go through array.
    #pragma omp parallel for
    for (int i = 0; i < 5; i++)
    {
        if (ints[0] > ints[i]) {
            int buf = ints[0];
            ints[0] = ints[i];
            ints[i] = buf;
        }
    }

    for (auto &&i : ints)
    {
        cout << i << endl;
    }

    return 0;
}
