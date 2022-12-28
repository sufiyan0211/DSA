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


Node* middleNode(Node* head) {
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    } 
    return slow;
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

	Node * middle = middleNode(head);
	cout << middle->data << endl;
	
	return 0;
}