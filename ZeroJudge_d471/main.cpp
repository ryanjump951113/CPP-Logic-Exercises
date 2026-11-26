/**
 * Problem: Binary Combination Generator (ZeroJudge d471.0)
 * Description: Generates all possible 2^n binary representations for n bits.
 * Technique: Bitwise shift operations and bit masking.
 */

// Use bitwise left shift to quickly compute 2^n, avoiding the overhead of floating-point pow().
#include <iostream>
using namespace std;

int main(void) {
    int n;
    while (cin >> n) {
        int possible = 1 << n; 
        // shift 1 left for n bits to initialize the possibility numbers.
        // for instance, when n==2 and 1 will be shifted left for 2 bits, getting 2^2 ==4 conditions( 00 01 10 11).
        for (int i = 0; i < possible; i++) {
            // range from 0 to 2^n-1.
            for (int j = n - 1; j >= 0; j--) {
                // start from the highest bit because the biggest number is at left side.
                // if start from 0 to n-1 the output will be opposite.
                cout << ((i >> j) & 1);
                // ((i >> j) & 1) shows the way to reserve the target bit.
                // shift i right for j bits (put i to the rightest side).
                // operate AND compute to let other bits which isn't our target be stuck.
            }
            cout << "\n";
        }
    }
    return 0;
}
