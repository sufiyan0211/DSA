#include <bits/stdc++.h> 
int solve(vector<int> &nums, int n) 
{
    int prevOfPrev  = 0;
    int prev = nums[0];

    for(int i=1; i<n; i++) {
        int firstCall = nums[i];
        if(i > 1)
            firstCall += prevOfPrev;

        int secondCall = prev;

        int curr = max(firstCall, secondCall);

        prevOfPrev = prev;
        prev = curr;
    }
    return prev;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return solve(nums, nums.size());
}