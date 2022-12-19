#include <bits/stdc++.h>
using namespace std;


int allocationPossible(int arr[], int n, int barrier, int totalStudents) {
        int student = 1;
        int pagesAlloted = 0;
        
        for(int i=0;i<n;i++) {
            if(arr[i] > barrier) {
                return false;
            }
            if(pagesAlloted+arr[i] > barrier) {
                student++;
                pagesAlloted = arr[i];
                if(student > totalStudents) return false;
            }
            else {
                pagesAlloted += arr[i];
            }
        }
        
        return true;
    }
    
    int findPages(int arr[], int n,  int totalStudents) 
    {
        //code here
        if(totalStudents > n) return -1;
        
        int sumOfPagesOfAllBooks = 0;
        for(int i=0;i<n;i++) {
            sumOfPagesOfAllBooks += arr[i];
        }
        
        int low = arr[0];
        int high = sumOfPagesOfAllBooks;
        
        int res = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            
            if(allocationPossible(arr, n, mid, totalStudents)) {
                res = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return res;
    }




int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int m;
    cin>>m;

    cout << findPages(A, n, m) << endl;

return 0;
}

