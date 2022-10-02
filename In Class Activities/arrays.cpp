#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string name[3];
    // int total = 0;
    name[0] = "Peter";
    name[1] = "Jane";
    name[2] = "Joe";

    // for (int i = 0; i < 3; i++)
    // {
    //     string buf = name[i];
    //     name[i + 1] = buf;
    // }
    
    // }
    
    for (auto item : name) {
        cout << item << endl;
    }
    return 0;

    // // lazy way of printing an array lol
    // // for_each(name, name+sizeof(name), [](string s){cout << s << endl;});

    // // nested loops

    // // for (int i = 0; i < 3; i++)
    // // {
    // //     cout << name[i] << endl;
    // //     for (int j = 2; j > 0; j--)
    // //     {
    // //         cout << name[j] << " ";
    // //     }
    // // }
    
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 10; j < 12; j++)
    //     {
    //         total += j * i;
    //     }
        
    // }

    // cout << total << endl;
    // // Swap the first two values in array without using "".


    
}
