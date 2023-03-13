#include <iostream>
#include <vector>
using namespace std;

int solve(int r, int c, int rows, int cols,
          vector<vector<int>> &matrix,
          vector<vector<int>> &dp) {

    if(r == rows-1) {
        return matrix[r][c];
    }

    if(dp[r][c] != -1) return dp[r][c];

    int right = INT_MIN;
    if(r == 0 && c+1 < cols) {
        right = solve(r, c+1, rows, cols, matrix, dp);
    }

    int down = INT_MIN, downLeft = INT_MIN, downRight = INT_MIN;
    if(r+1 < rows) {
        down = matrix[r][c] + solve(r+1, c, rows, cols, matrix, dp);
    }

    if(r+1 < rows && c-1 >= 0) {
        downLeft = matrix[r][c] + solve(r+1, c-1, rows, cols, matrix, dp);
    }

    if(r+1 < rows && c+1 < cols) {
        downRight = matrix[r][c] + solve(r+1, c+1, rows, cols, matrix, dp);
    }

    return dp[r][c] = max({right, down, downLeft, downRight});
}


int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxi = matrix[0][0];

    if(rows == 1) {
        for(int i=1;i<cols;i++) {
            maxi = max(maxi, matrix[0][i]);
        }
        return maxi;
    }

    vector<vector<int>> dp(rows, vector<int> (cols, -1));
    return solve(0, 0, rows, cols, matrix, dp);
}


int main() {
    vector<vector<int>> matrix = {{-1, 0},
                                  {0, -1}};

    cout << getMaxPathSum(matrix) << endl;
    return 0;
}