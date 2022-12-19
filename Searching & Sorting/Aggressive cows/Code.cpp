#include <bits/stdc++.h>

using namespace std;

bool canPlaceCows(int arr[], int n, int Totalcows, int distance) {
	
	int cowCordinate = arr[0];
	int countOfCowPlaced = 1;

	for(int i=1;i<n;i++) {
		if(arr[i] - cowCordinate >= distance) {
			cowCordinate = arr[i];
			countOfCowPlaced++;
		}
		if(Totalcows == countOfCowPlaced) {
			return true;
		}
	}
	return false;
}

int largestMinDistance(int arr[], int n, int cows) {
	sort(arr, arr+n);

	int low = 1;
	int high = arr[n-1] - a[0];

	int res = -1;

	while(low <= high) {
		int mid = (low+high) >> 1;
		if(canPlaceCows(arr, n, cows, mid)) {
			res = mid;
			low = mid + 1;	
		}
		else {
			high = mid - 1;
		}
	}
	return res;
}


int main() {
	int n; cin >> n;
	int cows; cin >> cows;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}
	cout << "largestMinDistance : " <<  largestMinDistance(arr, n, cows) << endl;

}