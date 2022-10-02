#include <iostream>

using namespace std;

bool isSorted(int arr[])
{
    bool returnVal = true;
    for (int i = 0; i < sizeof(arr); i++)
    {
        if (arr[i] > arr[i + 1])
        {
            returnVal = false;
            break;
        }
    }
    return returnVal;
}

int main(int argc, char const *argv[])
{
    int myArr[5] = {5, 4, 2, 3, 1};
    int myArrTwo[5] = {1, 2, 3, 4, 5};
    cout << isSorted(myArr) << endl;
    cout << isSorted(myArrTwo) << endl;
    return 0;
}
