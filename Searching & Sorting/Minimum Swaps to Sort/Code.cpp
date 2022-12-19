#include <bits/stdc++.h>
#include <vector>
using namespace std;


int minSwaps(vector<int>&arr)
{
    // Code here
    int n = arr.size();
    
    vector<pair<int, int> > v;
    for(int i=0;i<n;i++) {
	    v.push_back(make_pair(arr[i], i));
    }
    sort(v.begin(), v.end());
    
    int i = 0;
    int swapCount = 0;
    while(i<n) {
        int value = v[i].first;
        int index = v[i].second;
        
        if(i == index) i++;
        else {
            swap(v[i], v[index]);
            swapCount++;
        }
    }
    return swapCount;  
}


int main() {
	int n; cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}
	cout << "minSwaps: " << minSwaps(arr) << endl;

	return 0;
}