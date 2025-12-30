class Solution {
  public:
    
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int> (w+1, 0));
        vector<int> prev(w+1, 0), next(w+1, 0);
        
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
                int notPick = prev[j];
        
                int pick = 0;
                if(j-wt[i] >= 0) pick = val[i] + prev[j-wt[i]];
                
                next[j] = max(pick, notPick);
            }
            prev = next;
        }
      
        return prev[w];
    }
};
