vector<int> kadanes(vector<int> &arr) {
    
    vector<int> ans(3);
    
    int curr_min = arr[0], curr_max = arr[0];
    int final_min = arr[0], final_max = arr[0];
    int sum = arr[0];
    
    
    for(int i=1; i<arr.size(); i++) {
        curr_min = min(arr[i], curr_min+arr[i]);
        final_min = min(final_min, curr_min);
        
        curr_max = max(arr[i], curr_max+arr[i]);
        final_max = max(final_max, curr_max);
        
        sum += arr[i];
    }
    
    ans[0] = final_min;
    ans[1] = final_max;
    ans[2] = sum;
    
    return ans;
}
    
int circularSubarraySum(vector<int> &arr) {
    // your code here
    vector<int> ans = kadanes(arr);
    
    int final_min = ans[0];
    int final_max = ans[1];
    int sum  = ans[2];
    
    if(final_max < 0) return final_max;
    
    return max(final_max, sum-final_min);
    
}