#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(int i, int n, int k,
           vector<int> &arr,
           vector<vector<int>> &dp) {

    if(i >= n) return false;
    if(k == 0) return true;
    if(k < 0) return false;

    if(i == n-1) {
        if(k-arr[i] == 0) return true;
        else return false;
    }

    if(dp[i][k] != -1) return dp[i][k];

    bool pick = solve(i+1, n, k-arr[i], arr, dp);
    bool notPick = solve(i+1, n, k, arr, dp);

    return dp[i][k] = (pick || notPick);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int> (k+1, -1));
    return solve(0, n, k, arr, dp);
}