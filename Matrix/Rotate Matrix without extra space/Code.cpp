#include<bits/stdc++.h>
#include<vector>
using namespace std;

void reverseByCol(vector<vector<int> >& arr, int n, int col) {
    int rowStart = 0;
    int rowEnd = n-1;
    while(rowStart < rowEnd) {
        swap(arr[rowStart][col], arr[rowEnd][col]);
        rowStart++;
        rowEnd--;
    }
}
void rotateMatrix(vector<vector<int> >& arr, int n) {
    // code here 
    
    // Step1: Transponse of matrix
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
    
    // Step2: Reverse each col
    for(int j=0;j<n;j++) {
        reverseByCol(arr, n, j);
    }
}


int main() {
    int n, x;
    cin >> n;
    vector<vector<int> > arr;
    for (int i = 0; i < n; i++) {
        vector<int> a;
        for (int j = 0; j < n; j++) {
            cin >> x;
            a.push_back(x);
        }
        arr.push_back(a);
    }
    rotateMatrix(arr, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
    }
    cout << "\n";
    return 0;
}
