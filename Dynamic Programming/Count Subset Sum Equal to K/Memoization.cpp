class Solution {
  public:
    int perfectSum(int i, int target, vector<int> &a, vector<vector<int>> &dp) {
        
        if(i == 0) {
            if(target == 0 && a[0] == 0) return 2;
            if(target == 0|| a[0] == target) return 1;
            return 0;
        }
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int notPick = perfectSum(i-1, target, a, dp);
        
        int pick = 0;
        if(target-a[i] >=0 ) pick = perfectSum(i-1, target-a[i], a, dp);
        
        return dp[i][target] = pick+notPick;
    }
    
    int perfectSum(vector<int>& a, int target) {
        // code here
        int n = a.size();
        
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        
        return perfectSum(n-1, target, a, dp);
    }
};