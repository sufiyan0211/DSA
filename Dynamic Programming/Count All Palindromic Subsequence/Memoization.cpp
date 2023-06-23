class Solution {
public:
    long long int helper(int i, int j, string str, vector <vector<long long int>> &dp) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        int mod = 1e9 + 7;

        if (str[i] == str[j]) return dp[i][j] = (1 + helper(i, j - 1, str, dp) + helper(i + 1, j, str, dp)) % mod;
        return dp[i][j] =
                       (mod + helper(i, j - 1, str, dp) + helper(i + 1, j, str, dp) - helper(i + 1, j - 1, str, dp)) %
                       mod;
    }

    long long int countPS(string str) {
        //Your code here
        int n = str.size();
        vector <vector<long long int>> dp(n, vector<long long int>(n, -1));
        return helper(0, n - 1, str, dp);
    }
};