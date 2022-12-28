#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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



class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node *merge(Node *first, Node *second) {
        if(first == NULL) return second;
        if(second == NULL) return first;
        
        Node *head = NULL, *tail = NULL;
        
        while(first != NULL && second != NULL) {
            if(first->data <= second->data) {
                if(head == NULL) {
                    head = tail = first;
                    first = first->next;
                }
                else {
                    tail->next = first;
                    first = first->next;
                    tail = tail->next;
                }
            }
            else {
                if(head == NULL) {
                    head = tail = second;
                    second = second->next;
                }
                else {
                    tail->next = second;
                    second = second->next;
                    tail = tail->next;
                }
            }
        }
        
        if(first == NULL) {
            tail->next = second;
        }
        else if(second == NULL) {
            tail->next = first;
        }
        
        return head;
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        if(head == NULL || head->next == NULL) return head;
        
        Node *slow = head, *fast=head, *prevSlow;
        
        while(fast != NULL && fast->next != NULL) {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prevSlow->next = NULL;
        
        head = mergeSort(head);
        slow = mergeSort(slow);
        
        return merge(head, slow);
    }
};



void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct Node* a = NULL;
    long n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        push(&a, tmp);
    }
    Solution obj;
    a = obj.mergeSort(a);
    printList(a);
    
    return 0;
}