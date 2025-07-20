#include <bits/stdc++.h>
using namespace std;



template<typename T>
class Stack {
private:
    queue<T> q1;
    queue<T> q2;


public:
    Queue() {
    }

    ~Queue() {
        q1 = NULL;
        q2 = NULL;
    }

    void push(T item) {
        //Enqueue x to q2
        q2.push(item);

        //One by one dequeue everything from q1 and enqueue to q2.
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        //Swap the names of q1 and q2
        swap(q1, q2);
    }

    T pop() {
        if(isEmpty()) {
            throw underflow_error("Stack is already empty");
        }
        T item = q1.front();
        q1.pop();

        return item;
    }

    bool isEmpty() {
        return q1.empty();
    }

    T top() {
        if(isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return front->data;
    }

};

int main() {
    Stack<int> st;

    st.push(11);
    st.push(12);
    st.push(13);
    st.push(14);
    st.push(15);

    st.pop();

    cout << q.top() << endl;


    return 0;
}