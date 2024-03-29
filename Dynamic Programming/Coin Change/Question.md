Coin Change
===

<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an integer&nbsp;array <strong>coins[ ] of size N&nbsp;</strong>representing different denominations of currency and an integer <strong>sum</strong>, find the number of ways you can make <strong>sum</strong> by using different combinations from coins[ ]. &nbsp;<br>
Note: Assume that you have an infinite supply of each type of coin.&nbsp; </span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
sum = 4 , 
N = 3
coins[] = {1,2,3}
<strong>Output:</strong> 4
<strong>Explanation</strong>: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>:
Sum = 10 , 
N = 4
coins[] ={2,5,3,6}
<strong>Output:</strong> 5
<strong>Explanation</strong>: Five Possible ways are:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} 
and {5,5}.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>count()&nbsp;</strong>which accepts an array coins<strong>[ ] its size N&nbsp;and sum</strong>&nbsp;as input parameters and returns the number of ways to make change for given sum of money.&nbsp;</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(sum*N)<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(sum)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= sum, N&nbsp;&lt;= 10<sup>3</sup></span></p>
</div>