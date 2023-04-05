class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int rows = image.size();
        int cols = image[0].size();
        // {x,y}
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int oldColor = image[sr][sc];
        image[sr][sc] = color;

        vector<pair<int, int>> direction = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto it: direction) {
                int newX = x+it.first;
                int newY = y+it.second;
                if(newX >= 0 && newX < rows && newY >=0 && newY < cols &&
                   image[newX][newY] == oldColor) {
                    q.push({newX, newY});
                    image[newX][newY] = color;
                }
            }
        }
        return image;
    }
};