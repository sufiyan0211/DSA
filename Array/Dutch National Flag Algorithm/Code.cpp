#include <iostream>
#include <vector>
#include <algorithm>

void sorting(int arr[], int n)
{
    int low = 0, mid = 0, end = n-1;
    while(mid <= end) {
        switch(arr[mid]) {
            case 0:
                swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[end--]);
                break;
        }
    }
}