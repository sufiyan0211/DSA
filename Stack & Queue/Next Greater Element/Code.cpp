class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack <long long> s;
        vector<long long> ans(n);

        for(int i=n-1; i>=0; i--) {
            while(!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? -1 : s.top();
            s.push(arr[i]);
        }
        return ans;
    }
};