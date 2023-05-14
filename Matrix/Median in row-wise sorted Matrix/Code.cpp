#include <bits/stdc++.h>
using namespace std;


int binarySearchOnEachRow(vector<int> arr, int C, int value) {
    int low = 0;
    int high = C-1;
    while(low <= high) {
        int mid = (low + high) >> 1;
        if(arr[mid] <= value) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int median(vector<vector<int> > &matrix, int R, int C){
    int low = 1;
    int high = 2000;
    int N = R*C;
    while(low <= high) {
        int mid = (low+high) >> 1;
        // count of numbers which is lesser than equal to mid
        int count = 0;
        for(int i=0;i<R;i++) {
            count += binarySearchOnEachRow(matrix[i], C, mid);
        }
        if(count <= N/2) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}



int main()
{
    int r, c;
    cin>>r>>c;
    vector<vector<int> > matrix(r, vector<int>(c));
    for(int i = 0; i < r; ++i)
        for(int j = 0;j < c; ++j)
            cin>>matrix[i][j];
    cout<<median(matrix, r, c)<<endl;        
    return 0;
}
