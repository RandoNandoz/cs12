#include <iostream>

// While loop is a pre-test loop, meaning it checks if the conditions is true or false before execution.
// while (<cond>) { <code> }

using namespace std;

int main(int argc, char const *argv[])
{
    int num = 0;

    while (num < 3)
    {
        cout << num << endl;
        num++;
    }
    cout << "outside while loop, num=" << num << endl;

    num = 0;

    // never executes because num = 0, and 0 > 3 is false.

    while (num > 3)
    {
        cout << num << endl;
        num++;
    }
    cout << "outside of the second while loop, num = " << num << endl;

    // infinite loop
    num = 0;
    while (num < 3)
    {
        cout << num << endl;
    }
    
    return 0;
}
