#include <bits/stdc++.h>
using namespace std;


void heapify(vector<int> &arr, int &n, int i) {
    int largest = i;
    int left = (2*i)+1, right = (2*i)+2;
    
    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;
    
    if(i != largest) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void buildHeap(vector<int> &arr, int &n) {
    for(int i=(n-2)/2; i>=0; i--) {
        heapify(arr, n, i);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    vector<int> c;
    int i = 0, j = 0;
    
    while(i<n || j<m) {
        if(i<n) {
            c.push_back(a[i++]);
        }
        if(j<m) {
            c.push_back(b[j++]);
        }
    }
    n = c.size();
    buildHeap(c, n);
    return c;
}

int main() {
	int n = 4, m = 3;
	vector<int> a = {10, 5, 6, 2};
	vector<int> b = {12, 7, 9}; 

	mergeHeaps(a, b, n, m);

	return 0;
}