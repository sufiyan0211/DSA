# How to efficiently implement k stacks in a single array?

<p><strong>Method 1 (Divide the array in slots of size n/k) </strong>A simple way to implement k stacks is to divide the array in k slots of size n/k each, and fix the slots for different stacks, i.e., use arr[0] to arr[n/k-1] for first stack, and arr[n/k] to arr[2n/k-1] for stack2 where arr[] is the array to be used to implement two stacks and size of array be n. The problem with this method is inefficient use of array space. A stack push operation may result in stack overflow even if there is space available in arr[]. For example, say the k is 2 and array size (n) is 6 and we push 3 elements to first and do not push anything to second second stack. When we push 4th element to first, there will be overflow even if we have space for 3 more elements in array.&nbsp;</p>


<p><strong>Method 2 (A space efficient implementation)</strong> The idea is to use two extra arrays for efficient implementation of k stacks in an array. This may not make much sense for integer stacks, but stack items can be large for example stacks of employees, students, etc where every item is of hundreds of bytes. For such large stacks, the extra space used is comparatively very less as we use two <i>integer </i>arrays as extra space.&nbsp;</p>

<p><i><strong>1) top[]:</strong></i><strong> </strong>This is of size k and stores indexes of top elements in all stacks.&nbsp;</p>
<p><i><strong>2) next[]:</strong></i> This is of size n and stores indexes of next item for the items in array arr[].&nbsp;</p>

<p>Here arr[] is actual array that stores k stacks. Together with k stacks, a stack of free slots in arr[] is also maintained. The top of this stack is stored in a variable ‘free’. All entries in top[] are initialized as -1 to indicate that all stacks are empty. All entries next[i] are initialized as i+1 because all slots are free initially and pointing to next slot. Top of free stack, ‘free’ is initialized as 0.&nbsp;</p>