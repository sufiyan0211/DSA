vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dis(V, INT_MAX);
    dis[S] = 0;
    
    // MinHeap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    
    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it: adj[node]) {
            int edgeWeight = it[1];
            int adjNode = it[0];
            
            if(weight + edgeWeight < dis[adjNode]) {
                 dis[adjNode] = weight + edgeWeight; 
                 pq.push({dis[adjNode], adjNode});
            }
        }
    }
    return dis;
}