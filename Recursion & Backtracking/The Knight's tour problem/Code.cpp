class Solution {
  public:
  
    bool isValidMove(int newX, int newY, int n, 
    vector<vector<int>> &board) {
        
        if(newX >= 0 && newX < n && newY >= 0 && newY < n && board[newX][newY] == -1) 
            return true;
            
        return false;
    }
  
    bool isValidBoard(int row, int col, int step, 
    vector<pair<int, int>> &directions, 
    int n, vector<vector<int>> &board) {
        
        if(step == n*n) {
            return true;
        }
        
        // logic
        for (auto &direction: directions) {
            int dx = direction.first;
            int dy = direction.second;
            int newX = row+dx;
            int newY = col+dy;
            
            if(isValidMove(newX, newY, n, board)) {
                board[newX][newY] = step;
                if(isValidBoard(newX, newY, step+1, directions, n, board)) return true;
                board[newX][newY] = -1;
            }
        }
        return false; // all directions completed but still not received total steps
    }
    
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>> board(n, vector<int>(n, -1));
        
        vector<pair<int, int>> directions = {
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
        };
        
        board[0][0] = 0;
        if(isValidBoard(0, 0, 1, directions, n, board)) return board;
        
        board.clear();
        return board;
    }
};