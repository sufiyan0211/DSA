# Permutations of a String

**Difficulty:** Medium  
**Accuracy:** 34.65%  
**Submissions:** 277K+  
**Points:** 4  

---

## Problem Description
Given a string **s**, the task is to return a vector of strings of all **unique** permutations of the given string **s**, which may contain duplicates, in lexicographically sorted order.

---

## Examples

### Example 1:
**Input:** `"ABC"`  
**Output:** `["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]`  
**Explanation:**  
The string `"ABC"` has 6 permutations: `"ABC"`, `"ACB"`, `"BAC"`, `"BCA"`, `"CAB"`, `"CBA"`.

---

### Example 2:
**Input:** `"ABSG"`  
**Output:**  
`["ABGS", "ABSG", "AGBS", "AGSB", "ASBG", "ASGB", "BAGS", "BASG", "BGAS", "BGSA", "BSAG", "BSGA", "GABS", "GASB", "GBAS", "GBSA", "GSAB", "GSBA", "SABG", "SAGB", "SBAG", "SBGA", "SGAB", "SGBA"]`  
**Explanation:**  
The string `"ABSG"` has 24 permutations.

---

### Example 3:
**Input:** `"AAA"`  
**Output:** `["AAA"]`  
**Explanation:**  
No other unique permutations can be formed as all the characters are the same.

---

## Tags
**Company Tags:** Zoho, Accolite, Amazon, Microsoft, OYO Rooms, Samsung, Snapdeal, Citrix, Walmart, MAQ Software, Cisco  
**Topic Tags:** Strings, Recursion, Backtracking, Data Structures, Algorithms  

---

## Expected Complexities
- **Time Complexity:** \(O(n! \cdot n)\)
- **Auxiliary Space:** \(O(n! \cdot n)\)
