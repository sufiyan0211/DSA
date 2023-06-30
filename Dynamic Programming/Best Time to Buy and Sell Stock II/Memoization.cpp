class Solution {
private:
    int cal(int ind, int buy, vector<int>& prices, vector<vector<int>> &dp) {
        if(ind == prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy) {
            // we don't have any share on hold so we can buy. But it's on upto us to buy or not buy on ind th day
            profit = max(
                    -prices[ind] + cal(ind+1, 0, prices, dp), // selling at ind th day
                    0 + cal(ind+1, 1, prices, dp) // not selling at ind th day
            );
        }
        else {
            // We already have one share now we have to sell it (So this ind th day we can sell it or not sell it)
            profit = max(
                    prices[ind] + cal(ind+1, 1, prices, dp),
                    0 + cal(ind+1, 0, prices, dp)
            );
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return cal(0, 1, prices, dp);
    }
};