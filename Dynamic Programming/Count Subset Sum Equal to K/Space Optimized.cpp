class Solution {
  public:
    
    int perfectSum(vector<int>& a, int target) {
        // code here
        int n = a.size();
        
        vector<int> prev(target+1, 0), next(target+1, 0);
        
        if (a[0] == 0) {
            prev[0] = 2;   // pick and notPick both gives 1
        } else {
            prev[0] = 1;  
            if (a[0] <= target)
                prev[a[0]] = 1;
        }
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<=target; j++) {
                int notPick = prev[j];
                
                int pick = 0;
                if(j-a[i] >=0 ) pick = prev[j-a[i]];
                
                next[j] = pick+notPick;
            }
            prev = next;
        }
        
        return prev[target];
    }
};