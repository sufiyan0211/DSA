# Nth node from end of linked list

<p><span style="font-size:18px">Given a linked list consisting of <strong>L</strong> nodes and given a number <strong>N</strong>. The task is to find the <strong>N</strong><sup>th</sup> node from the end of the linked list.</span></p>


<strong>Example 1: </strong>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 2
LinkedList: 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;6-&gt;7-&gt;8-&gt;9
<strong>Output: </strong>8<strong>
Explanation: </strong>In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end.&nbsp;2nd node
from end is 8.&nbsp;&nbsp;</span>
</pre>


<strong>Example 2: </strong>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 5
LinkedList: 10-&gt;5-&gt;100-&gt;5
<strong>Output: </strong>-1<strong>
Explanation: </strong>In the second example, there
are 4 nodes in the linked list and we
need to find 5th from the end.&nbsp;Since 'n'
is more than the number of nodes in the
linked list, the output is -1.</span></pre>


<p><span style="font-size:18px"><strong>Your Task:</strong><br>
The task is to complete the function <strong>getNthFromLast</strong>() which takes two <strong>arguments</strong>: <strong>reference </strong>to <strong>head and N</strong> and you need to<strong> return N<sup>th</sup> </strong>from the end or -1 in case node doesn't exist.</span></p>


<p><span style="font-size:18px"><strong>Note:</strong><br>
Try to solve in a single traversal.</span></p>


<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1).</span></p>
