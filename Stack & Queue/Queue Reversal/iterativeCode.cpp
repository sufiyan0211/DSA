#include<bits/stdc++.h>
using namespace std;




queue<int> rev(queue<int> q)
{
    // add code here.
    stack <int> s;
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
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

