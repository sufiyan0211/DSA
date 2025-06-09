#include <bits/stdc++.h>
using namespace std;

// Node Structure
class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

// Stack strcutre
class myStack {
    Node *head;
    Node *mid;
    int size;

public:
    myStack() {
        size = 0;
        head = nullptr;
        mid = nullptr;
    }

    void push(int data) {
        Node *temp = new Node(data);
        if (size == 0) {
            head = temp;
            mid = temp;
            size++;
            return;
        }

        temp->next = head;
        head->prev = temp;
        head = temp;
        size++;

        if(size%2 == 0) {
            mid = mid->prev; // move left
        }
    }

    int pop() {
        // can't perform pop 
        if(size == 0) {
            return -1;
        }

        int data = head->data;

        if(size == 1) {
            head = nullptr;
            mid = nullptr;
            return data;
        }

        head = head->next;
        head->next = nullptr;
        size--;

        if(size%2 == 1) {
            mid = mid->next; // move right
        }

        return data;
    }

    int findMiddle() {
        if (size == 0) {
            return -1;
        }
        return mid->data;
    }

    void deleteMiddle() {
        // can't perform pop 
        if(size == 0) {
            return;
        }

        if(size == 1) {
            head = nullptr;
            mid = nullptr;
            return;
        }

        Node* previousOfMid = mid->prev;
        Node* nextOfMid = mid->next;

        previousOfMid->next = nextOfMid;
        nextOfMid->prev = previousOfMid;
        size--;

        if(size%2 == 0) {
            mid = previousOfMid;
        }
        else{
            mid = nextOfMid;
        }

    }
};

int main() {
    myStack st;
    st.push(1);
    st.push(2);
    cout << st.findMiddle() << endl;
    
    st.push(3);
    cout << st.findMiddle() << endl;
    
    st.push(4);
    cout << st.findMiddle() << endl;


    st.deleteMiddle();
    cout << st.findMiddle() << endl;


    cout << st.pop() << endl;

    return 0;
}