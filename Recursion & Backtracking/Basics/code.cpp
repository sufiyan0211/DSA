#include <bits/stdc++.h>
using namespace std;


// // Print name 5 times 

// void solve(int n) {
// 	if(n == 0) {
// 		return;
// 	}
// 	cout <<"Name\n";
// 	solve(n-1);
// }

// int main() {
// 	int n = 5;
// 	solve(n);
// 	return 0;
// }

// // op:{
// // 	Name
// // 	Name
// // 	Name
// // 	Name
// // 	Name
// // }



// // Print Linearly from 1 to N

// void solve(int n) {
// 	if(n == 0){
// 		return;
// 	}
// 	solve(n-1);
// 	cout<<n<<endl;
// }

// int main() {
// 	int n = 5;
// 	solve(n);
// 	return 0;
// }

// // op:{
// // 	1
// // 	2
// // 	3
// // 	4
// // 	5
// // }



// // Print Linearly from N to 1

// void solve(int n) {
// 	if(n == 0){
// 		return;
// 	}
// 	cout<<n<<endl;
// 	solve(n-1);
// }

// int main() {
// 	int n = 5;
// 	solve(n);
// 	return 0;
// }

// // op:{
// // 	1
// // 	2
// // 	3
// // 	4
// // 	5
// // }



// // Reverse an Array
// void solve(vector<int> &arr,int l,int r) {
// 	if(l>=r) {
// 		return;
// 	}
// 	swap(arr[l], arr[r]);
// 	solve(arr, l+1, r-1);
// }

// void solve(vector<int> &arr, int i) {
// 	int n = arr.size();
// 	if(i>=n-i-1){
// 		return;
// 	}
// 	swap(arr[i], arr[n-i-1]);
// 	solve(arr, i+1);
// }

// int main() {
// 	vector<int> arr = {1,2,3,4,5};
// 	solve(arr, 0, 4);
// 	// solve(arr, 0);
// 	// printing the arr
// 	for(auto it: arr) {
// 		cout << it << " ";
// 	} cout << endl;
// 	return 0;
// }

// // op: 5 4 3 2 1




// // Check array is palindrome or not
// bool solve(vector<int> &arr, int l, int r) {
// 	if(l>=r) {
// 		return true;
// 	}
// 	if(arr[l] != arr[r]) {
// 		return false;
// 	}
// 	return solve(arr, l+1, r-1);
// }


// int main() {
// 	vector<int> arr = {1,2,3,2,1};
// 	cout << solve(arr, 0, 4) << endl;
// 	vector<int> arr2 = {1,2,3,4,5};
// 	cout << solve(arr2, 0, 4) << endl;
// 	return 0;
// }

// // op: 
// // 1 
// // 0




// // Fibonaci Series
// int solve(int n) {
// 	if(n == 0) return 0;
// 	if(n == 1) return 1;
// 	return solve(n-1)+solve(n-2);
// }

// int main() {
// 	int n = 6;
// 	cout << solve(n);
// 	return 0;
// }

// // 0,1,2,3,5,8,13,....
// // op: 8


