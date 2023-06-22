class Solution {
public:
    int longestCommonSubstr(string S1, string S2, int n, int m) {
        // your code here
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (S1[i - 1] == S2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};