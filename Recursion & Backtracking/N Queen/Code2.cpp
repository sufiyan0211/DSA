class Solution { 
private:
    void backtrack(int currCol, vector<vector<int>> &board, 
    int n, vector<vector<int>> &ans, vector<int> vi,
    vector<int> &leftDigonalUpper, vector<int> &leftDiagonalDown, vector<int> &horizontal
    ) {
        
        if(currCol == n) {
            ans.push_back(vi);
            return;
        }
        
        
        for(int currRow = 0; currRow<n; currRow++) {
            if(leftDiagonalDown[currRow + currCol] == 0 && 
            leftDigonalUpper[n-1 + currCol - currRow] == 0 && 
            horizontal[currRow] == 0 
            )
            {
                board[currRow][currCol] = 1;
                vi[currCol] = currRow+1;
                
                leftDigonalUpper[n-1 + currCol - currRow] = 1;
                leftDiagonalDown[currRow + currCol] = 1;
                horizontal[currRow] = 1;
                
                backtrack(currCol+1, board, n, ans, vi, leftDigonalUpper, leftDiagonalDown, horizontal);
                
                board[currRow][currCol] = 0;
                
                leftDigonalUpper[n-1 + currCol - currRow] = 0;
                leftDiagonalDown[currRow + currCol] = 0;
                horizontal[currRow] = 0;
            }
        }
        
        
    }
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n, vector<int> (n, 0));
        vector<vector<int>> ans;
        vector<int> leftDigonalUpper(2*n - 1, 0), leftDiagonalDown(2*n - 1, 0), horizontal(n, 0);
        vector<int> vi(n);
        backtrack(0, board, n, ans, vi, leftDigonalUpper, leftDiagonalDown, horizontal);
        return ans;
    }
};