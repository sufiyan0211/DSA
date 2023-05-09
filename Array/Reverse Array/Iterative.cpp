#include<iostream>
#include<vector>
using namespace std;

void reverseArr(vector<int> &arr, int n) {
    int l = 0, r = n-1;
    while(l < r) {
        swap(arr[l++], arr[r--]);
    }
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

    reverseArr(arr, n);

    printArr(arr, n);

    return 0;
}