#include <iostream>
#include <vector>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
    // Write your code here.
    int totalSum = 0;
    for(int i=0;i<n;i++) {
        totalSum += arr[i];
    }

    int k = totalSum;
    vector<vector<bool>> dp(n, vector<bool> (k+1, false));
    for(int i=0;i<n;i++) {
        dp[i][0] = true;
    }
    if(arr[n-1] <= k)
        dp[n-1][arr[n-1]] = true;

    for(int i=n-2; i>=0; i--) {
        for(int target=1; target<=k; target++) {
            bool pick = false;
            if(target-arr[i] >= 0) {
                pick = dp[i+1][target-arr[i]];
            }
            bool notPick = dp[i+1][target];
            dp[i][target] = (pick || notPick);
        }
    }

    int mini = 1e9;
    for(int s1=0; s1<=totalSum/2; s1++) {
        if(dp[0][s1] == true)
            mini = min(mini, abs(totalSum-s1-s1));
    }
    return mini;
}
