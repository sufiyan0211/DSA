#include <bits/stdc++.h> 
using namespace std; 

vector<int> spirallyTraverse(vector<vector<int> > arr, int r, int c) 
{
    int top = 0;
    int bottom = r-1;
    int left = 0;
    int right = c-1;
    
    int i,j;
    vector<int> ans;
    while(top<=bottom && left<=right) {
        
        for(j=left;j<=right;j++) {
            ans.push_back(arr[top][j]);
        }
        top++;
        
        for(i=top;i<=bottom;i++) {
            ans.push_back(arr[i][right]);
        }
        right--;
        
        if(top<=bottom) {
            for(j=right;j>=left;j--) {
                ans.push_back(arr[bottom][j]);
            }
            bottom--;
        }
        
        if(left<=right) {
            for(int i=bottom;i>=top;i--){
            ans.push_back(arr[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main() {
    int r,c;
    cin>>r>>c;
    vector<vector<int> > matrix(r); 

    for(int i=0; i<r; i++)
    {
        matrix[i].assign(c, 0);
        for( int j=0; j<c; j++)
        {
            cin>>matrix[i][j];
        }
    }
    vector<int> result = spirallyTraverse(matrix, r, c);
    for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
    cout<<endl;
    return 0;
}
