class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for(int i=0; i<9; i++) {
            if(board[row][i] == ch) return false;

            if(board[i][col] == ch) return false;

            int subRow = 3 * (row/3) + i/3;
            int subCol = 3 * (col/3) + i%3;

            if(board[subRow][subCol] == ch) return false;
        }
        return true;
    }


    bool solveSudokuUtil(vector<vector<char>>& board) {
        for(int row=0; row<9; row++) {
            for(int col=0; col<9; col++) {
                if(board[row][col] == '.') {
                    for(char ch='1'; ch<='9'; ch++) {
                        if(isValid(board, row, col, ch)) {
                            board[row][col] = ch;
                            if(solveSudokuUtil(board)) return true;
                            else board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuUtil(board);
    }
};
