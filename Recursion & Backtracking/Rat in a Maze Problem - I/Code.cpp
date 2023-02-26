class Solution{
    public:
    void solve(vector<vector<int>> &matrix, int x, int y, vector<string> &ans, 
        string move, vector<vector<int>> visited, int n,
        vector<pair<char,pair<int, int>>> &dir
        ) {
        if(x == n-1 && y == n-1) {
            ans.push_back(move);
            return;
        }
        
        for(int i=0;i<4;i++) {
            char c = dir[i].first;
            int dx = dir[i].second.first;
            int dy = dir[i].second.second;
            int newX = x+dx;
            int newY = y+dy;
            if(newX>=0 && newX<n && newY>=0 && newY<n && visited[newX][newY] == 0 && matrix[newX][newY] == 1) {
                visited[x][y] = 1;
                solve(matrix, newX, newY, ans, move+c, visited, n, dir);
                visited[x][y] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &matrix, int n) {
        // Your code goes here
        vector<vector<int>> visited(n,vector<int> (n,0));
        vector<pair<char,pair<int, int>>> dir = {{'D',{1,0}}, {'L',{0,-1}}, {'R',{0, 1}}, 
        {'U',{-1,0}} };
        vector<string> ans;
        if(matrix[0][0]) solve(matrix, 0,0, ans, "", visited, n, dir);
        return ans;
    }
};