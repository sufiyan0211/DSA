class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        for(auto x: nums) sum += x;

        if(sum < abs(target) || (sum+target)%2 != 0) return 0;

        int s1 = (sum+target) / 2;

        vector<vector<int>> dp(n, vector<int> (s1+1, 0));

        if(nums[0] == 0) {
            dp[0][0] = 2;
        }
        else {
            dp[0][0] = 1;
            if(nums[0] <= s1) dp[0][nums[0]] = 1;
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<=s1; j++) {
                int notPick = dp[i-1][j];

                int pick = 0;
                if(j-nums[i] >= 0) pick = dp[i-1][j-nums[i]];

                dp[i][j] = pick+notPick;
            }
        }

        return dp[n-1][s1];
    }
};
