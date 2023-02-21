#include<bits/stdc++.h>
using namespace std;

void backtrack(int currIdx, int currSum,  int target,
	vector<int> vi, vector<vector<int>> &ans,
	vector<int> &nums) {
	if(currIdx == nums.size()) {
		if(currSum == target) {
			ans.push_back(vi);
		}
		return;
	}

	currSum += nums[currIdx];
	vi.push_back(nums[currIdx]);
	backtrack(currIdx+1, currSum, target, vi, ans, nums);

	vi.pop_back();
	currSum -= nums[currIdx];
	backtrack(currIdx+1, currSum, target, vi, ans, nums);
}

int main() {
	vector <int> nums = {1, 2, 1};
	int target = 2;

	vector<int> vi;
	vector<vector<int>> ans;

	backtrack(0, 0, target, vi, ans, nums);

	for(int i=0;i<ans.size();i++) {
		for(auto it: ans[i]) {
			cout << it << " ";
		}
		cout << endl;
	}


	return 0;
}