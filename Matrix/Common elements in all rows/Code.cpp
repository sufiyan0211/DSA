#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// rows -> n
// cols -> m

vector<int> commonElementsFromAllRows(vector<vector<int> > &arr, int n, int m) {
	unordered_map<int, int> ump;
	for(int j=0;j<m;j++) {
		ump[arr[0][j]] = 1;
	}

	vector<int> ans;

	for(int i=1;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(ump[arr[i][j]] == i) {
				ump[arr[i][j]] = i+1;
				if(i == n-1 && ump[arr[i][j]] == n) {
					ans.push_back(arr[i][j]);
				}
			}
		}
	}

	return ans;
}


int main() {
	int n,m; cin >> n >> m;
	vector<vector<int> > arr(n, vector<int>(m));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin >> arr[i][j];
		}
	}
	vector<int> ans = commonElementsFromAllRows(arr, n, m);
	for(int i=0;i<ans.size();i++) {
		cout << ans[i] << " ";
	} cout << endl;

	return 0;
}