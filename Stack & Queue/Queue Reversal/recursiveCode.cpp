#include<bits/stdc++.h>
using namespace std;


void reverseRecursively(queue<int> &q) {
    if(q.empty()) return;
    int temp = q.front();
    q.pop();
    reverseRecursively(q);
    q.push(temp);
}

queue<int> rev(queue<int> q)
{
    // add code here.
    reverseRecursively(q);
    return q;
}


int main()
{

    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    
}

