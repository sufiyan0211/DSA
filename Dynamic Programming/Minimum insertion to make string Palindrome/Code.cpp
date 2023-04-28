#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int palindromeLcs(string str1) {
    int n = str1.size();
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    for(int i=0; i<=n; i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][n];
}

int minInsertion(string &str)
{
    // Write your code here.
    int n = str.size();
    int l = palindromeLcs(str);
    return n-l;
}