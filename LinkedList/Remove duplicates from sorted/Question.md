# Remove duplicate element from sorted Linked List

#### Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).

#### Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

<strong> Example 1: </strong>
<pre><span style="font-size:18px"><strong>Input:
</strong>LinkedList: 2-&gt;2-&gt;4-&gt;5
<strong>Output: </strong>2 4 5<strong>
Explanation: </strong>In the given linked list 
2 -&gt;2 -&gt; 4-&gt; 5, only 2 occurs more 
than 1 time.</span>
</pre>

<strong> Example 2: </strong>
<pre><span style="font-size:18px"><strong>Input:
</strong>LinkedList: 2-&gt;2-&gt;2-&gt;2-&gt;2
<strong>Output: </strong>2<strong>
Explanation: </strong>In the given linked list 
2 -&gt;2 -&gt;2 -&gt;2 -&gt;2, 2 is the only element
and is repeated 5 times.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
The task is to complete the function&nbsp;<strong>removeDuplicates</strong>() which should remove the duplicates from linked list and return the head of the linkedlist.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity</strong> : O(N)<br>
<strong>Expected Auxilliary Space</strong> : O(1)</span></p>