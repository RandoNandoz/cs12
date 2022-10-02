#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    // int index = 1;
    int count = 1;
    while (n >= 1)

    {
        // index *= 10;
        n = n / 10;
        // cout << n << endl;
        count++;
    }
    cout << count - 1 << endl;
    return 0;
}
