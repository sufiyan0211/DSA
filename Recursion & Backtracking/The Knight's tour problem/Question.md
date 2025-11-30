# The Knight's Tour Problem

**Difficulty:** Medium  
**Accuracy:** 53.19%  
**Submissions:** 14K+  
**Points:** 4

---

## Problem Description

You are given an integer **n**, there is a **n × n** chessboard with a Knight starting at the top-left corner **(0, 0)**. Your task is to determine a valid **Knight's Tour**, where the Knight visits every square exactly once, following the standard movement rules of a chess Knight (two steps in one direction and one step perpendicular), for example if a Knight is placed at cell (2, 2), in one move it can move to any of the following cells: (4, 3), (4, 1), (0, 3), (0, 1), (3, 4), (3, 0), (1, 4) and (1, 0).

You have to return the order in which **each cell** is visited. If a solution exists, return the sequence of numbers (starting from 0) representing the order of visited squares. If no solution is possible, return an empty list.

**Note:** You can return any valid ordering, if it is correct the driver code will print true else it will print false.

---

## Examples

### Example 1

```
Input: n = 5
Output: true
Explanation: A possible Knight's Tour in a 5x5 chessboard is given below where 
each number represents the step at which the Knight visits that cell, starting 
from (0, 0) as step 0.

[[0, 11, 2, 17, 20],
 [3, 16, 19, 12, 7],
 [10, 1, 6, 21, 18],
 [15, 4, 23, 8, 13], 
 [24, 9, 14, 5, 22]]
```

### Example 2

```
Input: n = 4
Output: true
Explanation: For n = 4, it is not possible for a valid Knight's Tour so you 
have to return [].
```

---

## Constraints

- 1 ≤ n ≤ 6

---

## Expected Complexities

- **Time Complexity:** O(8^(n * n))
- **Auxiliary Space:** O(n^2)

---

## Topic Tags

- Recursion
- Backtracking
- Puzzles

---

## Related Articles

- [The Knights Tour Problem](https://www.geeksforgeeks.org/the-knights-tour-problem/)