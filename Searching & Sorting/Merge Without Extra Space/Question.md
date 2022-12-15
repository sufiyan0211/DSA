# Merge Without Extra Space

## Question
### Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

#### Example 1:
**Input**: 
`
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
`
**Output**: 
`
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
`
**Explanation**:
`
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.
`

#### Example 2:
<pre><span style="font-size:18px"><strong>Input</strong>: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
<strong>Output</strong>: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
<strong>Explanation</strong>:
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.</span></pre>


<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> &nbsp;O((n+m) log(n+m))<br>
<strong>Expected Auxilliary Space:</strong> O(1)</span><br>
&nbsp;</p>