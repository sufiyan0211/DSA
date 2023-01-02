#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    QueueStack *qs = new QueueStack();

    int Q;
    cin>>Q;
    while(Q--){
        int QueryType=0;
        cin>>QueryType;
        // QueryType = 1 means push operation
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }
        // QueryType = 2 means pop operation
        else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
    }
    cout<<endl;
}


//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
    // Your Code
    while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    
    q1.push(x);
    
    while(!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    // Your Code      
    if(q1.empty() == true) return -1;
    int x = q1.front();
    q1.pop();
    return x;
}




/*
i/p:
    5
    1 2 1 3 2 1 4 2
o/p:
     3 4
*/