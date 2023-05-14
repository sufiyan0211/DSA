class Solution{
public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> arr, int n) {
        // code here
        int minProd = arr[0];
        int maxProd = arr[0];
        int ans = arr[0];

        for(int i=1;i<n;i++) {
            if(arr[i] < 0) {
                swap(maxProd, minProd);
            }
            maxProd = max(arr[i], maxProd*arr[i]);
            minProd = min(arr[i], minProd*arr[i]);
            
            ans = max(ans, maxProd);
        }
        return ans;
    }
};