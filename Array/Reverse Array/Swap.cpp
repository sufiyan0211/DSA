#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int left, int right) {
    if(left >= right) return;

    swap(arr[left], arr[right]);

    reverseArray(arr, left+1, right-1);
}

void printArray(vector<int> &arr) {
    cout << "printing array: \n";
    for(int value: arr) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    reverseArray(arr, 0, n-1);
    printArray(arr);

    return 0;
}

