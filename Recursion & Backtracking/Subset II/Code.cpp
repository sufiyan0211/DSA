class Solution {
private:
    void solve(int i, int n, vector<int> &arr,
           vector<vector<int>> &ans,
           vector<int> vi) {
        if(i == n) {
            ans.push_back(vi);
            return;
        }

        // Pick
        vi.push_back(arr[i]);
        solve(i+1, n, arr, ans, vi);
        vi.pop_back();

        // notPick
        while(i+1 < n && arr[i] == arr[i+1]) i++;
        solve(i+1, n, arr, ans, vi);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> vi;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        solve(0, n, arr, ans, vi);
        return ans;
    }
};