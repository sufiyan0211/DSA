#include <bits/stdc++.h>
using namespace std;

int nextGap(int n) {
	if(n <= 1) return 0;
	return (n/2 + n%2);
}

void merge(int arr[], int left, int mid, int right) {

	int n = right - left + 1;
	int gap = n; 

	for(gap=nextGap(gap); gap > 0; gap=nextGap(gap)) {
		for(int i = left; i+gap <= right; i++) {
			if(arr[i] > arr[i+gap]) {
				swap(arr[i], arr[i+gap]);
			}
		}
	}
}

void mergeSort(int arr[], int left, int right) {
	if(left < right) {
		int mid = (left + right) >> 1;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}

int main() {
	int n; cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}

	mergeSort(arr, 0, n-1);

	cout << "\nSorted array is: \n";
	for(int i=0;i<n;i++) {
		cout << arr[i] << " ";
	} cout << endl;


	return 0;
}