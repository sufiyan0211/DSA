#include <iostream>
#include <vector>
using namespace std;

int minSum(int r, int c, int n,
           vector<vector<int>>& triangle) {
    if(r < 0 || c < 0 || r >= n || c >= n) return 1e8;
    if(r == n-2) {
        return triangle[r][c] + min(triangle[r+1][c], triangle[r+1][c+1]);
    }
    int down = triangle[r][c] + minSum(r+1, c, n, triangle);
    int downRight = triangle[r][c] + minSum(r+1, c+1, n, triangle);

    return min(down, downRight);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    // Write your code here.
    if(n == 1) return triangle[0][0];
    return minSum(0, 0, n, triangle);
}