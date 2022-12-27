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


class Solution
{
    public:
    Node * removeDuplicates( Node *head) 
    {
        if(head == NULL || head->next == NULL) return head;
        
        unordered_set<int> us;
        Node *prev = head;
        us.insert(prev->data);
        Node *curr = head->next;
     
        while(curr != NULL) {
            Node *next = curr->next;
            if(us.count(curr->data) > 0) {
                prev->next = next;
                us.insert(curr->data);
                curr = next;
            }
            else {
                us.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};


int main() {
	int K;
	cin>>K;
	struct Node *head = NULL;
    struct Node *temp = head;

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
	
    Solution ob;
	Node *result  = ob.removeDuplicates(head);
	print(result);
	cout<<endl;
		
	return 0;
}