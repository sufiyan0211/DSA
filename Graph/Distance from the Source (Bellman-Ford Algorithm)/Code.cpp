vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) 
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    // (n-1) relax operation on each edge (Stated by Bellman Ford Algo)
    for(int i=0;i<V-1;i++) {
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int edgeWeight = it[2];
            
            if(dist[u] != 1e8 && dist[u] + edgeWeight < dist[v]) {
                dist[v] = dist[u] + edgeWeight;
            }
        }
    }
    
    // if negative cycle occurs then after nth relax opperation of any edge will reduce the cost 
    for(auto it: edges) {
        int u = it[0];
        int v = it[1];
        int edgeWeight = it[2];
        
        if(dist[u] != 1e8 && dist[u] + edgeWeight < dist[v]) {
            return {-1};
        }
    }
    return dist;
}