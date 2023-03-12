#include <iostream>
#include <vector>
using namespace std;
int solve(int currRow, int currCol, int rows, int cols,
          vector<vector<int>> &grid) {

    if(currRow == rows-1 && currCol == cols-1) return grid[currRow][currCol];
    if(currRow >= rows || currCol >= cols) return 1e8;

    int right = grid[currRow][currCol] + solve(currRow + 1, currCol, rows, cols, grid);

    int down = grid[currRow][currCol] + solve(currRow, currCol + 1, rows, cols, grid);

    return min(right, down);
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int rows = grid.size();
    int cols = grid[0].size();
    return solve(0, 0, rows, cols, grid);
}

int main() {
    vector<vector<int>> grid = {{1, 2, 3},
                                {4, 5, 4},
                                {7, 5, 9}};

    cout << minSumPath(grid) << endl;
    return 0;
}