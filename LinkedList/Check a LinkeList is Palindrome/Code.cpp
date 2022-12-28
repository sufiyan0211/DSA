#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node *reverse(Node *head) {
        Node *prev = NULL, *curr = head, *next;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *slow = head, *fast = head, *prevSlow;
        while(fast != NULL && fast->next != NULL) {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *first = head, *second;
        if(fast == NULL) {
            // means length is even
            second = slow;
            prevSlow->next = NULL;
        }
        else {
            // means length is odd
            second = slow->next;
            slow->next = NULL;
        }
        
        second = reverse(second);
        
        while(first != NULL && second != NULL) {
            
            if(first->data != second->data) {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        
        return true;
    }
};


int main()
{
    int i,n,l,firstdata;
    struct Node *head = NULL,  *tail = NULL;
    cin>>n;
    // taking first data of LL
    cin>>firstdata;
    head = new Node(firstdata);
    tail = head;
    // taking remaining data of LL
    for(i=1;i<n;i++)
    {
        cin>>l;
        tail->next = new Node(l);
        tail = tail->next;
    }
    Solution obj;
	cout<<obj.isPalindrome(head)<<endl;
    
    return 0;
}