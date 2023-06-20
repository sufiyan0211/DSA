#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
public:
	int *arr;
	int size;
	int capacity;

	MaxHeap() {
		this->capacity = 1e9;
		this->size = -1;
		arr = new int[this->capacity];
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

    bool isEmpty() {
        return (size == -1);
    }

	int top() {
        if(isEmpty()) throw std::underflow_error("Heap is empty");
		return arr[0];
	}

    int getSize() {
        return (this->size)+1;
    }

	void insert(int val) {
        if(size >= capacity) {
            throw std::overflow_error("Heap is full");
            return;
        }
        if(size == -1) {
            size++;
            arr[size] = val;
            return;
        }
		size++;
		arr[size] = val;
		int i = size;
		while(arr[i] > arr[parent(i)]) {
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}

	void heapify(int i) {
		int largest = i;
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
			heapify(largest);
		}
	}

	int extractMin() {
        if(size == -1) {
            cout << "Heap is empty so can't be deleted anything from Heap: ";
            return -1;
        }
        if(size == 0) {
            return arr[size--];
        }
        int ans = arr[0];
		swap(arr[0], arr[size--]);
		heapify(0);
        return ans;
	}
};

int main() {
	MaxHeap maxHeap;

	maxHeap.insert(3);
	maxHeap.insert(2);
	maxHeap.insert(15);
	maxHeap.insert(20);

    cout << maxHeap.extractMin() << endl;
    cout << maxHeap.extractMin() << endl;
    cout << maxHeap.extractMin() << endl;
    cout << maxHeap.extractMin() << endl;
    cout << maxHeap.extractMin() << endl;

	return 0;
}