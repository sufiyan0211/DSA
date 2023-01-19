#include <bits/stdc++.h>
using namespace std;


class MaxHeap {
public:
	int *arr;
	int size;
	int capacity;

	MaxHeap(int capacity, int size) {
		this->capacity = capacity;
		this->size = size;
		arr = new int[capacity];
	}

	int left(int i) {
		return (2*i)+1;
	}

	int right(int i) {
		return (2*i)+2;
	}

	int parent(int i) {
		return (i-1)/2;
	}

	int top() {
		return arr[0];
	}

	void insert(int x) {
		size++;
		arr[size-1] = x;
		int i = size-1;
		while(arr[i] > arr[parent(i)]) {
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}

	void heapify(int i, int &largest) {
		largest = i;

		int rt = right(i);
		int lt = left(i);

		if(lt<size && arr[lt] > arr[largest]) {
			largest = lt;
		}
		if(rt<size && arr[rt] > arr[largest]) {
			largest = rt;
		}

		if(largest != i) {
			swap(arr[largest], arr[i]);
			heapify(largest, largest);
		}
	}

	void delet() {
		// This means we need to delete the top element
		arr[0] = INT_MIN;
		int largest = 0;
		heapify(0, largest);
		swap(arr[size-1], arr[largest]);
		size--;
	}
};

int main() {
	MaxHeap maxHeap(1000, 0);

	maxHeap.insert(50);
	maxHeap.insert(60);
	maxHeap.insert(40);
	cout << "Top: " << maxHeap.top() << endl;

	/*
	cout << "Printing arr\n";
	for(int i=0;i<3;i++) {
		cout << i << ": " << maxHeap.arr[i] << endl;
	}cout << endl;
	*/
	

	

	cout << "Deleting....\n";
	maxHeap.delet();
	cout << "Top: " << maxHeap.top() << endl;

	/*
	cout << "Printing arr\n";
	for(int i=0;i<3;i++) {
		cout << i << ": " << maxHeap.arr[i] << endl;
	}cout << endl;
	*/

	cout << "Deleting....\n";
	maxHeap.delet();
	cout << "Top: " << maxHeap.top() << endl;

	/*
	cout << "Printing arr\n";
	for(int i=0;i<3;i++) {
		cout << i << ": " << maxHeap.arr[i] << endl;
	}cout << endl;
	*/


	

	
	return 0;
}