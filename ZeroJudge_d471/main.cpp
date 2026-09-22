/**
 * Problem: Binary Combination Generator (ZeroJudge d471.0)
 * Description: Generates all possible 2^n binary representations for n bits.
 * Technique: Bitwise shift operations and bit masking.
 */

#include <iostream>
using namespace std;

int main(void) {
    int n;
    // 使用位元左移快速計算 2^n，避免浮點數 pow() 運算帶來的效能損耗
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
