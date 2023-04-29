class Solution {
private:
    int recursion(int i, int j, string str1, string str2, vector<vector<int>> &dp) {
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(str1[i] == str2[j]) {
            return dp[i][j] = recursion(i-1, j-1, str1, str2, dp) +
                              recursion(i-1, j, str1, str2, dp);
        }
        return dp[i][j] = recursion(i-1, j, str1, str2, dp);
    }


public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return recursion(n1-1, n2-1, s, t, dp);
    }
};