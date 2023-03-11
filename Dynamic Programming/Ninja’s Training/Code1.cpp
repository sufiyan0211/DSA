int solve(int currentRow, int lastVisitedCol, 
    vector<vector<int>> &points, int n, 
    vector<vector<int>> &dp
    ) {  
    
    if(dp[currentRow][lastVisitedCol+1] != -1) return dp[currentRow][lastVisitedCol+1];
    if(currentRow == n-1) {
        int maxi = 0;
        for(int cols=0; cols<=2; cols++) {
            if(cols == lastVisitedCol) continue; 
            maxi = max(maxi, points[n-1][cols]);
        }
        return dp[currentRow][lastVisitedCol+1] = maxi;
    }

    int maxi = 0;
    for(int cols=0; cols<=2; cols++) {
        if(cols == lastVisitedCol) continue;
        int call = points[currentRow][cols] + solve(currentRow+1, cols, points, n, dp);
        maxi = max(maxi, call);
    }
    return dp[currentRow][lastVisitedCol+1] = maxi;
}

int ninjaTraining(int n, vector<vector<int> > &points)
{
    // Write your code here.
    vector<vector<int> > dp(n, vector<int> (4, -1));
    return solve(0, -1, points, n, dp);
}