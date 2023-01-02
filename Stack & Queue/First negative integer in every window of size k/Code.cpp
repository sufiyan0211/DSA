#include <bits/stdc++.h>
using namespace std;

vector<int> printFirstNegativeInteger(int arr[], int n, int k) {
    vector<int> ans(n-k+1);
    deque<int> dq;
    for(int i=0;i<k;i++) {
        if(arr[i] < 0) {
            dq.push_back(i);
        }
    }
    ans[0] = (dq.empty()) ? 0 : arr[dq.front()];
    int j = 1;
    for(int i=k;i<n;i++) {
        if(arr[i] < 0) {
            dq.push_back(i);
        }
        while(!dq.empty() && dq.front() <= (i-k)) {
            dq.pop_front();
        }
        ans[j++] = (dq.empty()) ? 0 : arr[dq.front()];
    }
    return ans;
}


int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    vector<int> ans = printFirstNegativeInteger(arr, n, k);
    for (auto it : ans) cout << it << " ";
    cout << endl;
    return 0;
}


