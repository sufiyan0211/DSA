#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}


class Solution{
  public:
    //Function to merge K sorted linked list.
    Node *merge(Node *first, Node* second) {
        if(first == NULL) return second;
        if(second == NULL) return first;
        
        Node *curr1 = first, *curr2 = second, *next;
        Node *head = NULL, *tail = NULL;
        
        while(curr1 != NULL && curr2 != NULL) {
            if(curr1->data <= curr2->data) {
                next = curr1->next;
                if(head == NULL) {
                    head = tail = curr1;
                    curr1->next = NULL;
                    curr1 = next;
                }
                else {
                    tail->next = curr1;
                    tail = tail->next;
                    curr1->next = NULL;
                    curr1 = next;
                }
            }
            else {
                next = curr2->next;
                if(head == NULL) {
                    head = tail = curr2;
                    curr2->next = NULL;
                    curr2 = next;
                }
                else {
                    tail->next = curr2;
                    tail = tail->next;
                    curr2->next = NULL;
                    curr2 = next;
                }
            }
        }
        
        if(curr1 != NULL) {
            tail->next = curr1;
            tail = tail->next;
        }
        else if(curr2 != NULL) {
            tail->next = curr2;
            tail = tail->next;
        }
        return head;
    }
    
    Node * mergeKLists(Node *arr[], int k)
    {
        // Your code here
        Node *ans = NULL;
        for(int i=0;i<k;i++) {
            Node *list = arr[i];
            ans = merge(ans, list);
        }
        return ans;
    }
};


int main()
{
   int N;
   cin>>N;
   struct Node *arr[N];
   for(int j=0;j<N;j++) {
       int n;
       cin>>n;

       int x;
       cin>>x;
       arr[j]=new Node(x);
       Node *curr = arr[j];
       n--;

       for(int i=0;i<n;i++)
       {
           cin>>x;
           Node *temp = new Node(x);
           curr->next = temp;
           curr=temp;
       }
	}

	Solution obj;
	Node *res = obj.mergeKLists(arr,N);
	printList(res);

	return 0;
}