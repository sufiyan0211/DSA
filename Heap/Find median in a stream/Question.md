# Find median in a stream

<p><span style="font-size:18px">Given an input stream of <strong>N</strong> integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of <strong>X</strong> to the new stream.</span></p>


<strong>Example 1: </strong>
<pre><span style="font-size:18px"><strong>Input:
</strong>N = 4
X[] = 5,15,1,3
<strong>Output:
</strong>5</span>
<span style="font-size:18px">10</span>
<span style="font-size:18px">5</span>
<span style="font-size:18px">4<strong>
Explanation:</strong>Flow in stream : 5, 15, 1, 3 </span>
<span style="font-size:18px">5 goes to stream --&gt; median 5 (5) </span>
<span style="font-size:18px">15 goes to stream --&gt; median 10 (5,15) </span>
<span style="font-size:18px">1 goes to stream --&gt; median 5 (5,15,1) </span>
<span style="font-size:18px">3 goes to stream --&gt; median 4 (5,15,1 3) </span>
</pre>



<strong>Example 2: </strong>
<pre><span style="font-size:18px"><strong>Input:
</strong>N = 3
X[] = 5,10,15
<strong>Output:
</strong>5</span>
<span style="font-size:18px">7.5</span>
<span style="font-size:18px">10</span><span style="font-size:18px"><strong>
Explanation:</strong>Flow in stream : 5, 10, 15</span>
<span style="font-size:18px">5 goes to stream --&gt; median 5 (5) </span>
<span style="font-size:18px">10 goes to stream --&gt; median 7.5 (5,10) </span>
<span style="font-size:18px">15 goes to stream --&gt; median 10 (5,10,15) </span>
</pre>


<div><br>
<span style="font-size:18px"><strong>Expected Time Complexity</strong> : O(nlogn)<br>
<strong>Expected Auxilliary Space</strong> : O(n)</span></div>



