class Solution {
private: 
    void backtrack(int currIdx, int currSum,  int &target,
        vector<int> vi, vector<vector<int>> &ans,
        vector<int> &nums) {
            
        if(currIdx == nums.size()) {
            if(currSum == target) {
                ans.push_back(vi);
            }
            return;
        }

        if(nums[currIdx]+currSum <= target) {
            vi.push_back(nums[currIdx]);
            backtrack(currIdx, currSum+nums[currIdx], target, vi, ans, nums);
            vi.pop_back();
        }
        
        backtrack(currIdx+1, currSum, target, vi, ans, nums);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> vi;
        vector<vector<int>> ans;

        backtrack(0, 0, target, vi, ans, candidates);
        return ans;
    }
};