#include <iostream>
#include <vector>
using namespace std;

int solve(int i, int target, int n, vector<int> &num) {

    if(target == 0) {
        return 1;
    }

    if(i == n-1) {
        if(num[i] == target) return 1;
        else return 0;
    }

    if(i >= n) return 0;

    int pick = 0;
    if(target-num[i] >= 0)
        pick = solve(i+1, target-num[i], n, num);
    int notPick = solve(i+1, target, n, num);

    return pick+notPick;
}

int findWays(vector<int> &num, int target)
{
    // Write your code here.
    int n = num.size();
    return solve(0, target, n, num);
}