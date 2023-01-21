#include <bits/stdc++.h>
using namespace std;


vector<int> kLargest(int arr[], int n, int k) {
    // code here
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    for(int i=0;i<k;i++) {
        minHeap.push(arr[i]);
    }
    
    for(int i=k;i<n;i++) {
        if(minHeap.top() < arr[i]) {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    
    vector<int> ans(k);
    for(int i = k-1; i >= 0; i--) {
        ans[i] = minHeap.top();
        minHeap.pop();
    }
    
    return ans;
}


int main() {
	int n = 5, k = 2;
	int arr[] = {12, 5, 787, 1, 23};

	vector<int> ans = kLargest(arr, n, k);

	for(auto x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}

