# Rotate a 2D array without using extra space

### Given a N x N 2D matrix Arr representing an image. Rotate the image by 90 degrees (anti-clockwise). You need to do this in place. Note that if you end up using an additional array, you will only receive partial score.

<strong>Example 1:</strong>
<pre><span style="font-size:18px"><strong>Input:
</strong>N = 3
Arr[][] = {{1,  2,  3}
           {4,  5,  6}
           {7,  8,  9}}
<strong>Output:</strong>
 3  6  9 
 2  5  8 
 1  4  7 
<strong>Explanation:</strong> The given matrix is rotated
by 90 degree in anti-clockwise direction.</span></pre>



<strong>Example 2:</strong>
<pre><span style="font-size:18px"><strong>Input:
</strong>N = 4
Arr[][] = {{1,  2,  3,  4}
           {5,  6,  7,  8}
           {9, 10, 11, 12}
           {13, 14, 15, 16}}
<strong>Output:</strong>
 4  8 12 16 
 3  7 11 15 
 2  6 10 14 
 1  5  9 13
<strong>Explanation: </strong>The given matrix is rotated
by 90 degree in anti-clockwise direction.
</span></pre>


<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>rotate()</strong>&nbsp;which takes the 2D array of&nbsp;integers <strong>arr </strong>and&nbsp;<strong>n</strong><strong>&nbsp;</strong>as parameters and returns void. You need to change the array itself.</span>


<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N*N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>


