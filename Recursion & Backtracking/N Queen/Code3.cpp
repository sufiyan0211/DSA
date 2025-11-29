class Solution {
public:
    void solveNQueens(int currCol, int n, 
        vector<string> &board,
        vector<int> &horizontalLeft, 
        vector<int> &diagonallyLeftUpward, 
        vector<int> &diagonallyLeftDownward, 
        vector<vector<string>> &ans) {

        // base condition
        if(currCol == n) {
            ans.push_back(board);
            return;
        }
        

        for(int currRow=0; currRow<n; currRow++) {
            if(horizontalLeft[currRow] == 0 &&
                diagonallyLeftUpward[n-1 + currCol-currRow] == 0 &&
                diagonallyLeftDownward[currRow + currCol] == 0 ) {

                    board[currRow][currCol] = 'Q';
                    horizontalLeft[currRow] = 1;
                    diagonallyLeftUpward[n-1 + currCol-currRow] = 1;
                    diagonallyLeftDownward[currRow + currCol] = 1;

                    solveNQueens(currCol+1, n, board, horizontalLeft, 
                                diagonallyLeftUpward, diagonallyLeftDownward, ans);


                    board[currRow][currCol] = '.';
                    horizontalLeft[currRow] = 0;
                    diagonallyLeftUpward[n-1 + currCol-currRow] = 0;
                    diagonallyLeftDownward[currRow + currCol] = 0;


               }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> board(n, s);
        
        vector<vector<string>> ans;
        vector<int> horizontalLeft(n, 0), diagonallyLeftUpward(2*n, 0), diagonallyLeftDownward(2*n, 0);
        
        solveNQueens(0, n, board, horizontalLeft, diagonallyLeftUpward, diagonallyLeftDownward, ans);

        return ans;
    }
};
