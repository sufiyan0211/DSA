#include <iostream>
using namespace std;


class MaxHeap {
private:
    int *arr;
    int size;
    int capacity;
public:
    MaxHeap() {
        this->capacity = 1e9;
        this->size = -1;
        arr = new int[this->capacity];
    }

    int left(int i) {
        return (2 * i) + 1;
    }

    int right(int i) {
        return (2 * i) + 2;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    bool isEmpty() {
        return (size == -1);
    }

    int top() {
        if(isEmpty()) throw std::underflow_error("Heap is empty");
        return arr[0];
    }

    int getSize() {
        return size+1;
    }

    void insert(int val) {
        if(size >= capacity) throw std::overflow_error("Heap is full");
        if(isEmpty()) {
            size++;
            arr[size] = val;
            return;
        }

        size++;
        arr[size] = val;
        int i = size;
        while (arr[i] > arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.insert(70);
    cout << maxHeap.top() << endl;

    maxHeap.insert(60);
    cout << maxHeap.top() << endl;

    maxHeap.insert(80);
    cout << maxHeap.top() << endl;

    return 0;
}