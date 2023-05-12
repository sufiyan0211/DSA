class Solution{
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr+n);

        int diff = arr[n-1] - arr[0];

        int mini = arr[0]+k;
        int maxi = arr[n-1]-k;

        for(int i=1; i<n; i++) {

            mini = min(arr[0]+k, arr[i]-k);
            maxi = max(arr[n-1]-k, arr[i-1]+k);

            diff = min(diff, maxi-mini);
        }
        return diff;
    }
};