#include <bits/stdc++.h> 
long long int solve(vector<int> &nums, int n) 
{
    long long int prevOfPrev  = 0;
    long long int prev = nums[0];

    for(int i=1; i<n; i++) {
        long long int firstCall = nums[i];
        if(i > 1)
            firstCall += prevOfPrev;

        long long int secondCall = prev;

        long long int curr = max(firstCall, secondCall);

        prevOfPrev = prev;
        prev = curr;
    }
    return prev;
}
long long int houseRobber(vector<int>& nums)
{
    // Write your code here.
    
    vector<int> temp1, temp2;
    int n = nums.size();

    if(n==1) return nums[0];
    for(int i=0;i<n;i++) {
        if(i!=0) temp1.push_back(nums[i]);
        if(i!=n-1) temp2.push_back(nums[i]);
    }

    return max(solve(temp1, n-1), solve(temp2, n-1));
}