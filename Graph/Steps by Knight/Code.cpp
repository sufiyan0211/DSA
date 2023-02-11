int minStepToReachTarget(vector<int>&source,vector<int>&dest,int n)
{	    
    vector<vector<int>> visited(n, vector<int> (n, 0));
    visited[source[0]-1][source[1]-1] = 1;
    
    // {distance, {r,c}}
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {source[0]-1, source[1]-1}});
    
    vector<pair<int, int>> dir = {{-1,2}, {-1, -2}, {1,-2}, {1,2}, 
                                    {-2,1}, {-2,-1}, {2,-1}, {2,1}};
    
    while(!q.empty()) {
        int distance = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        if(r == dest[0]-1 && c == dest[1]-1) return distance;
        
        for(auto it: dir) {
            int newR = r+it.first;
            int newC = c+it.second;
            if(newR >= 0 && newR < n && newC >=0 && newC < n && visited[newR][newC] == 0) {
                visited[newR][newC] = 1;
                if(newR == dest[0]-1 && newC == dest[1]-1) return distance+1;
                q.push({distance+1, {newR, newC}});
            }
        }
    }
    return -1;
}