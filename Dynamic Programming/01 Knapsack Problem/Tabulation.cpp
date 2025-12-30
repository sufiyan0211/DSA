class Solution {
  public:
    
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        
        int n = val.size();
        
        vector<vector<int>> dp(n+1, vector<int> (w+1, 0));
        
        // // w == 0
        // for(int i=0; i<=n; i++) {
        //     dp[i][0] = 0;
        // }
        
        // // index == n
        // for(int i=0; i<=w; i++) {
        //     dp[n][i] = 0;
        // }
        
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<= w; j++) {
                int notPick = dp[i+1][j];
        
                int pick = 0;
                if(j-wt[i] >= 0) pick = val[i] + dp[i+1][j-wt[i]];
                
                dp[i][j] = max(pick, notPick);
            }
        }
        
        
        return dp[0][w];
    }
};
