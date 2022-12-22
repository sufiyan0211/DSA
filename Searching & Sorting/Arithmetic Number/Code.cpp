#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int inSequence(int A, int B, int C){
        if(C==0) {
            if(B==A) return 1;
        }
        else if(C!=0 && (B-A)%C == 0) {
            int n = ((B-A)/C)+1;
            return n>0 ? 1 : 0;
        }
        return 0;
    }
};


int main(){
    int A, B, C;
    cin>>A>>B>>C;
    
    Solution ob;
    cout<<ob.inSequence(A, B, C)<<endl;
    return 0;
}
