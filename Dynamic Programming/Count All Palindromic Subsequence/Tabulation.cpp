class Solution {
public:
    int mod = 1e9 + 7;

/*
    long long int helper(int i, int j, string str, vector <vector<int>> &dp) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        if (str[i - 1] == str[j - 1])
            return dp[i][j] = (1 + helper(i, j - 1, str, dp) + helper(i + 1, j, str, dp)) % mod;
        return dp[i][j] = (helper(i, j - 1, str, dp) + helper(i + 1, j, str, dp) - helper(i + 1, j - 1, str, dp)) % mod;
    }
*/
    long long int countPS(string str) {
        //Your code here
        int n = str.size();
        vector <vector<long long int>> dp(n + 1, vector<long long int>(n + 1, 0));
        for (int i = 0; i < n + 1; i++) dp[i][i] = 1;

        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j <= n; j++) {
                if (str[i - 1] == str[j - 1]) dp[i][j] = (1l + dp[i][j - 1] + dp[i + 1][j]) % mod;
                else dp[i][j] = (mod + dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]) % mod;
            }
        }

        return dp[1][n];
    }

};