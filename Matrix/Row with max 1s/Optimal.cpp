#include <iostream>
#include <vector>

using namespace std;

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    int ans = -1;
    int row = arr.size(), col = arr[0].size();
    int currentRow = 0, currentCol = col - 1; // starting location is top-right
    while (currentRow < row && currentCol >= 0) {
        if (arr[currentRow][currentCol] == 1) {
            currentCol--;
            ans = currentRow;
        } else if (arr[currentRow][currentCol] == 0) {
            currentRow++;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = rowWithMax1s(arr, n, m);
    cout << ans << "\n";

    return 0;
}

