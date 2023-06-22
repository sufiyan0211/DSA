class Solution {
public:
    int grouping(int ind, int sum, string str, vector <vector<int>> &dp) {
        if (ind == str.size()) return 1;
        if (dp[ind][sum] != -1) return dp[ind][sum];
        int currSum = 0;
        int ans = 0;
        for (int i = ind; i < str.size(); i++) {
            currSum += (str[i] - '0');
            if (currSum >= sum) {
                ans += grouping(i + 1, currSum, str, dp);
            }
        }
        return dp[ind][sum] = ans;
    }

    int TotalCount(string str) {
        // Code here
        int n = str.size();
        vector <vector<int>> dp(n, vector<int>(9 * n, -1));
        return grouping(0, 0, str, dp);
    }
};