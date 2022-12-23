#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1; // {arr[left], ... , arr[mid]}
	int n2 = right - mid;	 // {arr[mid+1], ..., arr[right]}

	int a[n1], b[n2];

	int k = 0;
	for(int i=left;i<=mid;i++) {
		a[k++] = arr[i];
	}

	k = 0;
	for(int i=mid+1;i<=right;i++) {
		b[k++] = arr[i];
	}

	int i = 0, j = 0;
	k = left;
	while(i<n1 && j<n2) {
		if(a[i] <= b[j]) {
			arr[k++] = a[i++];
		}
		else {
			arr[k++] = b[j++];
		}
	}

	while(i<n1) {
		arr[k++] = a[i++];
	}
	while(j<n2) {
		arr[k++] = b[j++];
	}

}

void mergeSort(int arr[], int left, int right) {
	if(left < right) {
		int mid = (left+right) >> 1;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, mid, right); // merge(arr, left, right);
	}
}

int main() {
	int n; cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}
	mergeSort(arr, 0, n-1);
	for(auto i: arr) {
		cout << i << " ";
	} cout << endl;
	return 0;
}




