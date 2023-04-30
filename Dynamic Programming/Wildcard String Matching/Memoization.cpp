class Solution {
private:
    bool superMatch(int i, int j, string &wild, string &pattern, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return true;
        if(i == 0 && j >= 1) return false;

        if(j == 0 && i >= 1) {
            for(int it=0; it<i; it++) { // int it=0; it<i; it++
                if(wild[it] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(wild[i-1] == pattern[j-1] || wild[i-1] == '?') {
            return dp[i][j] = superMatch(i-1, j-1, wild, pattern, dp);
        }
        if(wild[i-1] == '*') {
            return dp[i][j] = (
                    superMatch(i-1, j, wild, pattern, dp) ||  // matches with non
                    superMatch(i, j-1, wild, pattern, dp)
            );
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string &pattern, string &wild) {
        int n1 = wild.size();
        int n2 = pattern.size();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));
        return superMatch(n1, n2, wild, pattern, dp);
    }
};