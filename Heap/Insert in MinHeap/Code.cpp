#include <iostream>
using namespace std;


class MinHeap {
private:
	int *arr;
	int size;
	int capacity;
public:
	MinHeap() {
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
        if(isEmpty()) throw std::underflow_error("heap is empty");
		return arr[0];
	}

    int getSize() {
        return size+1;
    }

	void insert(int val) {
        if(size >= capacity) throw std::overflow_error("Heap is overflow");
        if(isEmpty()) {
            arr[++size] = val;
            return;
        }

        size++;
        arr[size] = val;
        int i = size;
        while(arr[i] < arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
	}
};

int main() {
	MinHeap minHeap;

    minHeap.insert(50);
	cout << minHeap.top() << endl;

    minHeap.insert(60);
	cout << minHeap.top() << endl;

    minHeap.insert(40);
	cout << minHeap.top() << endl;
	
	return 0;
}