class Solution {
public:
    int n;
    
    pair<int, int> getCoord(int num) {
        int rowFromTop = (num-1)/n;
        int rowFromBottom = (n-1) - rowFromTop;

        int col = (num-1)%n;

        if((n%2 == 1 && rowFromBottom%2 == 1) || (n%2 == 0 && rowFromBottom%2 == 0)) {
            col = (n-1) - col;
        }
        return make_pair(rowFromBottom, col);
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        
        int steps = 0;
        queue<int> que;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n-1][0] = true;
        
        que.push(1);
        vector<bool> seen(n*n+1,false);
        
        
        while(!que.empty()) {
            
            int N = que.size();
            while(N--) {
            
                int x = que.front();
                que.pop();

                if(x == n*n)
                    return steps;

                for(int k = 1; k<=6; k++) {
                    if(x+k > n*n)
                        break;

                    pair<int, int> coord = getCoord(x+k);
                    int r = coord.first;
                    int c = coord.second;
                    if(visited[r][c] == true)
                        continue;

                    visited[r][c] = true;
                    if(board[r][c] == -1)
                        que.push(k+x);
                    else {
                        que.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};