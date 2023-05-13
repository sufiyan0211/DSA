class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return intervals;
        vector<vector<int>> ans;
        if(intervals.size() == 0) return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++) {
            vector<int>pre = ans.back();
            if(intervals[i][0] >= pre[0] && intervals[i][0] <= pre[1]) {
                ans.back()[0] = min(ans.back()[0], intervals[i][0]);
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};