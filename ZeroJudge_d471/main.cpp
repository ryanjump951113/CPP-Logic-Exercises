/**
 * Problem: Binary Combination Generator (ZeroJudge d471.0)
 * Description: Generates all possible 2^n binary representations for n bits.
 * Technique: Bitwise shift operations and bit masking.
 */

#include <iostream>
using namespace std;

int main(void) {
    int n;
   //Use bitwise left shift to quickly compute 2^n, avoiding the overhead of floating-point pow().
    while (cin >> n) {
        int possible = 1 << n; 
        
        for (int i = 0; i < possible; i++) {
            for (int j = n - 1; j >= 0; j--) {
                cout << ((i >> j) & 1);
            }
            cout << "\n";
        }
    }
    return 0;
}
