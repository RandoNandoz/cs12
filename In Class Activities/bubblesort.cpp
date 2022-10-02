#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    // Let's get an array!
    int ints[5];

    // for (int i = 0; i < 5; i++)
    // {
    //     // for (int j = 0; j < i + 1; j++)
    //     // {
    //         if (ints[j] > ints[j + 1])
    //         {
    //             int buf = ints[j];
    //             ints[j] = ints[j + 1];
    //             ints[j + 1] = buf;
    //         }
    //     // }
    // }
    for (int i = 0; i < 5; i++)
    {
        cin >> ints[i];
    }
    
    // Bubble sort
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (ints[j] > ints[j + 1])
            {
                int buf = ints[j];
                ints[j] = ints[j + 1];
                ints[j + 1] = buf;
            }
            for (auto &&i : ints)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // for (int i = 0; i < 4; i++)
    // {
    //     if (ints[i] > ints[i + 1])
    //     {
    //         int buf = ints[i];
    //         ints[i] = ints[i + 1];
    //         ints[i + 1] = buf;
    //     }
    // }

    // for (int i : ints)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    return 0;
    // vs
}
