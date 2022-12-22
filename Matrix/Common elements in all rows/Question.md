# Common elements in all rows of a given matrix

### Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.

<strong> Example: </strong>
<pre><strong>Input:</strong>
mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

<strong>Output: </strong>
1 8 or 8 1
8 and 1 are present in all rows.</pre>



<strong> hint </strong>
<pre>
The idea is to use maps. We initially insert all elements of the first row in an map.
For every other element in remaining rows, we check if it is present in the map.
If it is present in the map and is not duplicated in current row, we increment count of the element in map by 1, 
else we ignore the element. 
If the currently traversed row is the last row, we print the element if it has appeared m-1 times before.
 </pre>