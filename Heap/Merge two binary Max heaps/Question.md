# Merge two binary Max heaps

<p><span style="font-size:18px">Given two binary max heaps as arrays, merge the given heaps to form a new max heap.</span></p>

<strong> Example 1: </strong>

<pre><span style="font-size:18px"><strong>Input  :</strong> 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
<strong>Output :</strong> 
{12, 10, 9, 2, 5, 7, 6}</span>
<span style="font-size:18px"><strong>Explanation :</strong></span>

<input alt="" src="https://media.geeksforgeeks.org/wp-content/uploads/Merge_max_heap_1.jpg" style="height:160px; width:300px" type="image">
<input alt="" src="https://media.geeksforgeeks.org/wp-content/uploads/Merge_max_heap_2.jpg" style="height:120px; width:200px" type="image">
<span style="font-size:18px"><input alt="" src="https://media.geeksforgeeks.org/wp-content/uploads/Merge_max_heap_3.jpg" style="height:160px; width:300px" type="image"></span></pre>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>mergeHeaps</strong><strong>()</strong>&nbsp;which takes the array <strong>a[]</strong>, <strong>b[]</strong>, its size <strong>n </strong>and <strong>m,&nbsp;</strong>as inputs and return&nbsp;the merged max heap.&nbsp;Since there can be multiple solutions, therefore, to check for the correctness of your solution, your answer will be checked by the driver code and will return&nbsp;<strong>1</strong>&nbsp;if it is correct, else it returns&nbsp;<strong>0</strong>.</span></p>


<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(n.Logn)<br>
<strong>Expected Auxiliary Space:</strong> O(n + m)</span></p>