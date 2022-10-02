#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num_one = 10;
    int num_two = 20;

    for (int i = 0; i < 5; i++)
    {
        num_one = num_two + 5;
        num_two = num_one;
    }
    cout << num_one << endl;
    cout << num_two << endl;
    return 0;
}
