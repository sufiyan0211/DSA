#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        // There are three condition in which we can say that subarray sum is zero 
        /*
            1. if arr[i] == 0
            2. if prefix[i] == 0
            3. if um[prefix[i]] > 0
        */
        long long int count = 0; // total count of all the possible zero sum subarray
        long long prefixSum = 0;
        
        unordered_map<long long int, long long int> um;
        um[0] = 1;
        
        
        for(int i=0;i<n;i++) {
            prefixSum += arr[i];
            if(um.count(prefixSum) > 0) {
                count = count + um[prefixSum];
            }
            um[prefixSum]++;
        }
        return count;
    }
};


int main() {
    int n;
    cin>>n; //input size of array

    vector<long long int> arr(n,0);

    for(int i=0;i<n;i++)
        cin>>arr[i]; //input array elements
    Solution ob;
    cout << ob.findSubarray(arr,n) << "\n";

    return 0;
}