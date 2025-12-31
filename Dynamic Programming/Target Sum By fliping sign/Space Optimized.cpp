class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        for(auto x: nums) sum += x;

        if(sum < abs(target) || (sum+target)%2 != 0) return 0;

        int s1 = (sum+target) / 2;

        vector<int> prev(s1+1, 0), next(s1+1, 0);

        if(nums[0] == 0) {
            prev[0] = 2;
        }
        else {
            prev[0] = 1;
            if(nums[0] <= s1) prev[nums[0]] = 1;
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<=s1; j++) {
                int notPick = prev[j];

                int pick = 0;
                if(j-nums[i] >= 0) pick = prev[j-nums[i]];

                next[j] = pick+notPick;
            }
            prev = next;
        }

        return prev[s1];
    }
};
