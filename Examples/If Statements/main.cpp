#include <iostream>
#include <string>
using namespace std;

// If else, else if and else.

// Relational operators: <, >, <=, >=, ==, !=, lesser, greater, lesser than or equal to, greater than or equal to, equal to, not equal to. respectively

// Logical operators: &&, ||, !, and, or, not. respectively

int main(int argc, char const *argv[])
{
    int sleep;
    string place;

    cout << "How many hours of sleep did you get?: ";
    cin >> sleep;

    if (sleep < 8)
    {
        cout << "You need more sleep!"
             << "\n";
    }
    else if (sleep == 7)
    {
        cout << "Holy that's not a lot of sleep!";
    }
    else if (sleep > 8 && sleep < 12)
    {
        cout << "You're well rested!"
             << "\n";
    }
    else
    {
        cout << "You've had too much sleep you lazy bum!"
             << "\n";
    }
    return 0;
}
