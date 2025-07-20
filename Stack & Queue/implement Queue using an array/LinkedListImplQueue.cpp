#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node<T> * next;


	Node(T data) {
		this->data = data;
		next = NULL;
	}
};


template<typename T>
class Queue {
private:
	T *arr;
	int count;
	Node<T> *front;
	Node<T> *rear;

public:
	Queue() {
		count = 0;
		front = NULL;
		rear = NULL;
	}

	~Queue() {
		while(front != NULL) {
			Node<T> *temp = front;
			front = front->next;
			delete temp;
		}
		rear = NULL;
		count = 0;
	}

	void enqueue(T item) {
		Node<T> *newNode = new Node<T>(item);

		if(front == NULL) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
		count++;
	}

	T dequeue() {
		if(isEmpty()) {
			throw underflow_error("Queue is empty");
		}

		Node<T> *temp = front;
		T item = front->data;
		front = front->next;

		if(front == NULL) {
			rear = NULL;
		}

		count--;

		delete temp;

		return item;
	}

	bool isEmpty() {
		return count == 0 or front == NULL;
	}

	T frontElement() {
		if(isEmpty()) {
			throw underflow_error("Queue is empty");
		}
		return front->data;
	}

};

int main() {
	Queue<int> q;

	q.enqueue(11);
	q.enqueue(12);
	q.enqueue(13);
	q.enqueue(14);
	q.enqueue(15);

	q.dequeue();

	cout << q.frontElement() << endl;


	return 0;
}