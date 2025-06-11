class Solution {
    public:
      void insertAtBottomRecursive(stack<int> &st, int x) {
          if(st.empty()) {
              st.push(x);
              return;
          }
          
          int topp = st.top();
          st.pop();
          
          // recursive call
          insertAtBottomRecursive(st, x);
          
          st.push(topp);
      }
      
      stack<int> insertAtBottom(stack<int> st, int x) {
          insertAtBottomRecursive(st, x);
          return st;
      }
  };