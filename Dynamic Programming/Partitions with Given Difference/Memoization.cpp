class Solution {
  public:
    int countPartitions(int i, int target, vector<int>& a, vector<vector<int>> &dp) {
        if (i == 0) {
            if (target == 0 && a[0] == 0) return 2;
            if (target == 0 || a[0] == target) return 1;
            return 0;
        }
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int notPick = countPartitions(i-1, target, a, dp);
        
        int pick = 0;
        if(target - a[i] >= 0) pick = countPartitions(i-1, target-a[i], a, dp);
        
        return dp[i][target] = pick+notPick;
    }
    
    int countPartitions(vector<int>& a, int diff) {
        // Code here
        int n = a.size();
        
        int sum = 0;
        for(auto x: a) sum += x;
        
        if (diff > sum || (sum + diff) % 2 != 0)
            return 0;
        
        int s1 = (diff + sum) / 2; 
        
        vector<vector<int>> dp(n, vector<int> (s1+1, -1));
        
        return countPartitions(n-1, s1, a, dp);
    }
};