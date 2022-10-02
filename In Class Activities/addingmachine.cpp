#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int x;
    int sum = 0;
    while (x != 99)
    {
        sum += x;
        cin >> x;
        // if (x == -99)
        // {
            // break;
        // }
    }
    cout << sum;
    return 0;
}
