Next Smaller Element
===


<pre><span style="font-size:18px"><strong>Input: </strong>N = 5, arr[] = {3, 8, 5, 2, 25}
<strong>Output:</strong> 2 5 2 -1 -1
<strong>Explanation:</strong> 
1. Roll number 1 has 3 marks. The first person 
who has less marks than him is roll number 4, 
who has 2 marks.
2. Roll number 2 has 8 marks, he helps student 
with 5 marks.
3. Roll number 3 has 5 marks, he helps student 
with 2 marks.
4. Roll number 4 and 5 can not pick anyone as 
no student with higher roll number has lesser 
marks than them. This is denoted by -1.
Output shows the marks of the weaker student that 
each roll number helps in order. ie- 2,5,2,-1,-1</span></pre>


<pre><span style="font-size:18px"><strong>Input: </strong>N = 4, a[] = {1, 2, 3, 4}
<strong>Output:</strong> -1 -1 -1 -1&nbsp;
<strong>Explanation:</strong> As the marks ars in increasing order. 
None of the students can find a classmate who has 
a higher roll number and less marks than them.
</span></pre>