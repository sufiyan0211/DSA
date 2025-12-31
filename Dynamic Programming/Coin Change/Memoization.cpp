class Solution {
  public:
    int count(int i, int target, vector<int>& a, vector<vector<int>> &dp) {
        
        if (i == 0) {
            return (target % a[0] == 0);
        }
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int notPick = count(i-1, target, a, dp);
        int pick = 0;
        if(target-a[i] >= 0) pick = count(i, target-a[i], a, dp);
        
        return dp[i][target] = pick+notPick;
    }
    
    
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        
        return count(n-1, sum, coins, dp);
    }
};
