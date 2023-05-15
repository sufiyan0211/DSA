class Solution{
public:
    long long trappingWater(int arr[], int n){
        // code here
        int leftMax[n], rightMax[n];
        int startMax = arr[0], endMax = arr[n-1];
        leftMax[0] = startMax;
        rightMax[n-1] = endMax;

        for(int i=1; i<n-1; i++) {
            startMax = max(startMax, arr[i]);
            leftMax[i] = startMax;

            endMax = max(endMax, arr[n-1-i]);
            rightMax[n-1-i] = endMax;
        }

        long long capacity = 0;
        for(int i=1;i<n-1;i++) {
            long long temp = min(leftMax[i], rightMax[i]) - arr[i];
            if(temp > 0) {
                capacity += temp;
            }
        }

        return capacity;
    }
};