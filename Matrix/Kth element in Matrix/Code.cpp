#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    int r;
    cin>>r;
    cout<<kthSmallest(mat,n,r)<<endl;
    return 0;
}



int binarySearchOnIthRow(int mat[MAX][MAX], int n, int i, int value) {
    int low = 0;
    int high = n-1;
    
    while(low <= high) {
        int mid = (low+high) >> 1;
        if(mat[i][mid] <= value) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int low = mat[0][0];
  int high = mat[n-1][n-1];
  while(low <= high) {
      int mid = (low+high) >> 1;
      
      int count = 0;
      for(int i=0;i<n;i++) {
          count += binarySearchOnIthRow(mat, n, i, mid);
      }
      if(count <= k-1) {
          low = mid + 1;
      }
      else {
          high = mid - 1;
      }
  }
  return low;
}
