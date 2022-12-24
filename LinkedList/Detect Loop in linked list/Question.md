# Detect Loop in linked list

#### Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.


<strong>Example 1: </strong>
<pre><span style="font-size:18px"><strong>Input:
</strong>N = 3
value[] = {1,3,4}
x(position at which tail is connected) = 2
<strong>Output: </strong>True<strong>
Explanation: </strong>In above test case N = 3.
</span><span style="font-size:18px">The linked list with nodes N = 3 is
given. Then value of&nbsp;x=2 is given which
means last node is connected with xth
node of linked list. Therefore, there
exists a loop.</span></pre>


<strong>Example 2: </strong>
<pre><span style="font-size:18px"><strong>Input:
</strong>N = 4
value[] = {1,8,3,4}
x = 0
<strong>Output: </strong>False<strong>
Explanation: </strong>For N = 4 ,x = 0 means
then lastNode-&gt;next = NULL, then
the&nbsp;Linked list does not contains
any loop.</span></pre>


<p><span style="font-size:18px"><strong>Your Task:</strong><br>
The task is to complete the function <strong>detectloop</strong>() which contains reference to the head as only argument.&nbsp; This function should return <strong>true</strong>&nbsp;if linked list contains loop, else return <strong>false</strong>.</span></p>


<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>