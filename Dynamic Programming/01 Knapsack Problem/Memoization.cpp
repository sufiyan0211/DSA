#include <bits/stdc++.h>

int val(int i, int w, int n, vector<int> &value,
        vector<int> &weight,
        vector<vector<int>> &dp) {

    if(w == 0) return 0;
    if(i == n-1) {
        if(weight[n-1] <= w) return value[n-1];
        else return 0;
    }
    if(dp[i][w] != -1) return dp[i][w];
    // include weight[i]
    int include = 0;
    if(w-weight[i] >= 0)
        include = value[i] + val(i+1, w-weight[i], n, value, weight, dp);

    // Not include weight[i]
    int exclude = val(i+1, w, n, value, weight, dp);

    return dp[i][w] = max(include, exclude);
}


int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
    return val(0, maxWeight, n, value, weight, dp);
}