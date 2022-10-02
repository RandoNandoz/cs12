#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int computingPower = 1;
    for (int i = 1980; i < 2001; i += 3)
    {
        cout << i << "\t" << (computingPower *= 4) << endl;
    }
    return 0;
}
