#include<bits/stdc++.h>
#include <vector>
using namespace std;

bool midTimeRequiredForOrder(int oderedPrata, int mid, int cooks,vector<int> rank) {
	int prata = 0;
	int time = 0;
	for(int i=0;i<cooks;i++) {
		int time = rank[i];
		int j = 2;
		while(time <= mid) {
			prata++;
			time = time + (rank[i] * j);
			j++;
		}
		if(prata >= oderedPrata) return true;
	}
	return false;
}

int minimumTimeForOrder(int oderedPrata, int cooks, vector<int> rank) {
	int low = 0;
	int high = 1e8;
	int ans = 0;

	while(low <= high) {
		int mid = (low+high) >> 1;
		if(midTimeRequiredForOrder(oderedPrata, mid, cooks, rank)) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}

int main() {
	int oderedPrata;
	int cooks;
	cin >> oderedPrata >> cooks;
	vector<int> rank(cooks);
	for(int i=0;i<cooks;i++) {
		cin >> rank[i];
	}
	int ans = minimumTimeForOrder(oderedPrata, cooks, rank);

	cout << "\nTime required for preparing " << oderedPrata << " is: " << ans << endl;

	return 0;
}