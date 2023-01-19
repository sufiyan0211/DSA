#include <bits/stdc++.h>
using namespace std;


class MaxHeap {
private:
	int *arr;
	int size;
	int capacity;
public:
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
};

int main() {
	MaxHeap maxHeap(1000, 0);
	maxHeap.insert(50);
	cout << maxHeap.top() << endl;
	maxHeap.insert(60);
	cout << maxHeap.top() << endl;
	maxHeap.insert(40);
	cout << maxHeap.top() << endl;
	
	return 0;
}