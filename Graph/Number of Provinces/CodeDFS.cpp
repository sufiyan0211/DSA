void DFS(vector<vector<int>> &adjList, int V, vector<bool> &visited, int i) {
    // create queue for BFS Traversal
    visited[i] = true;
    for(auto it: adjList[i]) {
        int adjNode = it;
        if(visited[adjNode] == false) {
            DFS(adjList, V, visited, adjNode);
        }
    }

}


int numProvinces(vector<vector<int>> adj, int V) {
    vector<bool> visited(V, false);
    // create Adj list
    vector<vector<int>> adjList(V);
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            if(adj[i][j] != 0) {
                adjList[i].push_back(j);
            }
        }
    }
    
    int count = 0;
    for(int i=0; i<V;i++) {
        if(visited[i] == false) {
            count++;
            DFS(adjList, V, visited, i);
        }
    }
    
    return count;
}