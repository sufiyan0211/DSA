class Solution {
    int m = 1000000007;
  private:
    long long int findFibo(long long int n, vector<long long int> &fibo) {
        if(n<=1) return n;
        if(fibo[n] != -1) return fibo[n];
        return fibo[n] = (findFibo(n-1, fibo)%m + findFibo(n-2, fibo)%m )%m;
        
    }
    
  public:
    long long int nthFibonacci(long long int n){
        // code here
        vector<long long int> fibo(n+1, -1);
        findFibo(n, fibo);
        return fibo[n];
    }
};