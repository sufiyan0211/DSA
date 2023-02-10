int countPaths(int n, vector<vector<int>>& roads) 
{
    vector<vector<pair<int, int>>> adj(n);
    for(auto it: roads) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    
    vector<int> ways(n, 0), dist(n, INT_MAX);
    ways[0] = 1;
    dist[0] = 0;
    
    // {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0,0});
    int mod = (int) (1e9 + 7);
    
    while(!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it: adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;
            
            if(distance + edgeWeight < dist[adjNode]) {
                dist[adjNode] = distance + edgeWeight;
                ways[adjNode] = ways[node];
                pq.push({dist[adjNode], adjNode});
            }
            else if(distance + edgeWeight == dist[adjNode]) {
                ways[adjNode] = (ways[adjNode] + ways[node])% mod;
            }
        }
    }
    return ways[n-1];
}