#include<iostream>
#include<vector>
using namespace std;

void reverseArr(vector<int> &arr, int l, int r) {
    if(l >= r) return;

    swap(arr[l], arr[r]);

    reverseArr(arr, l+1, r-1);
}

void printArr(vector<int> &arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {2, 1, 8, 10, 11};
    int n = arr.size();

    reverseArr(arr, 0, n-1);

    printArr(arr, n);

    return 0;
}