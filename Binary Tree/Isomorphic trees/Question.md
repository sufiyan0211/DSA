# Isomorphic Trees

## Problem

Given two Binary Trees. Check whether they are Isomorphic or not.

Note: Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e., by swapping left and right children of several nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic. For example, the following two trees are isomorphic with the following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.

---

## Examples

```
Input:
root1[] = [1, 2, 3, 4, 5, 7, 6, N, 7, 8]
root2[] = [1, 3, 2, N, 6, 4, 5, 8, 7]

Output:
true
```

```
Input:
root1[] = [1, 2, 3, 4]
root2[] = [1, 3, 2, 4]

    1               1
   / \             / \
  2   3           3   2
 /                 \
4                   4

Output:
false
```

```
Input:
root1[] = [1, 2, 3, 4]
root2[] = [1, 3, 2, N, N, N, 4]

     1            1
   /   \        /   \
  2     3      3     2
 /                      \
4                        4

Output:
true
```

---

## Constraints

- 1 <= number of nodes <= 10^5
- 1 <= node->data <= 10^5

---

## Expected complexities

- Time Complexity: O(n)
- Auxiliary Space: O(n)

---