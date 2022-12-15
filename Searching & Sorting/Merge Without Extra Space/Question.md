# Merge Without Extra Space

## Question
### Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

#### Example 1:
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

#### Example 2:
<pre><span style="font-size:18px"><strong>Input</strong>: 
n = 2, arr1[] = [10, 12] 
m = 3, arr2[] = [5 18 20]
<strong>Output</strong>: 
arr1[] = [5 10]
arr2[] = [12 18 20]
<strong>Explanation</strong>:
After merging two sorted arrays 
we get 5 10 12 18 20.</span>

</pre>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> &nbsp;O((n+m) log(n+m))<br>
<strong>Expected Auxilliary Space:</strong> O(1)</span><br>
&nbsp;</p>