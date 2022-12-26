#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}

Node *removeDuplicates(Node *head)
{
    Node *curr = head;
    while(curr != NULL) {
        Node *next = curr->next;
        while(next != NULL && next->data == curr->data) {
            curr->next = next->next;
            next=next->next;
        }
        if(curr != NULL) {
            curr = curr->next;
        }
        else break;
    }
    return head;
}

int main() {
    int K;
	cin>>K;
	Node *head = NULL;
    Node *temp = head;

	for(int i=0;i<K;i++){
	int data;
	cin>>data;
		if(head==NULL)
		head=temp=new Node(data);
		else
		{
			temp->next = new Node(data);
			temp=temp->next;
		}
	}
	
	Node *result  = removeDuplicates(head);
	print(result);
	cout<<endl;
	return 0;
}

