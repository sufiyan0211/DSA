#include <bits/stdc++.h>
using namespace std;


queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> s;
    
    for(int i=0;i<k;i++) {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    
    int count = q.size() - k;
    
    while(count--) {
        int f = q.front();
        q.pop();
        q.push(f);
    }
    return q;
}


int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    while (n-- > 0) {
        int a;
        cin >> a;
        q.push(a);
    }
    queue<int> ans = modifyQueue(q, k);
    while (!ans.empty()) {
        int a = ans.front();
        ans.pop();
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
