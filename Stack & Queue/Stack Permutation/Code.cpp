#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int isStackPermutation(int n,vector<int> &arr1,vector<int> &arr2){
        stack<int> s;
        int j = 0;
        for(int i=0;i<n;i++) {
            s.push(arr1[i]);
            while(!s.empty() && s.top() == arr2[j]) {
                s.pop();
                j++;
            }
        }
        if(!s.empty() || j != n) {
            return false;
        }
        return true;
    }
};


int main() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    Solution ob;
    cout<<ob.isStackPermutation(n,a,b)<<endl;
    
    return 0;
}