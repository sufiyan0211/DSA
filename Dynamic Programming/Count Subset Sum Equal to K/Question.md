# Perfect Sum Problem

## Problem Details

**Difficulty:** Medium  
**Accuracy:** 20.58%  
**Submissions:** 596K+  
**Points:** 4

---

## Problem Statement

Given an array **`arr`** of non-negative integers and an integer **`target`**, the task is to count all subsets of the array whose sum is equal to the given `target`.

## Examples

### Example 1
**Input:** `arr[] = [5, 2, 3, 10, 6, 8]`, `target = 10`  
**Output:** `3`  
**Explanation:** The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.

### Example 2
**Input:** `arr[] = [2, 5, 1, 4, 3]`, `target = 10`  
**Output:** `3`  
**Explanation:** The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.

### Example 3
**Input:** `arr[] = [5, 7, 8]`, `target = 3`  
**Output:** `0`  
**Explanation:** There are no subsets of the array that sum up to the target 3.

### Example 4
**Input:** `arr[] = [35, 2, 8, 22]`, `target = 0`  
**Output:** `1`  
**Explanation:** The empty subset is the only subset with a sum of 0.

## Constraints

- 1 ≤ arr.size() ≤ 10³
- 0 ≤ arr[i] ≤ 10³
- 0 ≤ target ≤ 10³

## Expected Complexities

**Time Complexity:** O(n*target)  
**Auxiliary Space:** O(n*target)

## Tags

### Company Tags
- Amazon
- Microsoft
- Tesco

### Topic Tags
- Dynamic Programming
- Algorithms

### Related Articles
- [Count Of Subsets With Sum Equal To X Using Recursion](https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x-using-recursion/)
- [Count Of Subsets With Sum Equal To X](https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/)
