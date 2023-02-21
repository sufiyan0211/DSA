#include<bits/stdc++.h>
using namespace std;

int backtrack(int currIdx, int currSum,  int target,
	vector<int> &nums) {
	if(currIdx == nums.size()) {
		if(currSum == target) {
			return 1;
		}
		else {
			return 0;
		}
	}

	currSum += nums[currIdx];
	int include = backtrack(currIdx+1, currSum, target, nums);

	currSum -= nums[currIdx];
	int exclude = backtrack(currIdx+1, currSum, target, nums);

	return include+exclude;
}

int main() {
	vector <int> nums = {1, 2, 1};
	int target = 2;
	
	cout << backtrack(0, 0, target, nums) << endl;

	return 0;
}