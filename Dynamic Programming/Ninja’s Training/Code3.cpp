#include <iostream>
#include <vector>

using namespace std;

int solve(int currentRow, int lastVisitedCol, 
    vector<vector<int>> &points, int n, 
    vector<vector<int>> &dp
    ) {  
    
    if(lastVisitedCol >= 0 && dp[currentRow][lastVisitedCol] != -1) return dp[currentRow][lastVisitedCol];
    if(currentRow == n-1) {
        int maxi = 0;
        for(int cols=0; cols<=2; cols++) {
            if(cols == lastVisitedCol) continue; 
            maxi = max(maxi, points[n-1][cols]);
        }
        return dp[currentRow][lastVisitedCol] = maxi;
    }

    int maxi = 0;
    for(int cols=0; cols<=2; cols++) {
        if(cols == lastVisitedCol) continue;
        int call = points[currentRow][cols] + solve(currentRow+1, cols, points, n, dp);
        maxi = max(maxi, call);
    }
    return dp[currentRow][lastVisitedCol+1] = maxi;
}

int ninjaTraining(int n, vector<vector<int> > &points)
{
    // Write your code here.
    vector<vector<int> > dp(n, vector<int> (4, -1));

    dp[n-1][0] = max(points[n-1][1], points[n-1][2]);
    dp[n-1][1] = max(points[n-1][0], points[n-1][2]);
    dp[n-1][2] = max(points[n-1][0], points[n-1][1]);
    dp[n-1][3] = max({points[n - 1][0], points[n - 1][1], points[n - 1][2]});

// int lastVisited = -1; lastVisited<=2; lastVisited++
    for(int rows = n-2; rows >= 0; rows--) {
        for(int lastVisited = -1; lastVisited<=2; lastVisited++) {
            int maxi = 0;
            for(int cols=0; cols<=2; cols++) {
                if(cols == lastVisited) continue;
                int call = points[rows][cols] + dp[rows+1][cols];
                maxi = max(maxi, call);
                dp[rows][lastVisited+1] = maxi;
            }
        }
    }
    return dp[0][0];
}

int main() {

  vector < vector < int > > points = {{10, 50, 1},
                                      {5, 100, 11}};

  int n = points.size();
  cout << "Code3.cpp\n";
  cout << ninjaTraining(n, points) << endl;
}
