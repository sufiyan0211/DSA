<h2><strong>Method 1 (By making push operation costly):</strong></h2>

<p>This method ensures that the newly entered element is always at the front of 'q1' so that pop operation dequeues from 'q1'. 'q2' is used to put every new element in front of 'q1'.</p>


<ul>
	<li><strong>push(s, x)</strong> operation's steps are described below:&nbsp;
	<br>
		<ul>
			<li>Enqueue x to q2</li>
			<li>One by one dequeue everything from q1 and enqueue to q2.</li>
			<li>Swap the names of q1 and q2</li>
		</ul>
	</li>
	<li><strong>pop(s)</strong> operation's function is described below:&nbsp;
		<br>
		<ul>
			<li>Dequeue an item from q1 and return it.</li>
		</ul>
	</li>
</ul>

