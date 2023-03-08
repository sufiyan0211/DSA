class Solution {
    int m = 1000000007;
  public:
    long long int nthFibonacci(long long int n){
        // code here
        long long int prevPrev = 0, prev = 1;
        for(long long int i=2;i<=n;i++) {
            long long int curri = (prev%m + prevPrev%m)%m;
            prevPrev = prev;
            prev = curri;
        }
        return prev;
    }
};