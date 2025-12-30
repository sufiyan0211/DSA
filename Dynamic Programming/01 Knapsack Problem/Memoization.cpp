class Solution {
  public:
    
    int knapsack(int index, int w, int n, vector<int> &val, vector<int> &wt,
                vector<vector<int>> &dp) {
        
        if(index == n || w == 0) {
            return 0;
        }
        
        if(dp[index][w] != -1) return dp[index][w];
        
        int notPick = knapsack(index+1, w, n, val, wt, dp);
        
        int pick = 0;
        if(w-wt[index] >= 0) pick = val[index] + knapsack(index+1, w-wt[index], n, val, wt, dp);
        
        return dp[index][w] = max(pick, notPick);
    }
    
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        
        int n = val.size();
        
        vector<vector<int>> dp(n+1, vector<int> (w+1, -1));
        
        return knapsack(0, w, n, val, wt, dp);
    }
};
