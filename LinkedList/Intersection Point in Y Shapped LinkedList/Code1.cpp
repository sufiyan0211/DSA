#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}


int size(Node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int l1 = size(head1);
    int l2 = size(head2);
    if(l1 < l2) return intersectPoint(head2, head1);
    
    int diff = l1 - l2;
    
    Node *curr1 = head1;
    Node *curr2 = head2;
    
    while(diff > 0) {
        curr1 = curr1->next;
        diff--;
    }
    
    while(curr1 != curr2) {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    
    if(curr1 == NULL) return -1;
    return curr1->data;
}


int main()
{
    int n1,n2,n3;

    cin>>n1>>n2>>n3;
    
    Node* head1 = inputList(n1);
    Node* head2 = inputList(n2);
    Node* common = inputList(n3);
    
    Node* temp = head1;
    while(temp!=NULL && temp->next != NULL)
        temp = temp->next;
    if(temp!=NULL) temp->next = common;
    
    temp = head2;
    while(temp!=NULL && temp->next != NULL)
        temp = temp->next;
    if(temp!=NULL) temp->next = common;
    
    cout << intersectPoint(head1, head2) << endl;
    
    return 0;
}
