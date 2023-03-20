class Solution{
public:
    vector<int> help_classmate(vector<int> arr, int n)
    {
        // Your code goes here
        vector<int> ans(n);
        stack<int> s;
        s.push(arr[n-1]);
        ans[n-1] = -1;

        for(int i=n-2;i>=0;i--) {
            while(!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            ans[i] = (s.empty()) ? -1 : s.top();
            s.push(arr[i]);
        }
        return ans;
    }
};