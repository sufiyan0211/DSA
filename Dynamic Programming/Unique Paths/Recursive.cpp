int solve(int currentRow, int currentCol, int m, int n,) {
	
	if(currentRow == m-1 && currentCol == n-1) return 1;
	
	int leftCall = 0, rightCall = 0;

	if(currentRow+1 < m)
		leftCall = solve(currentRow+1, currentCol, m, n);
	if(currentCol+1 < n) 
		rightCall = solve(currentRow, currentCol+1, m, n);
	
	return leftCall+rightCall;
}


int uniquePaths(int m, int n) {
	// Write your code here.
	return solve(0, 0, m, n);
}