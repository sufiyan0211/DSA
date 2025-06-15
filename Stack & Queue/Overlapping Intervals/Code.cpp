class Solution {
    public:
      vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
          // Code here
          vector<vector<int>> ans;
          
          int n = arr.size();
          
          sort(arr.begin(), arr.end());
          
          vector<int> res = arr[0];
          
          for(int i=1; i<n; i++) {
              int x = arr[i][0];
              int y = arr[i][1];
              
              if(x >= res[0] && x <= res[1]) {
                  if(y <= res[1]) {
                      continue;
                  }
                  else {
                      res[1] = y;
                  }
              }
              else {
                  ans.push_back(res);
                  res = arr[i];
              }
          }
          ans.push_back(res);
          return ans;
          
      }
  };