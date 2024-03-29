# Is Binary Tree Heap

<p><span style="font-size:18px">Given a binary tree. The task is to check whether the given tree follows the&nbsp;<strong>max heap</strong> property or not.<br>
<strong>Note:&nbsp;</strong>Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.</span></p>

<strong> Example 1: </strong>
<pre><span style="font-size:18px"><strong>Input:
</strong>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 5
 &nbsp;&nbsp;&nbsp;/  \
&nbsp;&nbsp; 2    3
<strong>Output: </strong>1
<strong>Explanation:</strong>&nbsp;The given tree follows <strong>max-heap</strong>&nbsp;property since 5,
is root and it is greater than both its children.
</span>
</pre>



<strong> Example 2: </strong>
<pre><span style="font-size:18px"><strong>Input:
</strong>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;10
 &nbsp;&nbsp;&nbsp;&nbsp;/&nbsp;&nbsp; \
 &nbsp;&nbsp;&nbsp;20&nbsp;&nbsp; 30 
&nbsp;&nbsp;/&nbsp;&nbsp; \
 40&nbsp;&nbsp; 60
<strong>Output:</strong> 0</span></pre>


<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the&nbsp;function <strong>isHeap()</strong>&nbsp;which takes the root of Binary Tree as parameter returns <strong>True</strong> if the given binary tree is a&nbsp;<strong>heap</strong>&nbsp;else&nbsp;returns <strong>False</strong>.<br>
<br>
<strong>Expected Time Complexity: </strong>O(N)<br>
<strong>Expected Space Complexity: </strong>O(N)</span></p>

