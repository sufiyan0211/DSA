<p>
	<pre> 
		<strong>Code 1</strong> is using auxilary queue. <br>
		<strong>Code 2</strong> is using auxilary stack.
	</pre>
</p>

<p>
Interviewer also wants see the approch using <strong> auxilary stack</strong> because thats the tricky one.
</p>


<pre>
<strong>Code 2: </strong> Using Stack <br>
<p>Following are the steps to solve the problem:&nbsp;</p>
<ol><li>Push the first half elements of the queue to stack.&nbsp;</li><li>Enqueue back the stack elements.&nbsp;</li><li>Dequeue the first half elements of the queue and enqueue them back.&nbsp;</li><li>Again push the first half elements into the stack.&nbsp;</li><li>Interleave the elements of queue and stack.&nbsp;</li></ol>
</pre>



<pre>
<strong>Code 1: </strong> Using Queue <br>
<p>Following are the steps to solve the problem:&nbsp;</p>
<ol><li>Make a temporary queue and push the first half of the original queue into the temp queue.</li><li>Till the temp queue is empty<ol><li>Pop the front of the temp queue and push it to the original queue</li><li>Pop the front of the original queue and push it to the original queue</li></ol></li><li>The original queue is converted to the interleaved queue.</li></ol>
</pre>