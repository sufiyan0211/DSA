class Solution {
private:
void backtrack(int currCol, vector<string> &board, int n, vector<vector<string>>& ans,
vector<int> &leftDiagonalUpper, vector<int>& leftDiagonalDown, vector<int>& leftHorizontal
) {
    if(currCol == n) {
        ans.push_back(board);
    }

    for(int currRow = 0; currRow<n; currRow++) {
        if( board[currRow][currCol] == '.' && 
        leftHorizontal[currRow] == 0 &&
        leftDiagonalUpper[n-1 + currCol-currRow] == 0 &&
        leftDiagonalDown[currRow + currCol] == 0
        ) {
            board[currRow][currCol] = 'Q';
            leftHorizontal[currRow] = 1;
            leftDiagonalUpper[n-1 + currCol-currRow] = 1;
            leftDiagonalDown[currRow + currCol] = 1;

            backtrack(currCol+1, board, n, ans, leftDiagonalUpper, leftDiagonalDown, leftHorizontal);

            board[currRow][currCol] = '.';
            leftHorizontal[currRow] = 0;
            leftDiagonalUpper[n-1 + currCol-currRow] = 0;
            leftDiagonalDown[currRow + currCol] = 0;
        }
    }
}

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n, '.');
        for(int i=0;i<n;i++) {
            board[i] = s;
        }
        vector<int> leftHorizontal(n, 0);
        vector<int> leftDiagonalUpper(2*n - 1, 0);
        vector<int> leftDiagonalDown(2*n - 1, 0);
        vector<vector<string>> ans;
        backtrack(0, board, n, ans, leftDiagonalUpper, leftDiagonalDown, leftHorizontal);
        return ans;
    }
};