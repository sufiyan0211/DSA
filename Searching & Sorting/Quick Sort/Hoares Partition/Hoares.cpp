#include<iostream>
#include <vector>
using namespace std;

int hoaresPartition(vector<int> &arr, int l, int r) {
    int i = l-1;
    int j = r+1;
    int pivot = arr[l];
    while(true) {
        do {
            i++;
        } while(arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if(i >= j) return j;
        swap(arr[i], arr[j]);
    }
    return -1;
}

void quickSort(vector<int> &arr, int l, int r) {
    if(l < r) {
        int pivot = hoaresPartition(arr, l, r);
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

