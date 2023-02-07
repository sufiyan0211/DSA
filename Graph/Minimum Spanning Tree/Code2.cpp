int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>vis(V);
    
    pq.push({0,0});
    vector<vector<int>>mst;
    int sum = 0;
    
    // O(E)
    while(!pq.empty()) {

        // O(log E)
        auto p = pq.top();
        pq.pop();
        int wt = p.first, node = p.second;
        
        if(vis[node]) // if already visited;
            continue;
        
        vis[node] = 1;
        sum += wt;
        
        // O(E log E)
        for(auto i: adj[node]) {
            int v = i[0], eWt = i[1];
            if(!vis[v]) {
                pq.push({eWt, v});
            }
        }
    }
    return sum;
}

// TC: E^2 log(E)