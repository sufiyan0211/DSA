#include <iostream>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

class MyStack {
private:
    stack<int> st;
    deque<int> dq;
public:

    void add(int value) {
        dq.push_back(value);
        if(dq.size() > st.size()+1) {
            int topEle = dq.front();
            dq.pop_front();
            st.push(topEle);
        }
    }

    void deleteLast() {
        if(dq.empty()) {
            cout << "MyStack is already empty, so Can't be deleted any more element from MyStack\n";
            return;
        }
        dq.pop_back();
        if(dq.size() < st.size()) {
            int lastEle = st.top();
            st.pop();
            dq.push_front(lastEle);
        }
    }

    int findMiddleElement() {
        int middleElement = dq.front();
        return middleElement;
    }

    void deleteMiddleElement() {
        if(dq.empty()) {
            cout << "MyStack is Empty, so no elements to be deleted.\n";
            return;
        }
        dq.pop_front();
        if(dq.size() < st.size()) {
            int lastEle = st.top();
            st.pop();
            dq.push_front(lastEle);
        }
    }

    int topElement() {
        if(dq.empty()) {
            cout << "MyStack is empty. So no top element to be return.\n";
            return -1;
        }
        return dq.back();
    }
};


int main() {
    MyStack myStack;
    myStack.add(10);
    myStack.add(20);
    myStack.add(30);

    cout << myStack.findMiddleElement() << endl;

    return 0;
}

