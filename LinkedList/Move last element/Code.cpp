#include <bits/stdc++.h>
using namespace std;

class Node {
public :
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
	Node() {
	}
};

void printList(Node *head) {

	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	} cout << endl;

}

Node *moveLastElement(Node *head) {
	Node *curr = head;
	Node *prev = NULL;

	while(curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = NULL;
	curr->next = head;

	return curr;
}


int main() {
	int n; cin >> n;
	Node *head = NULL, *tail = NULL;

	for(int i=0;i<n;i++) {
		int temp; cin >> temp;
		if(head == NULL){
			head = tail = new Node(temp);
		}
		else {
			tail->next = new Node(temp);
			tail = tail->next;
		}
	}
	Node *ans = moveLastElement(head);
	printList(ans);
}