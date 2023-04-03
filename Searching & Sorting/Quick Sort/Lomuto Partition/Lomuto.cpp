#include<iostream>
#include <vector>
using namespace std;

int lomutoPartition(vector<int> &arr, int l, int r) {
    int window = l-1;
    for(int i=l;i<=r-1;i++) {
        if(arr[i] <= arr[r]) {
            window++;
            swap(arr[i], arr[window]);
        }
    }
    window++;
    swap(arr[r], arr[window]);
    return window;
}

void quickSort(vector<int> &arr, int l, int r) {
    if(l < r) {
        int pivot = lomutoPartition(arr, l, r);
        quickSort(arr, l, pivot-1);
        quickSort(arr, pivot+1, r);
    }
}

void sorting(vector<int> &arr, int n) {
    quickSort(arr, 0, n-1);
}

int main() {
    vector<int> arr = {5, 12, 7, 10, 14, 11, 9};
    int n = arr.size();
    sorting(arr, n);

    /**
     * print arr
     */
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}