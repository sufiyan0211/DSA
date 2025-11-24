class Solution {
public:
void subsets(int currentIndex, vector<int>& nums,
                 vector<int> path, vector<vector<int>> &ans) {
        
        ans.push_back(path);

        for(int i = currentIndex; i<nums.size(); i++) {
            // to avoid duplicates in the ans
            if (i>currentIndex && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            subsets(i+1, nums, path, ans);
            path.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        subsets(0, nums, path, ans);
        return ans;
    }
};
