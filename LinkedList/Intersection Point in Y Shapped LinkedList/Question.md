# Intersection Point in Y Shapped Linked Lists

<p><span style="font-size:18px">Given two singly linked lists of size <strong>N</strong> and <strong>M, </strong>write a program to get the point where two linked lists intersect each other.</span></p>

<pre><span style="font-size:18px"><strong>Input:</strong><strong>
</strong>LinkList1 = 3-&gt;6-&gt;9-&gt;common
LinkList2 = 10-&gt;common
common = 15-&gt;30-&gt;NULL
<strong>Output: 1</strong>5
<strong>Explanation:
</strong><img alt="Y ShapedLinked List" class="aligncenter size-full wp-image-2753" src="linked.jpg" style="height:334px; width:388px" title="Y ShapedLinked List"></span>
</pre>



<pre><span style="font-size:18px"><strong>Input: 
</strong>Linked List 1 = 4-&gt;1-&gt;common
Linked List 2 = 5-&gt;6-&gt;1-&gt;common
common = 8-&gt;4-&gt;5-&gt;NULL
<strong>Output: </strong>8
<strong>Explanation: </strong></span>

<span style="font-size:18px"><strong>4              5</strong></span>
<span style="font-size:18px"><strong>|              |</strong></span>
<span style="font-size:18px"><strong>1              6
</strong></span><span style="font-size:18px"><strong> \             /</strong></span>
<span style="font-size:18px"><strong>  8   -----  1 </strong></span>
   <strong>|</strong>
   <strong>4</strong>
   <strong>|
</strong><span style="font-size:18px"><strong>  5</strong></span>
<span style="font-size:18px"><strong>  |</strong></span>
<span style="font-size:18px"><strong>  NULL       </strong></span></pre>