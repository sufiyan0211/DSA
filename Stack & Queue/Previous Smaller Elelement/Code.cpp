class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        // code here
        vector<int> previousSmallerArray(n);
        stack<int> st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && (arr[st.top()] >= arr[i])) st.pop();
            
            previousSmallerArray[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        
        return previousSmallerArray;
    }
};