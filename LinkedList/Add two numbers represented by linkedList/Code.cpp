#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
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
    cout<< endl;
}


class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    int size(struct Node *head) {
        int count = 0;
        while(head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }
    
    struct Node *add(struct Node *first, struct Node *second) {
        int carry = 0;
        struct Node *head = first;
        struct Node *prev;
        
        while(first != NULL && second != NULL) {
            int sum = first->data + second->data + carry;
            first->data = sum % 10;
            carry = sum / 10;
            
            prev = first;
            first = first->next;
            second = second->next;
        }
        
        while(first != NULL && carry != 0) {
            int sum = first->data + carry;
            first->data = sum % 10;
            carry = sum / 10;
            
            prev = first;
            first = first->next;
        }
        
        if(carry != 0) {
            struct Node *newNode = new Node(carry);
            if(prev != NULL) prev->next = newNode;
        }
        return head;
    }
    
    struct Node *reverse(struct Node *head) {
        struct Node *prev = NULL;
        struct Node *curr = head;
        while(curr != NULL) {
            struct Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        if(size(first) < size(second)) 
            return addTwoLists(second, first);
        
        first = reverse(first);
        second = reverse(second);
        
        first = add(first, second);
        
        return reverse(first);
    }
};



int main()
{
    int n, m;   
    cin>>n;
    Node* first = buildList(n);
    
    cin>>m;
    Node* second = buildList(m);
    Solution ob;
    Node* res = ob.addTwoLists(first,second);
    printList(res);
    
    return 0;
}