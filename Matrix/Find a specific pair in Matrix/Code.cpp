#include<bits/stdc++.h>
using namespace std;

int maxValueOfdiff(vector<vector<int> > arr, int n) {
	vector<vector<int> > maxArr(n, vector<int>(n));

	maxArr[n-1][n-1] = arr[n-1][n-1];

	// pre process the last row
	// bottom row (right to left)
	int maxValue = arr[n-1][n-1];
	for(int j=n-2;j>=0;j--) {
		if(arr[n-1][j] > maxValue) {
			maxValue = arr[n-1][j];
		}
		maxArr[n-1][j] = maxValue;
	}

	// preProcess the last column
	// rightmost column (bottom to top)
	for(int i=n-2;i>=0;i--) {
		if(arr[i][n-1] > maxValue) {
			maxValue = arr[i][n-1];
		}
		maxArr[i][n-1] = maxValue;
	}

	maxValue = INT_MIN;

	for(int i=n-2;i>=0;i--) {
		for(int j=n-2;j>=0;j--) {
			if(maxArr[i+1][j+1] - arr[i][j] > maxValue) {
				maxValue = maxArr[i+1][j+1] - arr[i][j];
			}
			maxArr[i][j] = max(arr[i][j], max(maxArr[i+1][j], maxArr[i][j+1]));
		}
	}

	return maxValue;
}

int main() {
	int n; cin >> n;
	vector<vector<int> > arr(n, vector<int>(n));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin >> arr[i][j];
		}
	}
	int ans = maxValueOfdiff(arr, n);
	cout << ans << endl;


	return 0;
}