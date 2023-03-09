#include <bits/stdc++.h> 
int solve(int i, vector<int> &nums, int n,vector<int> &dp) 
{
    if(i >= n) return 0;
    if(i == n-1) return nums[n-1];

    if(dp[i] != -1) return dp[i];
    
    int firstCall = solve(i+2, nums, n, dp) + nums[i];
    int secondCall = solve(i+1, nums, n, dp);

    return dp[i] = max(firstCall, secondCall); 
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp(nums.size()+2, -1);
    return solve(0, nums, nums.size(), dp);
}