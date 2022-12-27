#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}


Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *curr1 = head1, *curr2 = head2;
    Node *head = NULL, *tail=NULL;
    
    while(curr1!=NULL && curr2!=NULL) {
        if(curr1->data == curr2->data) {
            if(head == NULL) {
                head = tail = new Node(curr1->data);
            }
            else {
                tail->next = new Node(curr1->data);
                tail = tail->next;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        else if(curr1->data < curr2->data) {
            curr1 = curr1->next;
        }
        else {
            curr2 = curr2->next;
        }
    }
    
    return head;
}

int main()
{

    int n,m;
    cin>> n >> m;
    
    Node* head1 = inputList(n);
    Node* head2 = inputList(m);
    
    Node* result = findIntersection(head1, head2);
    
    printList(result);
    cout<< endl;
    return 0;
}