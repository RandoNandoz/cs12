#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int leg1 = 0;
    int leg2 = 0;
    int leg3 = 0;
    int hyp = 0;

    cin >> leg1;

    cin >> leg2;

    cin >> leg3;

    // find the hypotenuse
    if ((leg1 > leg2) && (leg1 > leg3))
    {
        hyp = leg1;
        if ((hyp * hyp) == (leg2 * leg2) + (leg3 * leg3))
        {
            cout << "Right Triangle";
        }
        else if (leg2 == leg3)
        {
            cout << "Acute Triangle";
        }
        else
        {
            cout << "Obtuse Triangle";
        }
    }
    else if ((leg2 > leg1) && (leg2 > leg3))
    {
        hyp = leg2;
        if ((hyp * hyp) == (leg1 * leg1) + (leg3 * leg3))
        {
            cout << "Right Triangle";
        }
        else if (leg1 == leg3)
        {
            cout << "Acute Triangle";
        }
        else
        {
            cout << "Obtuse Triangle";
        }
    }
    else if ((leg3 > leg2) && (leg3 > leg1))
    {
        hyp = leg3;
        if ((hyp * hyp) == (leg2 * leg2) + (leg1 * leg1))
        {
            cout << "Right Triangle";
        }
        else if (leg2 == leg1)
        {
            cout << "Acute Triangle";
        }
        else
        {
            cout << "Obtuse Triangle";
        }
    }
    else
    {
        cout << "Acute Triangle";
    }
}
