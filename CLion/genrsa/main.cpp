/*
 * Randy Zhu
 * 2021-12-15
 * Gets the private key and public key, using p and q, which are the two prime numbers.
 * Then, it generates the public key and private key, which are of the pair:
 * Public key: (r, s)
 * Private key: (r, t)
 * where r = p * q
 * s is in the set of integers, which are coprime to (p - 1) * (q - 1)
 * t, is the inverse of s, modulo (p - 1) * (q - 1)
 */

#include <iostream>
#include <limits>

typedef long long ull;

using std::cout;
using std::cin;
using std::endl;

// Finds GCF of two numbers.
inline ull gcf(ull x, ull y) {
    ull temp;
    while (y != 0) {
        temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

inline ull isCoprime(const ull &x, const ull &y) {
    return gcf(x, y) == 1;
}

ull mod(ull a, const ull &b)
{
    if (a < 0)
    {
        ull mul = -(a/b)+1;
        a+=b*mul;
    }
    return (a%b);
}

// magic
inline ull getModMultiInverse(ull x, ull y) {
    ull m, temp;
    ull len = y; // NOLINT(cppcoreguidelines-narrowing-conversions)
    ull p[2] = {0,1};
    while (x!=0)
    {
        m = y/x;
        temp = p[1];
        p[1] = mod((p[0] - m*p[1]),len);
        p[0] = temp;
        temp = x;
        x = y-m*x;
        y = temp;
    }
    return p[0];
}

// Finds s, where s is coprime with (p -1) * (q - 1).
ull findS(const ull &p, const ull &q) {
    ull n = (p - 1) * (q - 1);
    for (ull i = 2; i < n; i++) {
        if (isCoprime(i, n)) {
            return i;
        }
    }
}

inline ull findT(const ull &p, const ull &q, const ull &s) {
    return getModMultiInverse(s, (p - 1) * (q - 1));
}

int main() {
    ull p, q, r, s, t;

//    cout << std::numeric_limits<bool>::max() << endl;
//    cout << static_cast<int>(std::numeric_limits<char>::max()) << endl;
//    cout << static_cast<int>(std::numeric_limits<unsigned char>::max()) << endl;
//    cout << std::numeric_limits<short>::max() << endl;
//    cout << std::numeric_limits<unsigned short>::max() << endl;
//    cout << std::numeric_limits<int>::max() << endl;
//    cout << std::numeric_limits<unsigned int>::max() << endl;
//    cout << std::numeric_limits<long>::max() << endl;
//    cout << std::numeric_limits<unsigned long>::max() << endl;
    cout << std::numeric_limits<long long>::max() << endl;
//    cout << std::numeric_limits<unsigned long long>::max() << endl;
//    cout << std::numeric_limits<float>::max() << endl;
//    cout << std::numeric_limits<double>::max() << endl;
//    cout << std::numeric_limits<long double>::max() << endl;

    cout << "Enter p, which is a very large prime: ";
    cin >> p;

    cout << "Enter q, which is a different very large prime: ";
    cin >> q;

    r = p * q;

    s = findS(p, q);
    s = 9;

    t = findT(p, q, s);

    cout << "The public key is: (" << r << ", " << s << ")" << endl;

    cout << "The private key is: (" << r << ", " << t << ")" << endl;


    return 0;
}
