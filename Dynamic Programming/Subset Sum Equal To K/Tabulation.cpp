class Solution {
  public:
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        
        vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
        
        for(int i=0; i<n; i++) {
            dp[i][0] = true;
        }
    
        dp[n-1][arr[n-1]] = true;

        
        // Fill bottom-up
        for(int i = n - 2; i >= 0; i--) {
            for(int s = 1; s <= sum; s++) {
                bool notPick = dp[i + 1][s];
                bool pick = false;
                if(s - arr[i] >= 0) {
                    pick = dp[i + 1][s - arr[i]];
                }
                dp[i][s] = pick || notPick;
            }
        }

        return dp[0][sum];
    }
};
