#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = (2*i)+1;
	int right = (2*i)+2;

	if(left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	if(right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	if(i != largest) {
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}
}

void build(int arr[], int n) {
	for(int i=(n-2)/2; i>=0; i--) {
		heapify(arr, n, i);
	}
}

void heapSort(int arr[], int n) {
	build(arr, n);

	for(int i=n-1;i>=0;i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main() {

	int arr[] = {10, 5, 11, 5, 8, 10, 17, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Array before sorting:\n";
	for(auto x: arr) {
		cout << x << " ";
	} cout << "\n\n";


	heapSort(arr, n);

	cout << "Array after sorting:\n";
	for(auto x: arr) {
		cout << x << " ";
	} cout << "\n\n";


	return 0;
}