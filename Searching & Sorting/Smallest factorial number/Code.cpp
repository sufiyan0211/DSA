#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int countTrailingZeros(int n) {
        int sum = 0;
        while(n!=0) {
            sum += floor(n/5);
            n /= 5;
        }
        return sum;
    }
    public:
        int findNum(int n)
        {
            if(n == 0) return 0;
            
            int low = 5;
            int high = 1e7;
            
            while(low <= high) {
                int mid = (low+high) >> 1;
                int computation = countTrailingZeros(mid);
                if(computation >= n) {
                    high = mid - 1;
                }
                else if(computation < n) {
                    low = mid + 1;
                }
                
            }
            return low;
        }
};

int main() {
    int n;
    cin >> n;
    Solution ob;
    cout <<ob.findNum(n) << endl;
    return 0;
}