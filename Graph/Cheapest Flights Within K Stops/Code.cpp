 int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  
 {
    vector<vector<pair<int, int>>> adj(n);
    for(auto it: flights) {
        adj[it[0]].push_back({it[1], it[2]});
    }
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    // {stops, {node, distance}}
    queue<pair<int, pair<int, int>>> q;
    
    q.push({0,{src, 0}});
    
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        
        int stops = it.first;
        int node = it.second.first;
        int distance = it.second.second;
        
        if(stops > K) continue;
        
        for(auto iter: adj[node]) {
            int adjNode = iter.first;
            int edgeWeight = iter.second;
            
            if(distance + edgeWeight < dist[adjNode] && stops <= k) {
                dist[adjNode] = distance + edgeWeight;
                q.push({stops+1, {adjNode, dist[adjNode]}});
            }
        }
    }
    
    if(dist[dst] == 1e9) return -1;
    return dist[dst];
}