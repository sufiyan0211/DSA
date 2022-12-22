#include<bits/stdc++.h>
using namespace std;

int maxSum(int arr1[], int arr2[], int n1, int n2) {
	int i = 0, j = 0;
	vector<int> commonElements;

	while(i<n1 && j <n2) {
		if(arr1[i] == arr2[j]) {
			commonElements.push_back(arr1[i]);
			i++;
			j++;
		}
		else if(arr1[i] < arr2[j]) {
			i++;
		}
		else j++;
	}

	int countOfCommonElements = commonElements.size();
	vector<int> sumArr1(countOfCommonElements+1);
	vector<int> sumArr2(countOfCommonElements+1);

	int sum = 0;
	j = 0;
	for(i=0;i<n1;i++) {
		sum += arr1[i];
		if(arr1[i] == commonElements[j]) {
			sumArr1[j] = sum;
			j++;
			sum = 0;
		}
	}
	if(j == countOfCommonElements) {
		sumArr1[j] = sum;
	}

	sum = 0;
	j = 0;
	for(i=0;i<n2;i++) {
		sum += arr2[i];
		if(arr2[i] == commonElements[j]) {
			sumArr2[j] = sum;
			j++;
			sum = 0;
		}
	}
	if(j == countOfCommonElements) {
		sumArr2[j] = sum;
	}

	int maxSum = 0;
	for(i=0;i<=countOfCommonElements;i++) {
		if(sumArr1[i] >= sumArr2[i]) {
			maxSum += sumArr1[i];
		}
		else
		{
			maxSum += sumArr2[i];
		}
	}
	return maxSum;
}


int main() {
	int n1,n2;
	cin >> n1 >> n2;
	int arr1[n1], arr2[n2];
	for(int i=0;i<n1;i++) cin >> arr1[i];
	for(int i=0;i<n2;i++) cin >> arr2[i];

	cout << maxSum(arr1, arr2, n1, n2) << endl;

	return 0;
}
