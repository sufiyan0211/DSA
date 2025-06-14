class Solution {
    public:
    
      vector<int> findPreviousSmaller(vector<int> &arr) {
          int size = arr.size();
          vector<int> previousSmallerArray(size);
          stack<int> st;
  
          for(int i=0; i<size; i++) {
              while(!st.empty() && (arr[st.top()] >= arr[i])) st.pop();
              
              previousSmallerArray[i] = (st.empty()) ? -1 : st.top();
              st.push(i);
          }
          
          return previousSmallerArray;
      }
      
      vector<int> findNextSmaller(vector<int> &arr) {
          int size = arr.size();
          vector<int> nextSmallerArray(size);
          stack<int> st;
          
          
          for(int i=size-1; i>=0; i--) {
              while(!st.empty() && (arr[st.top()] >= arr[i])) st.pop();
              
              nextSmallerArray[i] = (st.empty()) ? size : st.top();
              st.push(i);
          }
          
          return nextSmallerArray;
      }
    
      int getMaxArea(vector<int> &arr) {
          // Your code here
          
         vector<int> prevSmaller =  findPreviousSmaller(arr);
         vector<int> nextSmaller =  findNextSmaller(arr);
         
         int maxArea = INT_MIN;
         
         for(int i=0; i<arr.size(); i++) {
             int area = (nextSmaller[i] - prevSmaller[i] - 1) * arr[i];
             maxArea = max(maxArea, area);
         }
         
         return maxArea;
      }
};
  