#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long int findSubarray(vector<long long int> &arr, int n ) {
    // There are three condition in which we can say that subarray sum is zero 
        /*
            1. if arr[i] == 0
            2. if prefixSum == 0
            3. if um[prefixSum] > 0
        */
        long long int count = 0;
        long long prefixSum = 0;
        
        unordered_map<long long int, long long int> um;
        um[0] = 1;  // when prefixSum == 0
        
        
        for(int i=0;i<n;i++) {
            prefixSum += arr[i];
            if(um.count(prefixSum) > 0) {
                count = count + um[prefixSum]; // when um[prefixSum] > 0
            } 
            um[prefixSum]++;
        }
        return count;
}

int main()
 { 
    int n;
    cin>>n; 
   
    vector<long long int> arr(n,0);
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
  
    cout << findSubarray(arr,n) << "\n";
    return 0;
}