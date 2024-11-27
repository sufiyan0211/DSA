class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        dp[n][0] = dp[n][1] = 0;
        for(int i=n-1; i>=0; i--) {
            for(int buy = 0; buy <=1; buy++) {
                int profit = 0;
                if(buy) {
                    profit = max(
                            -prices[i] + dp[i+1][0], // selling at ind th day
                            0 + dp[i+1][1] // not selling at ind th day
                    );
                }
                else {
                    profit = max(
                            prices[i] + dp[i+1][1], // buying at ind th day
                            0 + dp[i+1][0] // not buying at ind th day
                    );
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};