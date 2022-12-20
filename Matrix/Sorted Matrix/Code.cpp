#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > sortedMatrix(int n, vector<vector<int> > arr) {
    vector<int> v;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            v.push_back(arr[i][j]);
        }
    }
    
    sort(v.begin(), v.end());
    
    int k = 0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            arr[i][j] = v[k++];
        }
    }
    return arr;
}


int main() {
    int N;
    cin >> N;
    vector<vector<int> > v(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> v[i][j];
    v = sortedMatrix(N, v);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << v[i][j] << " ";
        cout << "\n";
    }
    return 0;
}