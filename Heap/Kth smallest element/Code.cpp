#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    priority_queue<int> maxHeap;
    for(int i=l;i<k;i++) {
        maxHeap.push(arr[i]);
    }
    
    for(int i=k;i<=r;i++) {
        if(arr[i] < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    return maxHeap.top();
}


int main() {
	int n = 6;
	int arr[] = {7,10,4,3,20,15};
	int k = 3;

	cout << kthSmallest(arr, 0, n-1, k) << endl;

	return 0;
}

