/*
    Name: Randy Zhu
    Date: 9/22/2021
    Purpose: Check whether a point lies in a rectangle
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int x, y, rx, ry, w, h;

    int bottomRightX;
    int bottomRightY;

    cin >> x;
    cin >> y;

    cin >> rx;
    cin >> ry;

    cin >> w;
    cin >> h;

    // Model the rectangle.

    // Calculate the xMax
    bottomRightX = rx + w;
    bottomRightY = ry - h;

    // Calulate the other points.

    int topRightX = rx + w;
    int topRightY = ry;
    
    int bottomLeftX = rx;
    int bottomLeftY = ry - h;
    if ((x == rx) || (x == topRightX) || (x == bottomLeftX) || (x == bottomRightX) || (y == rx) || (y == topRightY) || (y == bottomLeftY) || (y == bottomRightY))
    {
        cout << "On the Rectangle";
    }
    else if (((x > rx) && (x < bottomRightX)) && ((y < ry) && (y > bottomRightY)))
    {
        cout << "Inside" << endl;
    }
    else
    {
        cout << "Outside" << endl;
    }

    return 0;
}
