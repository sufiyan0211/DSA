class Solution {
  public:
    
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        
        // sum = 0
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        
        // first coin
        for (int j = 0; j <= sum; j++) {
            if (j % coins[0] == 0)
                dp[0][j] = 1;
        }
        
        // fill dp table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= sum; j++) {
                
                int notPick = dp[i - 1][j];
                int pick = 0;
                
                if (j >= coins[i]) {
                    pick = dp[i][j - coins[i]];
                }
                
                dp[i][j] = pick + notPick;
            }
        }
        
        return dp[n - 1][sum];
    }
};
