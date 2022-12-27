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

int addOneToend(Node *head) {
	if(head == NULL) return 1;

	int res = head->data + addOneToend(head->next);

	head->data = res%10;
	return (res/10);
}


Node *addOne(Node *head) {
	int carry = addOneToend(head);

	if(carry != 0) {
		Node *newNode = new Node(carry);
		newNode->next = head;
		return newNode;
	}
	return head;
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