class Solution {
private:
void backtrack(int currIdx, vector<int> vi,
    vector<vector<int>> &ans,
    int target, vector<int>& candidates) {
    
    if(target == 0) {
        ans.push_back(vi);
        return;
    }       

    for(int i=currIdx;i<candidates.size();i++) {
        if(i>currIdx && candidates[i] == candidates[i-1] ) continue;
        if(candidates[i] > target) break;
        vi.push_back(candidates[i]);
        backtrack(i+1, vi, ans, target-candidates[i], candidates);
        vi.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> vi;
        vector<vector<int>> ans;
        backtrack(0, vi, ans, target, candidates);
        return ans;
    }
};