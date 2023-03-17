#include <iostream>
#include <vector>
using namespace std;


int solve(int i, int n, int x, vector<int> &nums,
          vector<vector<int>> &dp) {

    if(x == 0) return 0;
    if(i == n) {
        if(x == 0) return 1;
        else return 1e9;
    }
    if(dp[i][x] != -1) return dp[i][x];
    // include
    int include = 1e9;
    if(x-nums[i] >= 0) {
        include = 1 + solve(i+1, n, x-nums[i], nums, dp);
    }
    int include2 = 1e9;
    if(x-nums[i] >= 0) {
        include2 = 1 + solve(i, n, x-nums[i], nums, dp);
    }
    // exclude
    int exclude = solve(i+1, n, x, nums, dp);

    return dp[i][x] = min({include, exclude, include2});
}

int minimumElements(vector<int> &nums, int x)
{
    // Write your code here.
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (x+1, -1));
    int ans = solve(0, n, x, nums, dp);
    return ans>=1e9 ? -1 : ans;
}







