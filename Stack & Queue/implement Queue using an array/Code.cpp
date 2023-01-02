#include<bits/stdc++.h>
using namespace std;

// element should be deleted from front
// And element should be added at last
class Queue {
private:
	int size; // index of the last element of queue
	int capacity;
	int *arr;
	int front;
	int back;
public:
	Queue(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		size = 0;
		front = -1;
		back = -1;
	}
	bool full() {
		if(front == 0 && back == capacity-1) {
			return true;
		}
		if(front == back + 1) return true;
		return false;
	}

	bool empty() {
		if(front == -1 && back == -1) {
			return true;
		}
		return false;
	}

	int getFront() {
		if(empty() == true){
			cout << "Queue is empty\n";
			return -1;
		}
		return arr[front];
	}

	int getBack() {
		if(empty() == true){
			cout << "Queue is empty\n";
			return -1;
		}
		return arr[back];
	}

	int pop() {
		if(empty() == true) {
			cout << "Queue underflow\n";
			return 0;
		}
		int x = arr[front];
		if(front == back) {
			front = -1;
			back = -1;
			return x;
		}
		front += 1;
		if(front == capacity) {
			front = 0;
			return x;
		}
 		return x;
	}

	void push(int x) {
		if(full()) {
			cout << "#72 Queue overflow\n";
			cout << x << " can't be entered into the Queue\n";
			return;
		}
		if(empty() == true) {
			front = 0;
			back = 0;
			arr[back] = x;
			return;
		}
		
		if(back == capacity-1) {
			back = 0;
			if(front == 0) {
				cout << "#86 Queue overflow\n";
				cout << x << " can't be entered into the Queue\n";
				return;
			}
			else {
				arr[back] = x;
				return;
			}
		}
		
		back += 1;
		arr[back] = x;
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

	q.pop();
	q.pop();

	cout << "Front : " << q.getFront() << endl;
	cout << "Back : " << q.getBack() << endl;
	cout << endl;

	q.push(6);

	cout << "Front : " << q.getFront() << endl;
	cout << "Back : " << q.getBack() << endl;
	cout << endl;

	q.push(7);

	cout << "Front : " << q.getFront() << endl;
	cout << "Back : " << q.getBack() << endl;
	cout << endl;

	q.push(8);

	q.pop();

	cout << "Front : " << q.getFront() << endl;
	cout << "Back : " << q.getBack() << endl;
	cout << endl;

	q.push(8);

	cout << "Front : " << q.getFront() << endl;
	cout << "Back : " << q.getBack() << endl;
	cout << endl;

	
	return 0;
}