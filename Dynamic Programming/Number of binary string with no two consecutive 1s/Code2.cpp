//User function template for C++
class Solution{
public:
#define ll long long
    const int mod = 1e9+7;
    ll countStrings(int n) {
        // code here
        return optimize(n);
    }


    ll optimize(int n) {

        ll countZero = 1, countOne = 1;
        for(int i=2; i<=n; i++) {
            ll newCountZero = countZero%mod + countOne%mod;
            newCountZero %= mod;
            ll newCountOne = countZero;

            countZero = newCountZero;
            countOne = newCountOne;
        }

        ll ans =  countZero + countOne;
        ans %= mod;

        return ans;
    }
};