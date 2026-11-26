## ZeroJudge e287 - Robot Path
* **Link:** [ZeroJudge e287](https://zerojudge.tw/ShowProblem?problemid=e287)
* **Code:** [main.cpp](./main.cpp)
* **Description:** Simulates a robot moving through an $N \times M$ grid by always stepping into the smallest unvisited adjacent cell until no valid move remains, then outputs the total path sum.
* **Technique:** 2D Grid Simulation, Sentinel Padding, Greedy Search, Direction Arrays.
* **Complexity:** Time $O(N \cdot M)$ | Space $O(N \cdot M)$

### Implementation Notes
1. **Boundary Padding (`(n + 2) x (m + 2)` Grid)**
   * Add an extra layer of `-1` around all four edges of the grid as a sentinel border.
   * Since all valid grid values are non-negative, checking `grid[nr][nc] != -1` automatically prevents out-of-bounds access without needing separate index range checks.

2. **Finding the Starting Position**
   * Scan the $N \times M$ grid while reading input to locate the cell with the global minimum value as the robot's initial coordinates `(cur_r, cur_c)`.

3. **Greedy Traversal & In-Place Visited Marking**
   * At each step, add the current cell's value to `total_sum` (using `long long` to prevent integer overflow) and immediately set `grid[cur_r][cur_c] = -1`.
   * Reusing `-1` unifies "out of bounds" and "already visited" into a single condition, avoiding the memory overhead of a separate `visited` matrix.
   * Use direction arrays (`dr`, `dc`) to inspect the 4 adjacent cells (down, up, right, left) and pick the unvisited neighbor with the minimum value. If no valid target exists (`next_r == -1`), terminate the loop.
