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
	cout << "Printing List: \n";
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	} cout << endl;
}

Node *addOneUtil(Node *head) {
	Node *prev = head;
	Node *curr = head->next;

	int carry = 1;
	int sum = head->data + carry;
	head->data = sum % 10;
	carry = sum/10;

	while(curr != NULL) {
		prev = curr;

		sum = curr->data + carry;
		curr->data = sum%10;
		carry = sum/10;

		curr = curr->next;
	}

	if(carry != 0) {
		Node *newNode = new Node(carry);
		prev->next = newNode;
	}
	return head;
}

Node *reverse(Node *head) {
	Node *prev = NULL;
	Node *curr = head;
	while(curr != NULL) {
		Node *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}


Node *addOne(Node *head) {
	head = reverse(head);

	head = addOneUtil(head);

	return reverse(head);
}


int main() {
	int n; cin >> n;
	Node *head = NULL, *tail = NULL;
	for(int i=0;i<n;i++) {
		int temp; cin >> temp;
		if(head == NULL) {
			head = tail = new Node(temp);
		}
		else {
			tail->next = new Node(temp);
			tail = tail->next;
		}
	}

	head = addOne(head);
	printList(head);
	return 0;

}