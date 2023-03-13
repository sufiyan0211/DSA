#include <iostream>
#include <vector>
using namespace std;

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

    for(int c=0; c<cols; c++) {
        dp[rows-1][c] = matrix[rows-1][c];
    }

    for(int r = rows-2; r >= 0; r--) {
        for(int c = cols-1; c >= 0; c--) {

            int down = INT_MIN, downLeft = INT_MIN, downRight = INT_MIN;
            if(r+1 < rows) {
                down = matrix[r][c] + dp[r+1][c];
            }

            if(r+1 < rows && c-1 >= 0) {
                downLeft = matrix[r][c] + dp[r+1][c-1];
            }

            if(r+1 < rows && c+1 < cols) {
                downRight = matrix[r][c] + dp[r+1][c+1];
            }

            dp[r][c] = max({down, downLeft, downRight});
        }
    }

    maxi = INT_MIN;
    for(int c=0; c<cols; c++) {
        maxi = max(maxi, dp[0][c]);
    }
    return maxi;
}


int main() {
    vector<vector<int>> matrix = {{10, 2, 3},
                                  {3, 7, 2},
                                  {8, 1, 5}};

    cout << getMaxPathSum(matrix) << endl;
    return 0;
}