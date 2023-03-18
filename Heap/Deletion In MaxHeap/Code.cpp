#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
public:
	int *arr;
	int size;
	int capacity;

	MaxHeap(int capacity) {
		this->capacity = capacity;
		this->size = 0;
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
        if(size == 0) {
            cout << "Heap is empty so can't be deleted anything from Heap: ";
            return -1;
        }
        if(size == 1) {
            cout << "This the last element of Heap which is deleted: ";
            size--;
            return arr[size];
        }
        int ans = arr[0];
        size--;
		swap(arr[0], arr[size]);
		heapify(0);
        return ans;
	}
};

int main() {
	MaxHeap maxHeap(11);

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