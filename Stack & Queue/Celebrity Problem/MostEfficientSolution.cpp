class Solution {
    public:
      int celebrity(vector<vector<int> >& mat) {
          // code here
          int size = mat.size();
          
          int celebrity = 0;
          for(int i=0; i<size; i++) {
              if(mat[celebrity][i] == 1) {
                  celebrity = i;
              }
          }
          
          for(int i=0; i<size; i++) {
              if(i != celebrity && (mat[celebrity][i] == 1 || mat[i][celebrity] == 0)) return -1;
          }
          
          return celebrity;
      }
  };