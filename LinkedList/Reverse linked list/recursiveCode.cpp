#include<bits/stdc++.h>
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


Node *recursiveReverse(Node *head) {
	if(head == NULL && head->next == NULL) {
		return head;
	}

	Node *newHead = recursiveReverse(head->next);
	Node *nextToHead = head->next;
	nextToHead->next = head;
	head->next = NULL;
	return newHead;
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

	Node *newHead = recursiveReverse(head);
	cout << "LinkedList after reversing: \n";
	printList(newHead);


	return 0;
}