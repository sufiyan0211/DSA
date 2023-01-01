#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaxLen(string str) {
        // code here

        int n = str.size();
        int open = 0, close = 0;
        int mx = 0;
        for(int i = 0;i<n;i++) {
            if(str[i] == '(') open++;
            else if(str[i] == ')') close++;
            
            if(open == close) {
                mx = max(mx, open+close);
            }
            else if(close > open) {
                open = close = 0;
            }
        }
        
        open = 0; close = 0;
        for(int i=n-1;i>=0;i--) {
            if(str[i] == '(') open++;
            else if(str[i] == ')') close++;
            
            if(open == close) {
                mx = max(mx, open+close);
            }
            else if(open > close) {
                open = close = 0;
            }
        }
        return mx;
    }
};

int main() {
    
    string S;
    cin >> S; 
    Solution ob;
    cout << ob.findMaxLen(S) << endl;
    
    return 0;
}

