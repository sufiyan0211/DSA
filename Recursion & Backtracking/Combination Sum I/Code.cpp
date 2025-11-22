class Solution {
public:
    void combinationSum(vector<int>& candidates, int target, 
                        int index, vector<int> path, int sum,
                        vector<vector<int>> &ans) {
        if (index == candidates.size()) {
            if (sum == target) {
                ans.push_back(path);
            }
            return;
        }

        // pick
        if (sum+candidates[index] <= target) {
            sum += candidates[index];
            path.push_back(candidates[index]);
            combinationSum(candidates, target, index, path, sum, ans);
            sum -= candidates[index];
            path.pop_back();
        }

        // not pick
        combinationSum(candidates, target, index+1, path, sum, ans);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> ans;
        combinationSum(candidates, target, 0, path, 0, ans);
        return ans;
    }
};
