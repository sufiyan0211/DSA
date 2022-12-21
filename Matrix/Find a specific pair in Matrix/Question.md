# Find a specific pair in Matrix

### Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.


<strong>Example: </strong>
<pre>Input:
mat[N][N] = {{ 1, 2, -1, -4, -20 },
             {<strong> -8</strong>, -3, 4, 2, 1 }, 
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, <strong>10</strong>, -5, 1 }};
Output: 18
The maximum value is 18 as mat[4][2] 
- mat[1][0] = 18 has maximum difference. </pre>


<strong> Solution hint: </strong>
<p>An <strong>efficient solution</strong> uses extra space. We pre-process the matrix such that index(i, j) stores max of elements in matrix from (i, j) to (N-1, N-1) and in the process keeps on updating maximum value found so far. We finally return the maximum value.</p>


<p><strong>Time complexity: O(N<sup>2</sup>).</strong><br><strong>Auxiliary Space: O(N<sup>2</sup>)</strong></p>