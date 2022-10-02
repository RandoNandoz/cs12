#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
     // Justify right (default)
     cout << "*" << -17 << "*" << endl;

     // Adds 6 units of width.
     cout << "*" << setw(6) << -17 << "*" << endl;

     // Set justification to left - PERSISTENT UNTIL CHANGED.
     cout << left;

     // This should display 6 units to the left.
     cout << "*" << setw(6) << -17 << "*" << endl;

     // Newline.
     cout << endl;

     // Prints a regular - right justified, no spacing.
     cout << "*"
          << "Hi there!"
          << "*" << endl;

     // 20 wide, justified left, as there is a "cout << left" on the 15th line.
     cout << "*" << setw(20) << "Hi there!"
          << "*" << endl;

     // Set justification back.
     cout << right;
     cout << "*" << setw(20) << "Hi there!"
          << "*" << endl;

     cout << setw(9) << -3.25 << endl;
     cout << internal << setw(9) << -3.25 << endl;

     cout << right;
     // Setfill() example:
     cout << setfill('x') << setw(10);
     cout << 24 << endl;

     // exp 2
     cout << setfill(' ') << "default fill: " << setw(10) << 42 << "\n";
     cout << "setfill('*'): " << setfill('*') << setw(10) << 42 << "\n";

     // exp 3
     int a;
     int b;
     a = 200;
     b = 300;

     cout << setfill('*');
     for (int i = 5; i < 8; i++)
     {
          cout << setw(i) << a << setw(5) << b << endl;
     }
     
     return 0;
}
