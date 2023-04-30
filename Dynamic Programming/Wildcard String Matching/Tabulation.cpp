class Solution {
public:
    bool isMatch(string &pattern, string &wild) {
        int n1 = wild.size();
        int n2 = pattern.size();
        vector<vector<bool>> dp(n1+1, vector<bool> (n2+1, false));
        dp[0][0] = true;

        for(int i=1; i<=n1; i++) {
            if(wild[i-1] == '*') dp[i][0] = true;
            else break;
        }

        for(int i=1; i<=n1; i++) {
            for(int j=1; j<=n2; j++) {
                if(wild[i-1] == pattern[j-1] || wild[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(wild[i-1] == '*') {
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n1][n2];
    }
};