# Sum of minimum and maximum elements of all subarrays of size k

<p>Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.</p>

<strong>Examples: </strong>
<pre>Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
        K = 4
Output : 18
Explanation : Subarrays of size 4 are : 
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4      
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4   
     
     Sum of all min &amp; max = 6 + 4 + 4 + 4 
     
                          = 18              
</pre>

