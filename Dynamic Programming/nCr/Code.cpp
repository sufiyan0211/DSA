
#include <iostream>
#include <vector>
using namespace std;

int nCr(int n, int r){
    // code here
    if(n < 0 || n < r) return 0;

    if((n-r) < r) r = n-r;

    vector<int> dp(r+1, 0);
    dp[0] = 1;
    int mod = 1e9 + 7;

    for(int i=1;i<=n;i++) {
        for(int j=r; j>=1; j--) {
            dp[j] = (dp[j-1] + dp[j])%mod;
        }
    }

    return dp[r];
}