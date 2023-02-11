int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) 
{
    int rows = grid.size();
    int cols = grid[0].size();
    
    vector<vector<int>> dist(rows, vector<int> (cols, 1e9));
    dist[source.first][source.second] = 0;
    
    // {distance, {row, col}}
    queue<pair<int, pair<int, int>>> q;
    q.push({0, source});
    
    while(!q.empty()) {
       int distance = q.front().first;
       int x = q.front().second.first;
       int y = q.front().second.second;
       q.pop();
       
       if (x == destination.first && y == destination.second) return distance;
       
       // go left
       if(y-1 >= 0 && grid[x][y-1] == 1) {
           if(distance+1 < dist[x][y-1]) {
               dist[x][y-1] = distance+1;
              if (x == destination.first && y-1 == destination.second) return distance+1;
               q.push({dist[x][y-1], {x, y-1}});
           }
       }
       // go right
       if(y+1 < cols && grid[x][y+1] == 1) {
           if(distance+1 < dist[x][y+1]) {
               dist[x][y+1] = distance+1;
              if (x == destination.first && y+1 == destination.second) return distance+1;
               q.push({dist[x][y+1], {x, y+1}});
           }
       }
       
       // go up
       if(x-1 >= 0 && grid[x-1][y] == 1) {
           if(distance+1 < dist[x-1][y]) {
               dist[x-1][y] = distance+1;
              if (x-1 == destination.first && y == destination.second) return distance+1;
               q.push({dist[x-1][y], {x-1, y}});
           }
       }
       
       // go down
       if(x+1 < rows && grid[x+1][y] == 1) {
           if(distance+1 < dist[x+1][y]) {
               dist[x+1][y] = distance+1;
              if (x+1 == destination.first && y == destination.second) return distance+1;
               q.push({dist[x+1][y], {x+1, y}});
           }
       }
    }
    
    if(dist[destination.first][destination.second] == 1e9) return -1;
    return dist[destination.first][destination.second];
}