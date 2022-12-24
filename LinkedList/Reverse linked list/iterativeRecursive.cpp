#include <bits/stdc++.h>
using namespace std;

class Node {
	public :
		int data;
		Node * next;
		Node(int data) {
			this->data = data;
			this->next = NULL;
		}
		Node() {

		}
};


void printList(Node* head) {
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	} cout << endl;
}

Node *iterativeReverse(Node *head) {
	Node *prev = NULL;
	Node *curr = head;
	Node *next;
	while(curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}



int main() {
	int n; cin >> n;

	Node* head;
	Node* nextNode;

	for(int i=0;i<n;i++) {
		int temp; cin >> temp;
		if(i == 0) {
			head = new Node(temp);
			nextNode = head;		
		}
		else {
			nextNode->next = new Node(temp);
			nextNode = nextNode->next;
		}
	}

	cout << "LinkedList before reversing: \n";
	printList(head);

	Node *newHead = iterativeReverse(head);
	cout << "LinkedList after reversing: \n";
	printList(newHead);


	return 0;
}