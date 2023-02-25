class Solution { 
private:
    bool isSafe(int currRow, int currCol, vector<vector<int>> &board, int n) {
        int dupRow = currRow;
        int dupCol = currCol;
        
        while(currCol >=0) {
            if(board[currRow][currCol] == 1) return false;
            currCol--;
        }
        
        currCol = dupCol;
        while(currRow >=0 && currCol >= 0) {
            if(board[currRow][currCol] == 1) return false;
            currRow--;
            currCol--;
        }
        
        currRow = dupRow;
        currCol = dupCol;
        while(currRow < n && currCol >= 0) {
            if(board[currRow][currCol] == 1) return false;
            currRow++;
            currCol--;
        }
        return true;
    }

    void backtrack(int currCol, vector<vector<int>> &board, 
    int n, vector<vector<int>> &ans, vector<int> vi) {
        
        if(currCol == n) {
            ans.push_back(vi);
            return;
        }
        
        
        for(int currRow = 0; currRow<n; currRow++) {
            if(isSafe(currRow, currCol, board, n))
            {
                board[currRow][currCol] = 1;
                vi[currCol] = currRow+1;
                backtrack(currCol+1, board, n, ans, vi);
                board[currRow][currCol] = 0;
            }
        }
        
        
    }
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n, vector<int> (n, 0));
        vector<vector<int>> ans;
        vector<int> vi(n);
        backtrack(0, board, n, ans, vi);
        return ans;
    }
};