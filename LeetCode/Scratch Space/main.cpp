#include <iostream>

using namespace std;

int main() {
  int sum = 0;
  int *ints = new int[10];
  for (int i = 0; i < 10; i++) {
    ints[i] = i;
  }

  sum = ints[0] + ints[1] + ints[2] + ints[3] + ints[4] + ints[5] + ints[6] + ints[7] + ints[8] + ints[9];
  cout << "Sum: " << sum << endl;
  return 0;
}