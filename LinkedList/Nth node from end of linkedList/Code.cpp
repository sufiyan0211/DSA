#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


int getNthFromLast(Node *head, int n)
{
    Node *first = head, *second = head;
    n = n-1;
    while(first != NULL && n > 0) {
        first = first->next;
        n--;
    }
    
    if(first == NULL) return -1;
    
    while(first->next != NULL && second != NULL){
        first = first->next;
        second = second->next;
    }
    
    return second->data;
}

int main()
{
  int i,n,l,k;

  struct Node *head = NULL,  *tail = NULL;

  cin>>n>>k;
  int firstdata;
  cin>>firstdata;
  head = new Node(firstdata);
  tail = head;
  for(i=1;i<n;i++)
  {
    cin>>l;
    tail->next = new Node(l);
    tail = tail->next;
  }

  cout<<getNthFromLast(head, k)<<endl;
    return 0;
}