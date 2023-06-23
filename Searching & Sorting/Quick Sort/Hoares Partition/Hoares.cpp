#include<iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int l, int r) {
    int pivot = arr[l];
    int i = l;
    int j = r;
    while(i < j) {
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int l, int r) {
    if(l < r) {
        int pivot = partition(arr, l, r);
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

