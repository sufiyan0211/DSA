#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));

    if(weight[n-1] <= maxWeight) dp[n-1][weight[n-1]] = 1;

    for(int i=n-1;i>=0;i--) {
        for(int w=0; w<=maxWeight; w++) {
            if(i == n-1) {
                if(weight[n-1] <= w) dp[i][w] = value[n-1];
                continue;
            }

            // include
            int include = 0;
            if(w-weight[i] >= 0)
                include = value[i] + dp[i+1][w-weight[i]];

            // Not include weight[i]
            int exclude = dp[i+1][w];
            dp[i][w] = max(include, exclude);
        }
    }
    return dp[0][maxWeight];
}
