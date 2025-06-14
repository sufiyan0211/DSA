class Solution {
    public:
      int celebrity(vector<vector<int> >& mat) {
          // code here
          int size = mat.size();
          stack<int> st;
          
          for(int i=0; i<size; i++) {
              st.push(i);
          }
          
          while(st.size() > 1) {
              int i = st.top();
              st.pop();
              
              int j = st.top();
              st.pop();
              
              if(mat[i][j] == 0) {
                  st.push(i);
              }
              else {
                  st.push(j);
              }
          }
          
          int celebrity = st.top();
          
          for(int i=0; i<size; i++) {
              if(i != celebrity && 
                  (mat[i][celebrity] == 0 || mat[celebrity][i] == 1)) return -1;
          }
          
          return celebrity;
      }
  };