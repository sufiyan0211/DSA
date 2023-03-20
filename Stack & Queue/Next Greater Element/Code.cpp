class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack <long long> s;
        s.push(arr[n-1]);
        vector<long long> ans(n);
        ans[n-1] = -1;
        for(int i=n-2;i>=0;i--) {
            while(!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            ans[i] = (s.empty()) ? -1 : s.top();
            s.push(arr[i]);
        }
        return ans;
    }
};