# ZigZag Tree Traversal

<p>Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree. </p>



<strong>Example 1: </strong>
<pre><span style="font-size:18px"><strong>Input:
</strong>&nbsp; &nbsp; &nbsp; &nbsp;&nbsp;1
 &nbsp;  &nbsp; /&nbsp; &nbsp;\
     2&nbsp; &nbsp;  3
&nbsp;   / \   /  \
&nbsp;  4   5 6    7
<strong>Output:
</strong>1 3 2 4 5 6 7</span>
</pre>



<strong>Example 2: </strong>
<pre><span style="font-size:18px"><strong>Input:
</strong>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;7
 &nbsp; &nbsp; &nbsp; &nbsp;/&nbsp; &nbsp; &nbsp;\
 &nbsp; &nbsp; &nbsp; 9&nbsp; &nbsp; &nbsp; &nbsp;7
 &nbsp; &nbsp; /&nbsp; \&nbsp;    /&nbsp; &nbsp;
&nbsp;  &nbsp;8&nbsp; &nbsp; 8&nbsp; &nbsp;6&nbsp; &nbsp; &nbsp;
 &nbsp; /&nbsp; \
&nbsp; 10&nbsp; &nbsp;9&nbsp;
<strong>Output:
</strong></span><span style="font-size:18px">7 7 9 8 8 6 9 10 </span></pre>


<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>zigZagTraversal()</strong>&nbsp;which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the&nbsp;Zig-Zag Level-Order Traversal of the Tree.</span></p>


<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N).</span></p>