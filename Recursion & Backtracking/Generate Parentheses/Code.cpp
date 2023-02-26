class Solution
{
    private:
    void backtrack(int open, int close, string currStr, int n, vector<string> &ans) {
        if(open == n && close == n) {
            ans.push_back(currStr);
            return;
        }
        if(open < n) {
            backtrack(open+1, close, currStr+"(", n, ans);
        }
        if(close < open) {
            backtrack(open, close+1, currStr+")", n, ans);
        }
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        backtrack(0, 0, "", n, ans);
        return ans;
    }
};