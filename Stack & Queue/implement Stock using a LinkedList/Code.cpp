#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};


void printList(Node *head) {
	cout << "\nPrinting list: \n";
	while(head!=NULL) {
		cout << head->data << " ";
		head = head->next;
	} cout << endl;
}

class Stack {
public:
	Node *top;

	Stack() {
		top = NULL;
	}

	void push(int value) {
		Node *temp = new Node(value);

		temp->next = top;
		top = temp;
	}

	int pop() {
		if(top == NULL) {
			cout << "stack is underflow\n";
			return 0;
		}
		Node *temp = top;
		top = top->next;
		return temp->data;
	}

	bool empty() {
		if(top == NULL){
			return true;
		}
		return false;
	}

	int topp() {
		if(top == NULL) {
			cout << "stack is empty\n";
			return -1;
		}
		return top->data;
	}
};


int main() {
	int n; cin >> n;
	Stack s;
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		s.push(x);
	}

	while(!s.empty()) {
		cout << s.topp() << " ";
		s.pop();
	} cout << endl;

	return 0;
}









