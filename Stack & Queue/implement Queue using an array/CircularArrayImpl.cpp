#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Queue {
private:
	T *arr;
	int size;
	int count;
	int front;
	int rear;

public:
	Queue(int size) {
		this->size = size;
		count = 0;
		front = 0;
		rear = -1;

		arr = new T[size];
	}

	~Queue() {
		delete[] arr;
	}

	void enqueue(T item) {
		if(isFull()) {
			throw overflow_error("Queue is full");
		}
		rear = (rear+1) % size;
		arr[rear] = item;
		count++;
	}

	T dequeue() {
		if(isEmpty()) {
			throw underflow_error("Queue is empty");
		}

		T item = arr[front];
		front = (front + 1) % size;
		count--;

		return item;
	}

	bool isFull() {
		return count == size;
	}

	bool isEmpty() {
		return count == 0;
	}

	T frontElement() {
		if(isEmpty()) {
			throw underflow_error("Queue is empty");
		}
		return arr[front];
	}

};

int main() {
	Queue<int> q(5);

	q.enqueue(11);
	q.enqueue(12);
	q.enqueue(13);
	q.enqueue(14);
	q.enqueue(15);
	
	q.dequeue();

	cout << q.frontElement() << endl;


	return 0;
}