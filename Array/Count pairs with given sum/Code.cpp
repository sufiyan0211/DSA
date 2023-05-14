class Solution{
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int, int> hashmap;

        int ans = 0;
        for(int i=0; i<n; i++) {
            if(hashmap.find(k-arr[i]) != hashmap.end()) {
                ans += hashmap[k-arr[i]];
            }
            hashmap[arr[i]]++;
        }

        return ans;
    }
};