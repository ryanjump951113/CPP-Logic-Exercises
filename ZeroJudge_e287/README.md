## ZeroJudge e287 - Robot Path
* **Link:** [ZeroJudge e287](https://zerojudge.tw/ShowProblem?problemid=e287)
* **Code:** [main.cpp](./main.cpp)
* **Description:** Starting from the globally smallest cell in an $N \times M$ grid, greedily move to the smallest unvisited adjacent cell until no valid move remains, then output the total path sum.
* **Technique:** 2D Grid Simulation, Sentinel Boundary Padding, Greedy Search, In-Place Marking.
* **Complexity:** Time $O(N \cdot M)$ | Space $O(N \cdot M)$

### Implementation Notes
1. **Boundary Padding (`a[n + 2][m + 2]`)**
   * Add an extra border of `-1` around all four edges of the grid (`row 0`, `row n+1`, `col 0`, `col m+1`).
   * Because all valid grid values are non-negative, checking `!= -1` prevents out-of-bounds access without needing separate index boundary conditions.

2. **Finding the Starting Position**
   * Scan the $N \times M$ grid to locate the cell with the minimum value and record its coordinates (`start_i`, `start_j`) as the starting point.

3. **Path Simulation & In-Place Visited Marking (`do-while`)**
   * Accumulate the current cell value into `ans` (using `long long` to avoid 32-bit integer overflow) and immediately mark `a[now_i][now_j] = -1`.
   * Reusing `-1` merges "out of bounds" and "already visited" into a single condition, saving the memory of an extra `visited` array.
   * Check the four adjacent neighbors (down, up, right, left) to find the smallest unvisited cell and update the `canfind` flag. If a valid move exists, advance `(now_i, now_j)` and continue; otherwise, terminate the loop.

### Future Improvement
* Refactor the four repeated neighbor `if` checks into direction arrays (`dr`, `dc`) with a loop to reduce code duplication.
* Replace the variable-length array `a[n + 2][m + 2]` with `std::vector` or a fixed-size array (`a[105][105]`) for strict C++ standard compliance.
