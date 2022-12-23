# In-Place Merge Sort

#### Implement Merge Sort i.e. standard implementation keeping the sorting algorithm as in-place. In-place means it does not occupy extra memory for merge operation as in the standard case.


<strong> Examples: </strong>
<blockquote><p><strong>Input:</strong> arr[] = {2, 3, 4, 1}&nbsp;<br><strong>Output:</strong> 1 2 3 4</p><p><strong>Input:</strong> arr[] = {56, 2, 45}&nbsp;<br><strong>Output:</strong> 2 45 56&nbsp;</p></blockquote>

<p><strong>Approach : </strong>The idea: We start comparing elements that are far from each other rather than adjacent. Basically we are using shell sorting to <a href="https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/">merge two sorted arrays with O(1) extra space</a>.</p>

<p>mergeSort():&nbsp;</p>
<ul><li>Calculate mid two split the array in two halves(left sub-array and right sub-array)</li><li>Recursively call merge sort on left sub-array and right sub-array to sort them</li><li>Call merge function to merge left sub-array and right sub-array</li></ul>

<p>merge():</p>
<ul><li>For every pass, we calculate the gap and compare the elements towards the right of the gap.</li><li>Initiate the gap with ceiling value of n/2 where n is the combined length of left and right sub-array.</li><li>Every pass, the gap reduces to the ceiling value of gap/2.</li><li>Take a pointer i to pass the array.</li><li>Swap the ith and (i+gap)th elements if (i+gap)th element is smaller than(or greater than when sorting in decreasing order) ith element.</li><li>Stop when (i+gap) reaches n.</li></ul>

<blockquote><p><strong>Input: </strong>10, 30, 14, 11, 16, 7, 28</p><p>Note: Assume left and right subarrays has been sorted so we are merging sorted subarrays [10, 14, 30] and [7, 11, 16, 28]</p><p>Start with</p><p>gap = &nbsp;ceiling of n/2 = 7/2 = 4</p><p>[This gap is for whole merged array]</p><p><strong>10</strong>, 14, 30, 7, <strong>11</strong>, 16, 28</p><p>10, <strong>14</strong>, 30, 7, 11, <strong>16</strong>, 28</p><p>10, 14, <strong>30</strong>, 7, 11, 16, <strong>28</strong></p><p>10, 14, 28, 7, 11, 16, 30</p><p>gap = &nbsp;ceiling of 4/2 = 2</p><p><strong>10</strong>, 14, <strong>28</strong>, 7, 11, 16, 30</p><p>10, <strong>14</strong>, 28, <strong>7</strong>, 11, 16, 30</p><p>10, 7, <strong>28</strong>, 14, <strong>11</strong>, 16, 30</p><p>10, 7, 11, <strong>14</strong>, 28, <strong>16</strong>, 30</p><p>10, 7, 11, 14, <strong>28</strong>, 16, <strong>30</strong></p><p><strong>&nbsp;</strong></p><p>gap = &nbsp;ceiling of 2/2 = 1</p><p><strong>10</strong>, <strong>7</strong>, 11, 14, 28, 16, 30</p><p>7, <strong>10</strong>, <strong>11</strong>, 14, 28, 16, 30</p><p>7, 10, <strong>11</strong>, <strong>14</strong>, 28, 16, 30</p><p>7, 10, 11, <strong>14</strong>, <strong>28</strong>, 16, 30</p><p>7, 10, 11, 14, <strong>28</strong>, <strong>16</strong>, 30</p><p>7, 10, 11, 14, 16, <strong>28</strong>, <strong>30</strong></p><p><strong>&nbsp;</strong></p><p><strong>Output: </strong>7, 10, 11, 14, 16, 28, 30</p></blockquote>