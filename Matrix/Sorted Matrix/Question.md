# Sorted matrix

### Given an NxN matrix Mat. Sort all elements of the matrix.

<strong>Example 1: </strong>
<pre><span style="font-size:18px"><strong>Input:</strong>
N=4
Mat=[[10,20,30,40],
[15,25,35,45] 
[27,29,37,48] 
[32,33,39,50]]
<strong>Output:</strong>
10 15 20 25 
27 29 30 32
33 35 37 39
40 45 48 50
<strong>Explanation:</strong>
Sorting the matrix gives this result.</span></pre>

<strong>Example 2: </strong>
<pre><span style="font-size:18px"><strong>Input:</strong>
N=3
Mat=[[1,5,3],[2,8,7],[4,6,9]]
<strong>Output:</strong>
1 2 3 
4 5 6
7 8 9
<strong>Explanation:</strong>
Sorting the matrix gives this result.</span></pre>

<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>sortedMatrix()</strong> which takes the integer N and the matrix Mat as input parameters and returns the sorted matrix.</span>

<span style="font-size:18px"><strong>Expected Time Complexity:</strong>O(N<sup>2</sup>LogN)<br>
<strong>Expected Auxillary Space:</strong>O(N<sup>2</sup>)</span>