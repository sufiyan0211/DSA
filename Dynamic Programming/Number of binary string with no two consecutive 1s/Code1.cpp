//User function template for C++
class Solution{
public:
#define ll long long
    const int mod = 1e9+7;
    ll countStrings(int n) {
        // code here
        vector<ll> zero(n+1); // zero[i] means number of string whose ith char zero
        vector<ll> one(n+1); // one[i] means number of string whose ith char one
        zero[1] = one[1] = 1;

        for(int i=2; i<=n; i++) {
            zero[i] = zero[i-1] + one[i-1];
            zero[i] %= mod;
            one[i] = zero[i-1];
        }

        ll ans =  zero[n] + one[n];
        ans %= mod;
        return (int) ans;
    }
};