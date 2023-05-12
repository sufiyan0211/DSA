#include <iostream>
using namespace std;
void moveNegative(int arr[], int n) {
    int window = -1;
    for(int i=0; i<n; i++) {
        if(arr[i] < 0) {
            window++;
            swap(arr[i], arr[window]);
        }
    }
}

int main() {
    int arr[] = {1, 4, -4, 9, 2, -8, 3};
    int n = 7;
    moveNegative(arr, n);
    return 0;
}