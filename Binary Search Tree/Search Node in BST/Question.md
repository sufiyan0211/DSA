# Search a node in BST

<p><span style="font-size:18px">Given a <strong>Binary Search Tree </strong>and a node value X, find if the node with value X is present in the BST or not.</span></p>

<strong>Example 1: </strong>
<pre><span style="font-size:18px"><strong>Input:</strong>         2
                \
&nbsp;                81 
&nbsp;              /    \ 
&nbsp;            42      87 
&nbsp;             \       \ 
&nbsp;              66      90 
&nbsp;             / 
&nbsp;           45
X = 87
<strong>Output: </strong>1
<strong>Explanation: </strong>As 87 is present in the
given nodes , so the output will be
1.</span></pre>


<strong>Example 2: </strong>
<pre><span style="font-size:18px"><strong>Input:</strong>      6
&nbsp;            \ 
&nbsp;             8 
&nbsp;            / \ 
&nbsp;           7   9
X = 11
<strong>Output: </strong>0
<strong>Explanation: </strong>As 11 is not present in 
the given nodes , so the output will
be 0.</span></pre>


<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Complete the function <strong>search()</strong>which returns <strong>true </strong>if the node with <strong>value x</strong> is <strong>present </strong>in the BST<strong>else returns false</strong>.</span></p>


<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(Height of the BST)<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1).</span></p>