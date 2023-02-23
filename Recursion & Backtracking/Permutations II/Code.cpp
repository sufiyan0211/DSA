class Solution {
private :
    void backtrack(int currIdx, vector<vector<int>> &ans,
    vector<int>& nums) {
        
        if(currIdx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> s;
        for(int i=currIdx;i<nums.size();i++) 
        {
            if(s.find(nums[i]) != s.end()) continue;
            s.insert(nums[i]);
            swap(nums[currIdx], nums[i]);
            backtrack(currIdx+1, ans, nums);
            swap(nums[currIdx], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(0, ans, nums);
        return ans;
    }
};