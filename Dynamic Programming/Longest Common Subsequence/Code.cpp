#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp) {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) {
            return dp[i][j] = 1+solve(i-1, j-1, s1, s2, dp);
        }

        return dp[i][j] = max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));
    }
public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(x, vector<int> (y, -1));
        return solve(x-1, y-1, s1, s2, dp);
    }
};