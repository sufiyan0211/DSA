#include <bits/stdc++.h>
using namespace std;


long long minCost(long long arr[], long long n) {
    // Your code here
    priority_queue<long long, vector<long long>, greater<long long> > minHeap;
    for(long long i=0;i<n;i++) {
        minHeap.push(arr[i]);
    }
    
    long long ans = 0;
    while(minHeap.size() >= 2) {
        long long first = minHeap.top();
        minHeap.pop();
        long long second = minHeap.top();
        minHeap.pop();
        long long sum = first + second;
        ans += sum;
        minHeap.push(sum);
    }
    return ans;
}


int main() {
	long long n = 4;
	long long arr[] = {4, 3, 2, 6};

	cout << minCost(arr, n) << endl;

	return 0;
}






