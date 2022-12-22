# The Double HeLiX

#### Two ﬁnite, strictly increasing, integer sequences are given. Any common integer between the two sequences constitute an intersection point. Take for example the following two sequences where intersection points are printed in bold:

<ul>
  <li>First= 3 5 <strong>7</strong> 9 20 <strong>25</strong> 30 40 <strong>55</strong> 56 <strong>57</strong> 60 62</li>
  <li>Second= 1 4 <strong>7</strong> 11 14 <strong>25</strong> 44 47 <strong>55</strong> <strong>57</strong> 100</li>
</ul>

#### You can ‘walk” over these two sequences in the following way:

#### You may start at the beginning of any of the two sequences. Now start moving forward.
#### At each intersection point, you have the choice of either continuing with the same sequence you’re currently on, or switching to the other sequence.
#### The objective is ﬁnding a path that produces the maximum sum of data you walked over. In the above example, the largest possible sum is 450, which is the result of adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62



<strong>Example: </strong>
<pre>
<strong>Input:</strong>
13 3 5 7 9 20 25 30 40 55 56 57 60 62
11 1 4 7 11 14 25 44 47 55 57 100
4 -5 100 1000 1005
3 -12 1000 1001
0

<strong>Output:</strong>
450
2100
</pre>