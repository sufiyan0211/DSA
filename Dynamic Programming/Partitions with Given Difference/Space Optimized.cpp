class Solution {
  public:
    int countPartitions(vector<int>& a, int diff) {
        // Code here
        int n = a.size();
        
        int sum = 0;
        for(auto x: a) sum += x;
        
        if (diff > sum || (sum + diff) % 2 != 0)
            return 0;
        
        int s1 = (diff + sum) / 2; 
        
        vector<int> prev(s1+1, 0), next(s1+1, 0);
        
        
        if(a[0] == 0) {
            prev[0] = 2;
        }
        else {
            prev[0] = 1;
            if(a[0] <= s1) prev[a[0]] = 1;
        }
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<=s1; j++) {
                int notPick = prev[j];
                
                int pick = 0;
                if(j - a[i] >= 0) pick = prev[j-a[i]];
                
                next[j] = pick+notPick;
            }
            prev = next;
        }
        
        
        return prev[s1];
    }
};