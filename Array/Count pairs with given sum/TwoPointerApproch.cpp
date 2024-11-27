int getPairsCount(vector<int> &arr, int size, int target) {
  
	sort(arr.begin(), arr.end());
	int ans =0, left = 0, right = size-1;
  
	while(left < right) {
		int sum = arr[left] + arr[right];
		if(sum < target) {
			left++;
		}
		else if(sum > target) {
			right--;
		}
		else {
			ans++;
			left++; right++;
		}
	}
    return ans;
}
