# Stack Permutations

<p><span style="font-size:18px">You are given two arrays <strong>A</strong> and <strong>B</strong>&nbsp;of unique elements of size <strong>N</strong>. Check if array<strong> B</strong>&nbsp;is a stack permutation of the array <strong>A</strong> or not.<br>
Stack permutation means that array <strong>B</strong> can be created from array <strong>A </strong>using a stack and stack operations.</span></p>


<strong>Example 1: </strong>
<pre><span style="font-size:18px"><strong>Input:</strong>
N = 3
A = {1,2,3}
B = {2,1,3}
<strong>Output:</strong>
1
<strong>Explanation:</strong>
1. push 1 from A to stack
2. push 2 from A to stack
3. pop 2 from stack to B
4. pop 1 from stack to B
5. push 3 from A to stack
6. pop 3 from stack to B</span></pre>

<strong>Example 1: </strong>
<pre><span style="font-size:18px"><strong>Input:</strong>
N = 3
A = {1,2,3}
B = {3,1,2}
<strong>Output:</strong>
0
<strong>Explanation:</strong>
Not Possible</span></pre>


<strong>Your Task: </strong>
<p><span style="font-size:18px">You don't need to read input or print anything. Your task is to complete the function <strong>isStackPermutation()</strong>&nbsp;which takes two arrays<strong> A</strong> and <strong>B&nbsp;</strong>as inputs and returns <strong>1</strong> if it is a stack permutation otherwise returns <strong>0</strong>.</span></p>


<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N)</span></p>




