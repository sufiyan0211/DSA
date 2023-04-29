class Solution {
private:
    int editDistance(int i, int j, string str1, string str2, vector<vector<int>> &dp) {
        if(i < 0) return j+1;
        if(j < 0) return i+1;

        if(dp[i][j] != -1) return dp[i][j];

        if(str1[i] == str2[j]) {
            return dp[i][j] = editDistance(i-1, j-1, str1, str2, dp);
        }
        return dp[i][j] = 1 + min(
                editDistance(i, j-1, str1, str2, dp), // insert
                min(
                        editDistance(i-1, j, str1, str2, dp),  // delete
                        editDistance(i-1, j-1, str1, str2, dp)  // replace
                )
        );
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return editDistance(n1-1, n2-1, word1, word2, dp);
    }
};