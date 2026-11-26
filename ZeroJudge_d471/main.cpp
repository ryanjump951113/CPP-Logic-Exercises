/**
 * Problem: Binary Combination Generator (ZeroJudge d471.0)
 * Description: Generates all possible 2^n binary representations for n bits.
 * Technique: Bitwise shift operations and bit masking.
 */


#include <iostream>
using namespace std;

int main(void) {
    int n;
    // Use left shift to compute 2^n, avoiding floating-point pow() overhead.
    while (cin >> n) {
        int possible = 1 << n; 
        
        for (int i = 0; i < possible; i++) {
           // Print bits from MSB to LSB.
            for (int j = n - 1; j >= 0; j--) {
                
                cout << ((i >> j) & 1);// Right-shift and mask to extract the j-th bit.
                
            }
            cout << "\n";
        }
    }
    return 0;
}
