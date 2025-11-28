class Solution {
  public:

    void ratInMaze(int x, int y, int n, string moves,
        vector<pair<string, pair<int, int>>> &directions, 
        vector<vector<int>>& maze, 
        vector<string> &ans) {

        // Base Case: Reached destination
        if (x == n-1 && y == n-1) {
            ans.push_back(moves);
            return;
        }

        // Explore all 4 directions
        for (auto &direction : directions) {
            string nextMove = direction.first;
            int dx = direction.second.first;
            int dy = direction.second.second;

            int newX = x + dx;
            int newY = y + dy;

            // Check validity
            if (newX >= 0 && newX < n && newY >= 0 && newY < n && maze[newX][newY] == 1) {
                maze[newX][newY] = 0; // mark visited
                ratInMaze(newX, newY, n, moves + nextMove, directions, maze, ans);
                maze[newX][newY] = 1; // backtrack
            }
        }
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;

        // If start or end is blocked → no path
        if (maze[0][0] == 0 || maze[n-1][n-1] == 0)
            return ans;

        // Lexicographical order of moves: D L R U
        vector<pair<string, pair<int, int>>> directions = {
            {"D", {1, 0}},
            {"L", {0, -1}},
            {"R", {0, 1}},
            {"U", {-1, 0}}
        };

        // Mark starting cell as visited
        maze[0][0] = 0;

        ratInMaze(0, 0, n, "", directions, maze, ans);
        return ans;
    }
};
