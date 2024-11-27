int getPairsCount(vector<int> &arr, int size, int target) {
	
	unordered_set<int> us;
	int ans = 0;
	
	for(int i=0;i<size;i++) {
		int secondElement = target - arr[i];
		if(us.find(secondElement) != us.end()) {
			ans++;
		}
		us.insert(arr[i]);
	}

	return ans;
}
