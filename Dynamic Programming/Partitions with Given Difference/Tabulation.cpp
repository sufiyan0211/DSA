class Solution {
  public:
    int countPartitions(vector<int>& a, int diff) {
        // Code here
        int n = a.size();
        
        int sum = 0;
        for(auto x: a) sum += x;
        
        if (diff > sum || (sum + diff) % 2 != 0)
            return 0;
        
        int s1 = (diff + sum) / 2; 
        
        vector<vector<int>> dp(n, vector<int> (s1+1, 0));
        
        
        if(a[0] == 0) {
            dp[0][0] = 2;
        }
        else {
            dp[0][0] = 1;
            if(a[0] <= s1) dp[0][a[0]] = 1;
        }
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<=s1; j++) {
                int notPick = dp[i-1][j];
                
                int pick = 0;
                if(j - a[i] >= 0) pick = dp[i-1][j-a[i]];
                
                dp[i][j] = pick+notPick;
            }
        }
        
        
        return dp[n-1][s1];
    }
};