class DisjointSet {
    vector<int> size, parent;
    public:
    // contructor
    DisjointSet(int n) {
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // fun to find ultimate parent
    int ultimateParent(int u) {
        if(parent[u] == u) {
            return u;
        }
        
        return parent[u] = ultimateParent(parent[u]);
    }
    
    // union by size
    void unionBySize(int u, int v) {
        int ultimateParentOfU = ultimateParent(u);
        int ultimateParentOfV = ultimateParent(v);
        if (ultimateParentOfU == ultimateParentOfV) return;
        
        if(size[ultimateParentOfU] <= size[ultimateParentOfV]) {
            parent[ultimateParentOfU] = ultimateParentOfV;
            size[ultimateParentOfV] += size[ultimateParentOfU];
        }
        else if(size[ultimateParentOfV] < size[ultimateParentOfU]) {
            parent[ultimateParentOfV] = ultimateParentOfU;
            size[ultimateParentOfU] += size[ultimateParentOfV];
        }
    }
};


int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<pair<int, pair<int, int>>> edges;
    for(int i=0;i<V;i++) {
        for(auto it: adj[i]) {
            int adjNode = it[0];
            int weight = it[1];
            int node = i;
            edges.push_back({weight, {node, adjNode}});
        }
    }
    // Step1: sort edges
    sort(edges.begin(), edges.end());

    // Step2: Make Disjoint set
    DisjointSet ds(V);
    int mst_w = 0;
    
    for(auto it: edges) {
        int weight = it.first;
        int u = it.second.first;
        int v = it.second.second;
        
        if(ds.ultimateParent(u) != ds.ultimateParent(v)) {
            mst_w += weight;
            ds.unionBySize(u, v);
        }
    }
    return mst_w;
}