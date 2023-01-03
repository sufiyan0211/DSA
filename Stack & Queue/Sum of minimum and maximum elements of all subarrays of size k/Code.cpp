#include <bits/stdc++.h>
using namespace std;

int maxMin(int arr[], int n, int k) {
	deque<int> maxi, mini;
	for(int i=0;i<k;i++) {
		while(!maxi.empty() && arr[maxi.back()] <= arr[i]) {
			maxi.pop_back();
		}

		while(!mini.empty() && arr[mini.back()] >= arr[i]) {
			mini.pop_back();
		}

		maxi.push_back(i);
		mini.push_back(i);
	}

	int sum = 0;
	for(int i=k;i<n;i++) { 
		sum += arr[maxi.front()] + arr[mini.front()];

		while(!maxi.empty() && maxi.front() <= i-k) {
			maxi.pop_front();
		}

		while(!mini.empty() && mini.front() <= i-k) {
			mini.pop_front();
		}

		while(!maxi.empty() && arr[maxi.back()] <= arr[i]) {
			maxi.pop_back();
		}

		while(!mini.empty() && arr[mini.back()] >= arr[i]) {
			mini.pop_back();
		}

		maxi.push_back(i);
		mini.push_back(i);
	}
	sum += arr[maxi.front()] + arr[mini.front()];
	return sum;
}

int main() {
	int n,k; cin >> n >> k;
	int arr[n];
	for(int i=0;i<n;i++) cin >> arr[i];
	int sum = maxMin(arr, n, k);
	cout << sum << endl;
	
	return 0;
}