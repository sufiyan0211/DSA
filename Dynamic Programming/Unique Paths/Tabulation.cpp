#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int m, int n) {
    // Write your code here.
    vector<vector<int>> dp(m, vector<int> (n, -1));
    dp[m-1][n-1] = 1;

    for(int row=m-1; row>=0; row--) {
        for(int col=n-1; col>=0; col--) {
            if(row == m-1 && col == n-1) continue;
            int leftCall = 0, rightCall = 0;
            if(row+1 < m)
                leftCall = dp[row+1][col];
            if(col+1 < n)
                rightCall = dp[row][col+1];
            dp[row][col] = leftCall+rightCall;
        }
    }
    return dp[0][0];
}


int main() {
    int n = 4, m = 4;
    cout << uniquePaths(m, n) << endl;

    return 0;
}