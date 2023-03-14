#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int r, int c1, int c2, int rows, int cols,
          vector<vector<int>> &grid,
          vector<vector<vector<int>>> &dp) {

    if(c1 < 0 || c1 >= cols || c2 < 0 || c2 >= cols) return -1e8;

    if(r == rows-1) {
        if(c1 == c2) return grid[r][c1];
        else return grid[r][c1] + grid[r][c2];
    }

    if(dp[r][c1][c2] != -1) return dp[r][c1][c2];

    int maxi = -1e8;
    for(int dc1 = -1; dc1 <= 1; dc1++) {
        int value = 0;
        for(int dc2 = -1; dc2 <= 1; dc2++) {
            if(c1 == c2) value = grid[r][c1];
            else value = grid[r][c1] + grid[r][c2];
            value += solve(r+1, c1+dc1, c2+dc2, rows, cols, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[r][c1][c2] = maxi;
}

int maximumChocolates(int rows, int cols, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(rows, vector<vector<int>> (cols, vector<int> (cols, -1)));
    return solve(0, 0, cols-1, rows, cols, grid, dp);
}