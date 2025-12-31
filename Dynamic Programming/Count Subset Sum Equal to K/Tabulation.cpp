class Solution {
  public:
    
    int perfectSum(vector<int>& a, int target) {
        // code here
        int n = a.size();
        
        vector<vector<int>> dp(n, vector<int> (target+1, 0));
        
        if (a[0] == 0) {
            dp[0][0] = 2;   // pick and notPick both gives 1
        } else {
            dp[0][0] = 1;  
            if (a[0] <= target)
                dp[0][a[0]] = 1;
        }
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<=target; j++) {
                int notPick = dp[i-1][j];
                
                int pick = 0;
                if(j-a[i] >=0 ) pick = dp[i-1][j-a[i]];
                
                dp[i][j] = pick+notPick;
            }
        }
        
        return dp[n-1][target];
    }
};