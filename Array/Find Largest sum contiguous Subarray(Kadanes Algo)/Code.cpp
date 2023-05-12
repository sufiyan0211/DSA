class Solution{
public:
    int maxSubarraySum(int arr[], int n){
        // Your code here
        int curr_max = arr[0];
        int final_max = arr[0];
        for(int i=1;i<n;i++)
        {
            curr_max = max(curr_max+arr[i], arr[i]);
            final_max = max(final_max, curr_max);
        }
        return final_max;
    }
};