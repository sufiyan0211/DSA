#include <bits/stdc++.h>
using namespace std;

int binarySearchOnIthRow(vector<int> arr, int m) {
    int low = 0;
    int high = m-1;
    while(low <= high) {
        int mid = (low+high) >> 1;
        if(arr[mid] == 0) {
            low = mid + 1;
        }
        else if(arr[mid] == 1) {
            if(mid != 0 && arr[mid-1] == 1) {
                high = mid - 1;
            }
            else if(mid != 0 && arr[mid-1] != 1) return m-mid;
            else if(mid == 0) return m;
        }
    }
    return -1;
}
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    int ans = -1;
    int highestOnes = 0;
    
    for(int i=0;i<n;i++) {
        int count = binarySearchOnIthRow(arr[i], m);
        if(count > highestOnes) {
            highestOnes = count;
            ans = i;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > arr(n,vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>arr[i][j];
        }
    }
    int ans = rowWithMax1s(arr, n, m);
    cout << ans << "\n";

    return 0;
}

