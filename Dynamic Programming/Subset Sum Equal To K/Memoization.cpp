class Solution {
  public:
    bool isSubsetSum(int index, int k, vector<int>& arr, int size, int sum,
        vector<vector<int>> &dp) {
               
        if (index >= size) return false;

        if(k - arr[index] == 0) return true;
        if(dp[index][k] != -1) return dp[index][k];
        
        bool pick = false;
        if(k - arr[index] >= 0) 
            pick = isSubsetSum(index+1, k-arr[index], arr, size, sum, dp);
        
        bool notPick = isSubsetSum(index+1, k, arr, size, sum, dp);
        
        return dp[index][k] = (pick || notPick);
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int size = arr.size();
        
        vector<vector<int>> dp(size, vector<int> (sum+1, -1));
        
        return isSubsetSum(0, sum, arr, size, sum, dp);
    }
};
