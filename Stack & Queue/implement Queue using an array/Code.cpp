#include<bits/stdc++.h>
using namespace std;

class Queue {
private:
	int size; // index of the last element of queue
	int capacity;
	int *arr;
public:
	Queue(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		this->size = -1;
	}
	bool full() {
		if(size == capacity-1) {
			return true;
		}
		return false;
	}

	bool empty() {
		if(size == -1) {
			return true;
		}
		return false;
	}

	int front() {
		return arr[0];
	}

	int back() {
		return arr[size];
	}

	int pop() {
		if(size == -1) {
			cout << "Queue underflow\n";
			return 0;
		}
		int x = arr[size];
		size--;
		return x;
	}

	void push(int x) {
		if(full()) {
			cout << "Queue overflow\n";
			cout << x << " can't be entered into the Queue\n";
			return;
		}
		size++;
		arr[size] = x;
	}
};

int main() {
	Queue q(5);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);

	while(!q.empty()) {
		cout << "front: " << q.front() << endl;
		cout << "back: " << q.back() << endl;
		cout << endl;

		q.pop();
	}

	q.pop();
	
	return 0;
}