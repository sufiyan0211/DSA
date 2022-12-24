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


Node *reverse(Node *head, int k) { 
    if( head == NULL) return NULL;
    
    Node *curr = head;
    Node *prev = NULL;
    Node *next;
    int count = 0;
    
    while(curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    if(next != NULL)
        head->next = reverse(next, k);
        
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

    int k; cin >> k;

    cout << "LinkedList before reversing: \n";
    printList(head);

    Node *newHead = reverse(head, k);
    cout << "LinkedList after reversing: \n";
    printList(newHead);


    return 0;
}