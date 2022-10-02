#include <iostream>
#define ever \
    ;        \
    ;

using namespace std;

int main(int argc, char const *argv[])
{
    //     // A for loop is a pre-test loop

    //     // for (initialization; condition; increment)
    //     // {
    //     //     // code to be executed
    //     // }

    //     int index, number;

    //     int total = 0;

    //     char symbol;

    //     for (index = 0; index < 3; index++)
    //     {
    //         cout << index << endl;
    //     }
    //     cout << "Nous sommes fini avec la loop, index = " << index << endl;

    //     cout << "yeet new loop" << endl;

    //     for (index = 4; index < 3; index++)
    //     {
    //         // never executes as index is always greater than 4.
    //         cout << index << endl;
    //     }

    //     cout << "yeet another new loop" << endl;

    //     for (index = 5; index >= 1; index--)
    //     {
    //         cout << index << endl;
    //     }

    //     cout << "yeet^2 another new loop" << endl;

    //     // start from 0 go up by five's up to and including 100

    //     for (int i = 0; i <= 100; i += 5)
    //     {
    //         cout << index << endl;
    //     }

    // alternative implementation
    // for (int i = 0; i < 101; i += 5)
    // {
    //     cout << i << endl;
    // }

    // multiplicative implementation
    // for (int i = 0; i <= 20; i++)
    // {
    //     cout << i * 5 << endl;
    // }

    // int summate = 0;
    // for (int i = 0; i <= 10; i++)
    // {
    // summate += i;
    // cout << summate << endl;
    // }

    // list numbers from 1 to five inclusively and say if it is even or old

    // for (auto i = 0; i <= 5; i++)
    // {
    //     if (i % 2 == 0)
    //     {
    //         cout << i << " is an even number" << endl;
    //     }
    //     else
    //     {
    //         cout << i << " is an odd number" << endl;
    //     }
    // }

    // nested loop

    for (auto index = 0; index < 2; index++)
    {
        for (auto jindex = 9; jindex > 7; jindex--)
        {
            cout << "index = " << index << ", jindex = " << jindex << endl;
        }
    }

    auto symbol = 'a'; // chars are one quote

    // string unused = "a quick brown for jumps over the lazy dog"
    // strings use doublequotes

    int number = symbol;

    cout << symbol << " has the ASCII value of: " << number << endl;

    for (auto i = 65; i < 91; i++)
    {
        symbol = i;
        cout << symbol;
    }

    cout << endl;

    for (char i = 'z'; i >= 'a'; i--)
    {
        cout << i;
    }

    for (ever)
    {
        cout << "a" << endl;
    }

    return 0;
}
