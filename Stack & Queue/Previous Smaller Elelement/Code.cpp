class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        // code here
        vector<int> ans(n);
        stack<int> s;
        s.push(arr[0]);
        ans[0] = -1;
        for(int i=1;i<n;i++) {
            while(!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            ans[i] = (s.empty()) ? -1 : s.top();
            s.push(arr[i]);
        }
        return ans;
    }
};