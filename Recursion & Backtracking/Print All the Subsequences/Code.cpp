#include<bits/stdc++.h>
using namespace std;

void backtrack(int currIdx,
	vector<int> vi, vector<vector<int>> &ans,
	vector<int> &nums) {
	if(currIdx == nums.size()) {
		ans.push_back(vi);
		return;
	}

	vi.push_back(nums[currIdx]);
	backtrack(currIdx+1, vi, ans, nums);

	vi.pop_back();
	backtrack(currIdx+1, vi, ans, nums);
}

int main() {
	vector <int> nums = {1, 2, 1};

	vector<int> vi;
	vector<vector<int>> ans;

	backtrack(0, vi, ans, nums);

	for(int i=0;i<ans.size();i++) {
		for(auto it: ans[i]) {
			cout << it << " ";
		}
		cout << endl;
	}


	return 0;
}