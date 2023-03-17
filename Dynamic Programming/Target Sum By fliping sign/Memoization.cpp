#include <iostream>
#include <vector>
using namespace std;

int count(int i, int target, int n, vector<int>& arr,
          vector<vector<int>> &dp) {
    if(i == n) {
        if(target == 0) return 1;
        else return 0;
    }
    if(dp[i][target] != -1) return dp[i][target];
    int include = 0;
    if(target-arr[i] >= 0) include = count(i+1, target-arr[i], n, arr, dp);
    int exclude = count(i+1, target, n, arr, dp);
    return dp[i][target] = include+exclude;
}

int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    int sum = 0;
    for(auto it : arr) sum += it;
    if(sum-target < 0 || (sum-target)%2 != 0) return false;
    int t = ((sum-target)/2)+1;
    vector<vector<int>> dp(n, vector<int> (t, -1));
    return count(0, (sum-target)/2, n, arr, dp);
}
