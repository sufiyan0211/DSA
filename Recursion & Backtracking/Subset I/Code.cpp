class Solution {
private:
    void backtrack(int currIdx, vector<int> &vi, 
    vector<vector<int>> &ans, vector<int> &nums) {
        ans.push_back(vi);
        for(int i=currIdx;i<nums.size();i++) {
            if(i>currIdx && nums[i] == nums[i-1]) continue;
            vi.push_back(nums[i]);
            backtrack(i+1, vi, ans, nums);
            vi.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vi;
        sort(nums.begin(), nums.end());
        backtrack(0, vi, ans, nums);
        return ans;
    }
};