class Solution {
  public:
    
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        
        vector<int> prev(sum+1, 0), next(sum+1, 0);
        
        // sum = 0
        for (int i = 0; i < n; i++) {
            prev[0] = 1;
        }
        
        // first coin
        for (int j = 0; j <= sum; j++) {
            if (j % coins[0] == 0)
                prev[j] = 1;
        }
        
        // fill dp table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= sum; j++) {
                
                int notPick = prev[j];
                int pick = 0;
                
                if (j >= coins[i]) {
                    pick = next[j - coins[i]];
                }
                
                next[j] = pick + notPick;
            }
            prev = next;
        }
        
        return prev[sum];
    }
};
