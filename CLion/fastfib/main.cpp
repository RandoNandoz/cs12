// randy zhu
// 2021-11-07
// takes the fib sequence mod 1bil and 7

// optimize the code
#pragma GCC optimize("Ofast")
#pragma GCC target("arch=skylake")

#include <iostream>
#include <algorithm>
#include <vector>

#define ull unsigned long long
using namespace std;

// performs mod on every element of a matrix (2d vector)
// takes in a pointer for the dividend which will be modified in the function
// and takes in a divisor for the mod
inline void modulo_two_by_two_matrix_by_scalar(vector<vector<ull>> *dividend, const ull &divisor) {
    for_each(dividend->begin(), dividend->end(), [&divisor](vector<ull> &vu) {
        for_each(vu.begin(), vu.end(), [&divisor](ull &u) {
            u %= divisor;
        });
    });
}

//void print_two_dim_matrix(const vector<vector<ull>> &matrix) {
//    for_each(matrix.begin(), matrix.end(), [](const vector<ull> &one_dim_vector){
//        for_each(one_dim_vector.begin(), one_dim_vector.end(), [](const ull &x){
//            cout << x << " ";
//        });
//        cout << endl;
//    });
//}

// linear algebra lol?
// multiplies two 2x2 matrices
inline vector<vector<ull>>
multiply_two_by_two_matrix(const vector<vector<ull>> &multiplicand, const vector<vector<ull>> &multiplier) {
    // oh, god
    // this is awful
    // please ignore
    return {
            // photomath = poggers
            {
                    multiplicand[0][0] * multiplier[0][0] + multiplicand[0][1] * multiplier[1][0],
                    multiplicand[0][0] * multiplier[0][1] + multiplicand[0][1] * multiplier[1][1]
            },
            {
                    multiplicand[1][0] * multiplier[0][0] + multiplicand[1][1] * multiplier[1][0],
                    multiplicand[1][0] * multiplier[0][1] + multiplicand[1][1] * multiplier[1][1]
            }};
}

// does the mod exponent on the matrix
// takes in a matrix and an exponent
// and a mod


// the fib thing, takes in n and mod
inline ull mod_fib(ull n, ull mod) {
    // the identity matrix according to wikipedia
    const vector<vector<ull>> MATRIX_IDENTITY = {
            {1, 1},
            {1, 0}
    };inline vector<vector<ull>>
two_dim_power_mod(const vector<vector<ull>> &two_dim_base, ull scalar_exp, const ull &scalar_mod) {
    // recursive
    // if the exponent is 1 then we're done
    if (scalar_exp == 1) {
        return two_dim_base;
    }
    // recursively call the power fn, halfing the exponent each time
    vector<vector<ull>> res = two_dim_power_mod(two_dim_base, scalar_exp / 2, scalar_mod);
    // if the exponent is even, square it and then mod it
    if (scalar_exp % 2 == 0) {
        vector<vector<ull>> x = multiply_two_by_two_matrix(res, res);
        modulo_two_by_two_matrix_by_scalar(&x, scalar_mod);
        return x;
    }
        // otherwise, if it's odd, multiply the square with the base, (factor out the x^1), and mod
    else {
        vector<vector<ull>> x = multiply_two_by_two_matrix(multiply_two_by_two_matrix(res, res), two_dim_base);
        modulo_two_by_two_matrix_by_scalar(&x, scalar_mod);
        return x;
    }
}
    // if our value is zero or one just return zero and one
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        // otherwise raise our identity matrix to the (n-1)th power.
        return two_dim_power_mod(MATRIX_IDENTITY, n - 1, mod)[0][0];
    }
}

int main() {
//    vector<vector<ull>> testa = {{1,1}, {2,2}};
//    vector<vector<ull>> testb = {{3,3}, {3,3}};
    ull cases;
    cin >> cases;
    for (ull _ = 0; _ < cases; ++_) {
        ull n;
        cin >> n;
        cout << mod_fib(n, 1000000007) << endl;
//        auto res = multiply_two_by_two_matrix(testa, testb);
//        print_two_dim_matrix(res);
    }
    return 0;
}
