class Solution {
    int m = 1000000007;
  public:
    long long int nthFibonacci(long long int n){
        // code here
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        
        for(long long int i=2;i<=n;i++) {
            dp[i] = (dp[i-1]%m + dp[i-2]%m)%m;
        }
        return dp[n];
    }
};