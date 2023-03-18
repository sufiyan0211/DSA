#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap {
public:
	int *arr;
	int size;
	int capacity;

	MinHeap(int capacity) {
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
		while(arr[i] < arr[parent(i)]) {
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}

	void heapify(int i) {
		int smallest = i;
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
            heapify(smallest);
		}
	}

	int extractMax() {
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
    MinHeap minHeap(11);

    minHeap.insert(3);
    minHeap.insert(2);
    minHeap.insert(15);
    minHeap.insert(20);

    cout << minHeap.extractMax() << endl;
    cout << minHeap.extractMax() << endl;
    cout << minHeap.extractMax() << endl;
    cout << minHeap.extractMax() << endl;
    cout << minHeap.extractMax() << endl;
	return 0;
}