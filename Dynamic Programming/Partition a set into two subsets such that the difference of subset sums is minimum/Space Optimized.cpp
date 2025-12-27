class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += arr[i];
        }
        
        vector<bool> prev(sum+1, false), curr(sum+1, false);
        
        // Base case: sum 0 is always achievable
        prev[0] = curr[0] = true;
        
        // Base case: at last index, can achieve arr[n-1] by picking it
        prev[arr[n-1]] = true;
        
        // Fill DP table
        for(int i=n-2; i>=0; i--) {
            for(int s=1; s<=sum; s++) {
                bool notPick = prev[s];
                bool pick = false;
                if(s >= arr[i]) pick = prev[s-arr[i]];
                curr[s] = notPick || pick;
            }
            prev = curr;
        }
        
        // Find minimum difference
        int ans = INT_MAX;
        for(int s=0; s<=sum/2; s++) {
            if(prev[s]) ans = min(ans, abs((sum-s) - s)); 
        }
        
        return ans;
    }
};
