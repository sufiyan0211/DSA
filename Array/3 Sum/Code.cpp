class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            int target = -1 * nums[i];
            if(i>0 && nums[i-1] == nums[i]) {
                continue;
            }
            int start = i+1, end = n-1;
            while(start < end) {
                int sum = nums[start] + nums[end];
                if(start > i+1 && nums[start-1] == nums[start]) {
                    start++;
                    continue;
                }
                if(end < n-1 && nums[end+1] == nums[end]) {
                    end--;
                    continue;
                }
                if(start >= end) break;
                if(sum == target) {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                }
                else if(sum < target) {
                    start++;
                }
                else {
                    end--;
                }
            }
        }
        return ans;
    }
};