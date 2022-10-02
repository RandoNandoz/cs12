#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    int myInt;
    cin >> myInt;
    cout << "Chemistry\t4" << endl;
    cout << "Physics\t\t8" << endl;
    cout << "English\t\t2" << endl;
    cout << "Math Lab\t12" << endl;

    cout << endl << "Grand Total\t" << ((4 + 8 + 2 + 12)/4) << endl;
    return 0;
}
