#include <bits/stdc++.h>
using namespace std;

class kQueues {
private :
	int *arr;
	int frespot;
	int *front;
	int *rear;
	int *next;
public:
	kQueues(int n, int k) {
		arr = new int[n];
		next = new int[n];
		front = new int[k];
		rear = new int[k];

		freespot = 0;
		for(int i=0;i<n;i++) {
			next[i] = i+1;
		}
		next[n-1] = -1;


		for(int i=0;i<k;i++) {
			front[i] = -1;
			rear[i] = -1;
		}
	}

	void push(int x, int k) {
		if(freespot == -1) {
			cout << x << " can't be entered into the queue because queue is already full\n";
			return;
		}

		int index = freespot;
		arr[index] = x;
		freespot = next[index];

		if(front[k] == -1) {
			front[k] = index;
		}
		else {
			next[rear[k]] = index;
		}

		next[index] = -1;

		rear[k] = index;
	}

	int pop(int k) {
		if(front[k] == -1) {
			cout << "underflow\n";
			return 0;
		}

		int index = front[k];

		front[k] = next[index];

		next[index] = freespot;
		freespot = index;

		return arr[index];
	}
};


int main() {

    kQueues q(10, 2);
    q.push(10, 0);
    q.push(15,0);
    q.push(20, 1);
    q.push(25,0);

    cout << q.pop(0) << endl;
    cout << q.pop(1) << endl;
    cout << q.pop(0) << endl;
    cout << q.pop(0) << endl;

    cout << q.pop(0) << endl;

    return 0;
}