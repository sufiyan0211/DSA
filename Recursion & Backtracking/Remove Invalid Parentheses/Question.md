# 301. Remove Invalid Parentheses

**Difficulty:** Hard  
**Status:** Solved  
**Acceptance Rate:** 49.6%  
**Accepted:** 494,041 / 996.1K

---

## Problem Description

Given a string `s` that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return *a list of **unique strings** that are valid with the minimum number of removals*. You may return the answer in **any order**.

---

## Examples

### Example 1

```
Input: s = "()())()"
Output: ["(())()", "()()()"]
```

### Example 2

```
Input: s = "(a)())()"
Output: ["(a())()", "(a)()()"]
```

### Example 3

```
Input: s = ")("
Output: [""]
```

---

## Constraints

- `1 <= s.length <= 25`
- `s` consists of lowercase English letters and parentheses `'('` and `')'`.
- There will be at most `20` parentheses in `s`.

---

## Hints

**Hint 1:** Since we do not know which brackets can be removed, we try all the options! We can use recursion.

**Hint 2:** In the recursion, for each bracket, we can either use it or remove it.

**Hint 3:** Recursion will generate all the valid parentheses strings but we want the ones with the least number of parentheses deleted.

**Hint 4:** We can count the number of invalid brackets to be deleted and only generate the valid strings in the recursion.

---

## Topics

- String
- Backtracking
- Breadth-First Search

---

## Similar Questions

- **Valid Parentheses** - Easy
- **Minimum Number of Swaps to Make the String Balanced** - Medium

---
