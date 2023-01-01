#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaxLen(string str) {
        // code here

        /*
        Stack 's'will store the index of opening brackets
        Stack will be initialized with -1
        when closing bracket is encounter then do one pop from the stack
        after poping
        if the stack is empty then store the index of current closing bracket
        else (when stack is not empty after poping operation then)
            len = max(len, (i-st.top()));
        */
        int n = str.size();
        stack<int> s; 
        s.push(-1);
        int len = 0;
        
        for(int i=0;i<n;i++) {
            if(str[i] == '(') {
                s.push(i);
            }
            else {
                s.pop();
                if(s.empty()) {
                    s.push(i);
                }
                else {
                    int curr = i-s.top();
                    len = max(len, curr);
                }
            }
        }
        return len;
    }
};

int main() {
    
    string S;
    cin >> S; 
    Solution ob;
    cout << ob.findMaxLen(S) << endl;
    
    return 0;
}

