## ZeroJudge d471 - Binary Combination Generator
* **Link:** [ZeroJudge d471](https://zerojudge.tw/ShowProblem?problemid=d471)
* **Code:** [main.cpp](./main.cpp)
* **Description:** Generates all possible $2^n$ binary representations for $n$ bits.
* **Technique:** Bitwise shift operations and bit masking.

### Implementation Notes
1. **Computing Total Combinations (`1 << n`)**
   * Use bitwise left shift to quickly compute $2^n$, avoiding the overhead of floating-point `pow()`.
   * Shift `1` left by `n` bits to initialize the total number of possibilities. For instance, when `n = 2`, shifting `1` left by 2 bits gives $2^2 = 4$ combinations (`00`, `01`, `10`, `11`), ranging from `0` to $2^n - 1$.

2. **Output Order (`j = n - 1` down to `0`)**
   * Start from the highest bit (MSB) because the most significant value is on the left side.
   * If we start from `0` to `n - 1`, the output will be reversed.

3. **Extracting the Target Bit (`(i >> j) & 1`)**
   * `((i >> j) & 1)` is used to isolate the target bit:
     * Shift `i` right by `j` bits to move the target bit to the rightmost position (LSB).
     * Perform a bitwise `AND` with `1` to mask out (zero out) all other bits that aren't our target.
