#include <bits/stdc++.h>
using namespace std;


class MinHeap {
public:
	int *arr;
	int size;
	int capacity;

	MinHeap(int capacity, int size) {
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
		while(arr[i] < arr[parent(i)]) {
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}

	void heapify(int i, int &smallest) {
		smallest = i;

		int rt = right(i);
		int lt = left(i);

		if(lt<size && arr[lt] < arr[smallest]) {
			smallest = lt;
		}
		if(rt<size && arr[rt] < arr[smallest]) {
			smallest = rt;
		}

		if(smallest != i) {
			swap(arr[smallest], arr[i]);
			heapify(smallest, smallest);
		}
	}

	void delet() {
		// This means we need to delete the top element
		arr[0] = INT_MAX;
		int smallest = 0;
		heapify(0, smallest);
		swap(arr[size-1], arr[smallest]);
		size--;
	}
};

int main() {
	MinHeap minHeap(1000, 0);

	minHeap.insert(50);
	minHeap.insert(60);
	minHeap.insert(40);

	/*
	cout << "Printing arr\n";
	for(int i=0;i<3;i++) {
		cout << i << ": " << minHeap.arr[i] << endl;
	}cout << endl;
	*/
	

	cout << "Top: " << minHeap.top() << endl;

	cout << "Deleting....\n";
	minHeap.delet();
	cout << "Top" << minHeap.top() << endl;

	/*
	cout << "Printing arr\n";
	for(int i=0;i<3;i++) {
		cout << i << ": " << minHeap.arr[i] << endl;
	}cout << endl;
	*/

	cout << "Deleting....\n";
	minHeap.delet();
	cout << "Top: " << minHeap.top() << endl;

	/*
	cout << "Printing arr\n";
	for(int i=0;i<3;i++) {
		cout << i << ": " << minHeap.arr[i] << endl;
	}cout << endl;
	*/


	

	
	return 0;
}