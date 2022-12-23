#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:

    long long int merge(long long int arr[], long long int left, long long int mid, long long int right) {
        long long int n1 = mid - left + 1;
        long long int n2 = right - mid;
        
        long long int a[n1], b[n2];
        long long int i,j,k;
        
        k = 0;
    	for(i=left;i<=mid;i++) {
    		a[k++] = arr[i];
    	}
    
    	k = 0;
    	for(i=mid+1;i<=right;i++) {
    		b[k++] = arr[i];
    	}

        
        i = 0;
        j = 0;
        k = left;
        long long int inversions = 0;
        while(i<n1 && j<n2) {
            if(a[i] <= b[j]) {
                arr[k++] = a[i++];
            }
            else {
                inversions += (n1 - i);
                arr[k++] = b[j++];
            }
        }
        while(i<n1)
        {
            arr[k++] = a[i++];
        }
        while(j<n2)
        {
            arr[k++] = b[j++];
        }
        
        return inversions;
    }
    long long int mergeSort(long long int arr[], long long int left, long long int right) {
        long long int inversions = 0;
        if(left < right) {
            long long int mid = (left+right) >> 1;
            inversions += mergeSort(arr, left, mid);
            inversions += mergeSort(arr, mid+1, right);
            inversions += merge(arr, left, mid, right);
        }
        return inversions;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long int ans = mergeSort(arr, 0, N-1);
        return ans;
    }

};


int main() {
    long long N;
    cin >> N;
    
    long long A[N];
    for(long long i = 0;i<N;i++){
        cin >> A[i];
    }
    Solution obj;
    cout << obj.inversionCount(A,N) << endl;
    
    return 0;
}
