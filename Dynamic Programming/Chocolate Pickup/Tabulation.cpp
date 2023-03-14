#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumChocolates(int rows, int cols, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(rows, vector<vector<int>> (cols, vector<int> (cols, -1)));

    for(int c1=0; c1<cols; c1++) {
        for(int c2=0; c2<cols; c2++) {
            if(c1==c2) dp[rows-1][c1][c2] = grid[rows-1][c1];
            else dp[rows-1][c1][c2] = grid[rows-1][c1] + grid[rows-1][c2];
        }
    }

    for(int r=rows-2; r>=0; r--) {
        for(int c1=cols-1; c1>=0; c1--) {
            for(int c2=cols-1; c2>=0; c2--) {

                int maxi = -1e8;
                for(int dc1 = -1; dc1 <= 1; dc1++) {
                    int value = 0;
                    for(int dc2 = -1; dc2 <= 1; dc2++) {
                        if(c1 == c2) value = grid[r][c1];
                        else value = grid[r][c1] + grid[r][c2];
                        if(r+1 > rows || c1+dc1 < 0 || c1+dc1 >= cols || c2+dc2 < 0 || c2+dc2 >= cols) value = -1e8;
                        else value += dp[r+1][c1+dc1][c2+dc2];
                        maxi = max(maxi, value);
                    }
                }
                dp[r][c1][c2] = maxi;
            }
        }
    }

    return dp[0][0][cols-1];
}