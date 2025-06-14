class Solution{
public:
    vector<int> help_classmate(vector<int> arr, int n)
    {
        // Your code goes here
        vector<int> nextSmallerArray(n);
        stack<int> st;
        
        for(int i=size-1; i>=0; i--) {
            while(!st.empty() && (arr[st.top()] >= arr[i])) st.pop();
            
            nextSmallerArray[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        
        return nextSmallerArray;
    }
};