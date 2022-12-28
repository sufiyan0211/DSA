#include<bits/stdc++.h>
using namespace std;
 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
 
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);
    
    return new_Node;
}
 
 
 Node *reverse(Node **r)
{
    Node *prev =NULL;
    Node *cur = *r;
    Node *nxt;
    while(cur!=NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
    return prev;
}

void push(struct Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node = newNode(new_data);
 
    /* link the old list off the new Node */
    new_Node->next = (*head_ref);
 
    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}


void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {

        temp=Node;
        Node = Node->next;
        free(temp);
    }

}

 
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
    long long x=0;
    long long y=0;
    Node *p=l1;
    Node *q=l2;
    while(p){
        x=((x*10)+p->data)%1000000007;
        p=p->next;
    }
    while(q){
        y=((y*10)+q->data)%1000000007;
        q=q->next;
    }
    long long ans= (x*y)%1000000007;
    return ans;
}

 
int main(void)
{
    int n,m,i,x;

    struct Node* first = NULL;
    struct Node* second = NULL;
    cin>>n;
    for(i=0;i<n;i++)
    {
		cin>>x;
		push(&first, x);
    }
     cin>>m;
    for(i=0;i<m;i++)
    {
		cin>>x;
    push(&second, x);
    }

     reverse(&first);
     reverse(&second);
	 long long res = multiplyTwoLists(first,second);
    
    cout<<res<<endl;
    freeList(first);
    freeList(second);
   
   return 0;
}

























