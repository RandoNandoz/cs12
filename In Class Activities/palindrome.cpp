#include <iostream>
#include <string>

int abs(int x)
{
    if (x < 0)
    {
        return -x;
    }
    else
    {
        return x;
    }
}

bool is_palidrome(std::string str, int left_side)
{
    if (str.length() <= 1)
    {
        return true;
    }
    else
    {
        // the right side of the search
        // imagine we start at the first page, and this is a book.
        // left_side is the page, counting from the left, or cover side of the book.
        // right side, is the page, counting from the right, or back side of the book.
        int right_side = abs(left_side - (str.length() - 1));

        if (left_side > right_side)
        {
            return true;
        }
        if (str[left_side] == str[right_side])
        {
            return is_palidrome(str, left_side + 1);
        }
        else
        {
            return false;
        }
    }
}

int main(int argc, char const *argv[])
{
    std::string str;
    std::cin >> str;

    std::cout << is_palidrome(str, 0) << "\n";

    return 0;
}
