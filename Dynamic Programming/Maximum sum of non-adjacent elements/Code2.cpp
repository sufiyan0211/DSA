#include <bits/stdc++.h> 
int solve(vector<int> &nums, int n, vector<int> &dp) 
{
    int negative  = 0;
    dp[0] = nums[0];

    for(int i=1; i<n; i++) {
        int firstCall = nums[i];
        if(i > 1)
            firstCall += dp[i-2];

        int secondCall = dp[i-1];

        dp[i] = max(firstCall, secondCall);
    }
    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp(nums.size()+2, -1);
    return solve(nums, nums.size(), dp);
}