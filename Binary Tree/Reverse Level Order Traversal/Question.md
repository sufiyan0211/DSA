# Reverse Level Order Traversal

<p>Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level. </p>

<strong>Example 1: </strong>
<pre><span style="font-size:18px"><strong>Input :</strong>
        1
      /   \
     3     2</span>

<span style="font-size:18px"><strong>Output:</strong> 3 2 1
<strong>Explanation:</strong>
Traversing level 1 : 3 2
Traversing level 0 : 1</span></pre>


<strong>Example 2: </strong>
<pre><span style="font-size:18px"><strong>Input :</strong>
       10
      /  \
     20   30
    / \ 
   40  60</span>

<span style="font-size:18px"><strong>Output: </strong>40 60 20 30 10
<strong>Explanation:</strong>
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10</span></pre>


<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp; </strong><br>
You dont need to read input or print anything. Complete the function <strong>reverseLevelOrder() </strong>which takes the root of the tree as input parameter and returns a list containing the reverse level order traversal of the given tree.</span></p>


<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space: </strong>O(N)</span></p>


