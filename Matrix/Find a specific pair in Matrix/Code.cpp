#include<bits/stdc++.h>

using namespace std;

int maxValueOfdiff(vector <vector<int>> mat, int n) {
    vector <vector<int>> maxArr(n, vector<int>(n));
    maxArr[n - 1][n - 1] = mat[n - 1][n - 1];

    // pre compute last column from bottom row to top row
    for (int currentRow = n - 2; currentRow >= 0; currentRow--) {
        maxArr[currentRow][n - 1] = max(maxArr[currentRow + 1][n - 1], mat[currentRow][n - 1]);
    }


    // pre compute last row from right row to left col
    for (int currentCol = n - 2; currentCol >= 0; currentCol--) {
        maxArr[n - 1][currentCol] = max(maxArr[n - 1][currentCol + 1], mat[n - 1][currentCol]);
    }

    int ans = -1e9;
    for (int row = n - 2; row >= 0; row--) {
        for (int col = n - 2; col >= 0; col--) {
            ans = max(ans, maxArr[row + 1][col + 1] - mat[row][col]);
            maxArr[row][col] = max(mat[row][col],
                                   max(maxArr[row + 1][col], maxArr[row][col + 1]));
        }
    }


    return ans;
}

int main() {
    int n;
    cin >> n;
    vector <vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = maxValueOfdiff(arr, n);
    cout << ans << endl;


    return 0;
}