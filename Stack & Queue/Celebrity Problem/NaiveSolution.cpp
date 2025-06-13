class Solution {
    public:
      int celebrity(vector<vector<int> >& mat) {
          // code here
          int size = mat.size();
          
          int celebrity = 0;
          
          for(int i=0; i<size; i++) {
              int count = 0;
              for(int j=0; j<size; j++) {
                  if(mat[i][j] == 0) {
                      count++;
                  }
              }
              if(count == size) celebrity = i;
          }
          
          for(int i=0; i<size; i++) {
              if( i!=celebrity && (mat[i][celebrity] == 0 || mat[celebrity][i] == 1)) return -1;
          }
          
          return celebrity;
      }
  };