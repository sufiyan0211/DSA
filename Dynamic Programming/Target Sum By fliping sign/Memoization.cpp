class Solution {
public:
    int findTargetSumWays(int i, int target, vector<int>& a, vector<vector<int>> &dp) {

        if(i == 0) {
            if(target == 0 && a[0] == 0) return 2;
            if(target == 0 || a[0] == target) return 1;
            return 0;
        }

        if(dp[i][target] != -1) return dp[i][target];

        int notPick = findTargetSumWays(i-1, target, a, dp);

        int pick = 0;
        if(target-a[i] >= 0) pick = findTargetSumWays(i-1, target-a[i], a, dp);

        return dp[i][target] = pick+notPick;
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        for(auto x: nums) sum += x;

        if(sum < abs(target) || (sum+target)%2 != 0) return 0;

        int s1 = (sum+target) / 2;

        vector<vector<int>> dp(n, vector<int> (s1+1, -1));

        return findTargetSumWays(n-1, s1, nums, dp);
    }
};
