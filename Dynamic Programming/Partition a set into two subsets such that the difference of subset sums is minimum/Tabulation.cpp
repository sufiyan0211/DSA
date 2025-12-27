class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += arr[i];
        }
        
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        
        // Base case: sum 0 is always achievable
        for(int i=0; i<n; i++) {
            dp[i][0] = true;
        }
        
        // Base case: at last index, can achieve arr[n-1] by picking it
        dp[n-1][arr[n-1]] = true;
        
        // Fill DP table
        for(int i=n-2; i>=0; i--) {
            for(int s=1; s<=sum; s++) {
                bool notPick = dp[i+1][s];
                bool pick = false;
                if(s >= arr[i]) pick = dp[i+1][s-arr[i]];
                dp[i][s] = notPick || pick;
            }
        }
        
        // Find minimum difference
        int ans = 1e9;
        for(int s=0; s<=sum/2; s++) {
            if(dp[0][s]) ans = min(ans, abs(s - (sum - s))); 
        }
        
        return ans;
    }
};
