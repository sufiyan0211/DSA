class Solution {
public:
    int lcs(int i, int j, string str1, string str2, vector <vector<int>> &dp) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (str1[i] == str2[j]) {
            return dp[i][j] = 1 + lcs(i - 1, j - 1, str1, str2, dp);
        }
        return dp[i][j] = max(lcs(i - 1, j, str1, str2, dp), lcs(i, j - 1, str1, str2, dp));
    }

    int longestPalinSubseq(string str1) {
        //code here
        int n = str1.size();
        string str2 = str1;
        reverse(str2.begin(), str2.end());
        vector <vector<int>> dp(n, vector<int>(n, -1));
        return lcs(n - 1, n - 1, str1, str2, dp);
    }
};