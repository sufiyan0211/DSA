# Sliding Window Maximum

<p>
	Given an array and an integer <strong> K </strong> , find the maximum for each and every contiguous subarray of size K.
</p>

<strong> Example 1: </strong>
<blockquote><p><strong>Input:</strong> arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3&nbsp;<br><strong>Output:</strong> 3 3 4 5 5 5 6<br><strong>Explanation:</strong> Maximum of 1, 2, 3 is 3<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Maximum of 2, 3, 1 is 3<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Maximum of 3, 1, 4 is 4<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Maximum of 1, 4, 5 is 5<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Maximum of 4, 5, 2 is 5&nbsp;<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Maximum of 5, 2, 3 is 5<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;Maximum of 2, 3, 6 is 6</p><p><strong>Input</strong>: arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, K = 4&nbsp;<br><strong>Output</strong>: 10 10 10 15 15 90 90<br><strong>Explanation: </strong>Maximum of first 4 elements is 10, similarly for next 4&nbsp;<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;elements (i.e from index 1 to 4) is 10, So the sequence&nbsp;<br>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;generated is 10 10 10 15 15 90 90</p></blockquote>



<strong> Example 2: </strong>
<pre><span style="font-size:18px"><strong>Input:</strong>
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6</span>
<span style="font-size:18px"><strong>Output: </strong>
3 3 4 5 5 5 6 </span>
<span style="font-size:18px"><strong>Explanation: </strong>
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6</span></pre>


<strong>Example 3: </strong>
<pre><span style="font-size:18px"><strong>Input:</strong>
N = 10, K = 4
arr[] = 8 5 10 7 9 4 15 12 90 13</span>
<span style="font-size:18px"><strong>Output: </strong>
10 10 10 15 15 90 90
<strong>Explanation: 
</strong>1st contiguous subarray = {8 5 10 7}, Max = 10
2nd contiguous subarray = {5 10 7 9}, Max = 10 
3rd contiguous subarray = {10 7 9 4}, Max = 10 
4th contiguous subarray = {7 9 4 15}, Max = 15
5th contiguous subarray = {9 4 15 12}, Max = 15 
6th contiguous subarray = {4 15 12 90}, Max = 90 
7th contiguous subarray = {15 12 90 13}, Max = 90 </span>
</pre>