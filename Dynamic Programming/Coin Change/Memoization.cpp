class Solution {
private:
    long long int count(int i, int value, int n, int arr[],
    vector<vector<long long int>> &dp) {
        if(value == 0) return 1;
        if(i == n) {
            if(value == 0) return 1;
            else return 0;
        }
        if(dp[i][value] != -1) return dp[i][value];
        long long int include = 0;
        if(value-arr[i] >= 0) include = count(i, value-arr[i], n, arr, dp);
        long long int exclude = count(i+1, value, n, arr, dp);
        return dp[i][value] = include+exclude;
    }

public:
    long long int count(int coins[], int n, int sum) {
        // code here.
        vector<vector<long long int>> dp(n, vector<long long int> (sum+1, -1));
        return count(0, sum, n, coins, dp);
    }
};