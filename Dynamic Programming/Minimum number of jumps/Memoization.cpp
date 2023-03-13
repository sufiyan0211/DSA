class Solution{
private:
    int solve(int i, int n, int arr[], vector<int> &dp) {
        if(i == n-1) return 0;
        if(arr[i] == 0) return 1e8;
        int ans = 1e8;
        if(dp[i] != -1) return dp[i];
        for(int ind = i+1; ind <= min(n-1, i+arr[i]); ind++) {
            int call = solve(ind, n, arr, dp);
            ans = min(ans, 1+call);
        }
        return dp[i] = ans;
    }
    
    
public:
    int minJumps(int arr[], int n) {
        // Your code here
        if(arr[0] == 0) return -1;
        vector<int> dp(n, -1);
        int ans = solve(0, n, arr, dp);
        return ans >= 1e8 ? -1 : ans;
    }
};