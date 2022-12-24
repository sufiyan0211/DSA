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
};


void printList(Node* head) {
	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	} cout << endl;
}


int main() {
	Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);
    head1->next->next->next->next->next->next = new Node(7);

    printList(head1);
	return 0;
}