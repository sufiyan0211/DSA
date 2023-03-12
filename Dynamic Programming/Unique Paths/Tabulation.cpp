int solve(int currentRow, int currentCol, int m, int n,
		vector<vector<int>> &dp
) {
	if(dp[currentRow][currentCol] != -1) return dp[currentRow][currentCol];
	
	if(currentRow == m-1 && currentCol == n-1) return 1;
	
	int leftCall = 0, rightCall = 0;

	if(currentRow+1 < m)
		leftCall = solve(currentRow+1, currentCol, m, n, dp);
	if(currentCol+1 < n) 
		rightCall = solve(currentRow, currentCol+1, m, n, dp);
	
	return dp[currentRow][currentCol] = leftCall+rightCall;
}


int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int> (n, -1));
	return solve(0, 0, m, n, dp);
}