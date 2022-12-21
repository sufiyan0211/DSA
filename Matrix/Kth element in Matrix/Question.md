# Kth element in Matrix

### Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

<strong>Example 1: </strong>
<pre><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Input:
</strong>N = 4
mat[][] =     {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
<strong>Output: </strong>27
<strong>Explanation: </strong>27 is the 3<sup>rd</sup> smallest element.</span></span></pre>


<strong>Example 2: </strong>
<pre><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Input:
</strong>N = 4
mat[][] =     {{10, 20, 30, 40}
                   {15, 25, 35, 45}
                   {24, 29, 37, 48}
                   {32, 33, 39, 50}}
K = 7
<strong>Output: </strong>30
<strong>Explanation: </strong>30 is the 7<sup>th</sup> smallest element.</span></span></pre>


<div><br>
<br>
<strong><span style="font-size:18px">Your Task:</span></strong><br>
<span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif">You don't need to read input or print anything. Complete the function <strong>kthsmallest()</strong> which takes the mat, N and K as input parameters and returns the kth smallest element in the matrix.</span></span></div>


<p><span style="font-size:18px"><span style="font-family:arial,helvetica,sans-serif"><strong>Expected Time Complexity:&nbsp;</strong>O(K*Log(N))<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N)</span></span></p>


