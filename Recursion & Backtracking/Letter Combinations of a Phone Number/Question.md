# 17. Letter Combinations of a Phone Number

**Difficulty:** Medium  
**Status:** Solved  
**Acceptance Rate:** 64.9%  
**Accepted:** 2,801,161 / 4.3M

---

## Problem Description

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![Telephone Keypad](https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-keypad2svg.png)

---

## Examples

### Example 1

```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

### Example 2

```
Input: digits = "2"
Output: ["a","b","c"]
```

---

## Constraints

- `1 <= digits.length <= 4`
- `digits[i]` is a digit in the range `['2', '9']`

---

## Topics

- Hash Table
- String
- Backtracking

---

## Similar Questions

- **Generate Parentheses** - Medium
- **Combination Sum** - Medium
- **Binary Watch** - Easy
- **Count Number of Texts** - Medium
- **Minimum Number of Pushes to Type Word I** - Easy
- **Minimum Number of Pushes to Type Word II** - Medium