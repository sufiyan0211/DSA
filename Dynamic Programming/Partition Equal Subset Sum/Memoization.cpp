class Solution{
private:
    int solve(int i, int sum, int n, int arr[],
              vector<vector<int>> &dp) {

        if(i >= n) return false;
        if(sum < 0) return false;
        if(sum-arr[i] == 0) return true;

        if(dp[i][sum] != -1) return dp[i][sum];

        int pick = solve(i+1, sum-arr[i], n, arr, dp);
        int notPick = solve(i+1, sum, n, arr, dp);

        return dp[i][sum] = (pick || notPick);
    }

public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<n;i++) sum += arr[i];

        if(sum%2 != 0) return 0;
        sum /= 2;

        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return solve(0, sum, n, arr, dp);
    }
};