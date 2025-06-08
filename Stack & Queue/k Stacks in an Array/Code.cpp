#include<bits/stdc++.h>

using namespace std;

class Node {
public:
	int index;
	Node *next;

	Node(int x) {
		index = x;
		next = NULL;
	}
};

class Nstack {
public:
	int* arr; // original array
	Node** topp; // top element index of particular array
	Stack<int> emptyIndexes; // Empty index 

	// n is number of stack and s size of an array
	Nstack(int n, int s) {
		arr = new int[s];
		topp = new Node*[n];

		for(int i=0; i<n; i++) {
			topp[i] = NULL;
		}
		for(int i=0; i<s ;i++) {
			emptyIndexes.push(i);
		}
	}

	// push element x in mth stack
	bool push(int x, int m) {
		if(emptyIndexes.empty()) {
			return false;
		}

		int availableIndex = emptyIndexes.top();

		arr[availableIndex] = x;

		Node *temp = new Node(availableIndex);
		temp->next = topp[m-1];
		topp[m-1] = temp;


		emptyIndexes.pop();

		return true;
	}

	// pop element from mth Stack
	int pop(int m) {
		if(topp[m-1] == NULL) {
			return -1;
		}

		int availableIndex = topp[m-1]->index;

		int element = arr[topp[m-1]->index];
		topp[m-1] = topp[m-1]->next;

		emptyIndexes.push(availableIndex);

		return element;
	}

	// return top element of mth Stack
	int top(int m) {
		if(topp[m-1] == NULL) {
			return -1;
		}

		return arr[topp[m-1]->index];
	}

};


int main() {

	Nstack nStack(3, 20); // 3 stacks in an array of size 20

	nstack.push(11, 1);
	nstack.push(12, 2);
	nstack.push(13, 3);
	nstack.push(14, 1);
	nstack.push(15, 2);
	nstack.push(16, 3);
	nstack.push(17, 1);
	nstack.push(18, 2);
	nstack.push(19, 3);
	nstack.push(20, 1);
	nstack.push(21, 2);
	nstack.push(22, 3);

	cout << "operations on stack-1" << endl;
	cout << nStack.top(1) << endl;

	nStack.pop(1);
	cout << nStack.top(1) << endl;


	nStack.pop(1);
	cout << nStack.top(1) << endl;


	cout << "operations on stack-2" << endl;
	cout << nStack.top(2) << endl;

	nStack.pop(2);
	cout << nStack.top(2) << endl;


	nStack.pop(2);
	cout << nStack.top(2) << endl;

	return 0;
}