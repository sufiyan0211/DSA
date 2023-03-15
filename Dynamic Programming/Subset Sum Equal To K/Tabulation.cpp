#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool> (k+1, false));

    for(int i=0;i<n;i++) {
        dp[i][0] = true;
    }

    if(arr[n-1] <= k)
        dp[n-1][arr[n-1]] = true;

    for(int i=n-2; i>=0; i--) {
        for(int target=1; target<=k; target++) {
            bool pick = false;
            if(target-arr[i] >= 0) {
                pick = dp[i+1][target-arr[i]];
            }
            bool notPick = dp[i+1][target];

            dp[i][target] = (pick || notPick);
        }
    }

    return dp[0][k];
}


int main() {
    vector<int> arr = {4, 3, 2, 1};
    int n = 4, k = 5;
    cout << subsetSumToK(n, k, arr) << endl;
    return 0;
}