# Lowest Common Ancestor in a BST

<p><span style="font-size:18px">Given a Binary Search Tree (with all values unique)&nbsp;and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.</span></p>

<strong>Example 1: </strong>
<pre><span style="font-size:18px"><strong>Input:
</strong>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 5
 &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp;/&nbsp; &nbsp; \
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;4&nbsp;&nbsp; &nbsp; &nbsp; 6
 &nbsp; &nbsp;   &nbsp;/&nbsp; &nbsp;&nbsp; &nbsp;  &nbsp;\
 &nbsp;    &nbsp;3&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;7
 &nbsp;&nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  \
&nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp;&nbsp;&nbsp;8
n1 = 7, n2 = 8
<strong>Output: </strong>7
</span></pre>

<strong>Example 1: </strong>

<pre><span style="font-size:18px"><strong>Input:
</strong>     2
&nbsp;  /   \
&nbsp; 1     3
n1 = 1, n2 = 3
<strong>Output: </strong>2
</span></pre>


<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>LCA()</strong>&nbsp;which takes the root Node of the BST and two integer values n1 and n2 as inputs and returns the Lowest Common Ancestor of the Nodes with values n1 and n2 in the given BST.&nbsp;</span></p>


<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(Height of the BST).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(Height of the BST).</span></p>