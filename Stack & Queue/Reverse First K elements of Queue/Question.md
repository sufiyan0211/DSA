# Reverse First K elements of Queue

<p><span style="font-size:18px">Given an integer <strong>K </strong>and a&nbsp;<a href="http://www.geeksforgeeks.org/queue-data-structure/">queue</a>&nbsp;of integers, we need to reverse the order of the first<strong> K</strong> elements of the queue, leaving the other elements in the same relative order.</span></p>


<p><span style="font-size:18px">Only following standard operations are allowed on queue.</span></p>

<ul>
	<li><span style="font-size:18px">enqueue(x) : Add an item x to rear of queue</span></li>
	<li><span style="font-size:18px">dequeue() : Remove an item from front of queue</span></li>
	<li><span style="font-size:18px">size() : Returns number of elements in queue.</span></li>
	<li><span style="font-size:18px">front() : Finds front item.<br>
	<strong>Note:</strong> The above operations represent the general processings. In-built functions of the respective languages&nbsp;can be used to solve the problem.</span></li>
</ul>


<strong>Example 1: </strong>
<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">5 3
1 2 3 4 5

<strong>Output: 
</strong>3 2 1 4 5
<strong>
Explanation: 
</strong>After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.
</span>
</pre>


<strong>Example 2: </strong>
<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">4 4
4 3 2 1

<strong>Output: 
</strong>1 2 3 4
<strong>
Explanation: 
</strong>After reversing the given
input from the 4th position the resultant
output will be 1 2 3 4.</span></pre>


<p><strong><span style="font-size:18px">Your Task:</span></strong><br>
<span style="font-size:18px"><strong>Complete </strong>the <strong>provided function</strong> <strong>modifyQueue </strong>that takes <strong>queue and k</strong> as <strong>parameters </strong>and <strong>returns </strong>a <strong>modified </strong>queue. The <strong>printing </strong>is done <strong>automatically </strong>by the <strong>driver code</strong>.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity</strong> : O(N)<br>
<strong>Expected Auxiliary Space </strong>: O(K)</span></p>

