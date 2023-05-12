class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;

            for(int j=i+1; j<n; j++) {
                if(j>i+1 && nums[j-1] == nums[j]) continue;

                long long newTarget = (long long)target - (nums[i] + nums[j]);

                int start = j+1, end = n-1;
                while(start < end) {
                    if(start > j+1 && nums[start-1] == nums[start]) {
                        start++;
                        continue;
                    }
                    if(end < n-1 && nums[end+1] == nums[end]) {
                        end--;
                        continue;
                    }
                    if(start >= end) break;
                    long long sum = nums[start] + nums[end];
                    if(sum == newTarget) {
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                    }
                    else if(sum < newTarget) {
                        start++;
                    }
                    else {
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};