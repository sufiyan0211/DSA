# 239. Sliding Window Maximum
## Description

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

### Example 1:

**Input:** nums = [1,3,-1,-3,5,3,6,7], k = 3
**Output:** [3,3,5,5,6,7]
**Explanation:**

| Window position | Max |
|----------------|-----|
| [1 3 -1] -3 5 3 6 7 | 3 |
| 1 [3 -1 -3] 5 3 6 7 | 3 |
| 1 3 [-1 -3 5] 3 6 7 | 5 |
| 1 3 -1 [-3 5 3] 6 7 | 5 |
| 1 3 -1 -3 [5 3 6] 7 | 6 |
| 1 3 -1 -3 5 [3 6 7] | 7 |

### Example 2:

**Input:** nums = [1], k = 1
**Output:** [1]

### Constraints:

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `1 <= k <= nums.length`

## Topics

- Array
- Queue
- Sliding Window
- Heap (Priority Queue)
- Monotonic Queue

## Hints

1. How about using a data structure such as deque (double-ended queue)?
2. The queue size need not be the same as the window’s size.
3. Remove redundant elements and the queue should store only elements that need to be considered.

## Similar Questions

- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) (Hard)
- [Min Stack](https://leetcode.com/problems/min-stack/) (Medium)
- [Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/) (Medium)
- [Paint House II](https://leetcode.com/problems/paint-house-ii/) (Hard)
- [Jump Game VI](https://leetcode.com/problems/jump-game-vi/) (Medium)
- [Maximum Number of Robots Within Budget](https://leetcode.com/problems/maximum-number-of-robots-within-budget/) (Hard)
- [Maximum Tastiness of Candy Basket](https://leetcode.com/problems/maximum-tastiness-of-candy-basket/) (Medium)
- [Maximal Score After Applying K Operations](https://leetcode.com/problems/maximal-score-after-applying-k-operations/) (Medium)