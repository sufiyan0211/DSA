class Solution{
public:
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> maxHeap;
        for(int i = l; i<k; i++) {
            maxHeap.push(arr[i]);
        }

        for(int i = k; i <= r; i++) {
            if(arr[i] < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
        return maxHeap.top();
    }
};