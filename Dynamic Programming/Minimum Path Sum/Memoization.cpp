#include <iostream>
#include <vector>
using namespace std;
int solve(int currRow, int currCol, int rows, int cols,
          vector<vector<int>> &grid,
          vector<vector<int>> &dp) {

    if(currRow == rows-1 && currCol == cols-1) return grid[currRow][currCol];
    if(currRow >= rows || currCol >= cols) return 1e8;

    if(dp[currRow][currCol] != -1) return dp[currRow][currCol];

    int right = grid[currRow][currCol] + solve(currRow + 1, currCol, rows, cols, grid, dp);

    int down = grid[currRow][currCol] + solve(currRow, currCol + 1, rows, cols, grid, dp);

    return dp[currRow][currCol] = min(right, down);
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dp(rows, vector<int> (cols, -1));
    return solve(0, 0, rows, cols, grid, dp);
}

int main() {
    vector<vector<int>> grid = {{1, 2, 3},
                                {4, 5, 4},
                                {7, 5, 9}};

    cout << minSumPath(grid) << endl;
    return 0;
}