class DisjointSet{
    vector<int> size, parent;
    public:
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int ultimateParent(int u) {
        if(u == parent[u]) {
            return u;
        }
        return parent[u] = ultimateParent(parent[u]);
    }
    
    void unionBySize(int u, int v) {
        int ultimateParentOfU = ultimateParent(u);
        int ultimateParentOfV = ultimateParent(v);
        
        if(ultimateParentOfU == ultimateParentOfV) return;
        
        if(size[ultimateParentOfU] < size[ultimateParentOfV]) {
            parent[ultimateParentOfU] = ultimateParentOfV;
            size[ultimateParentOfV] += ultimateParentOfU;
        }
        else {
            parent[ultimateParentOfV] = ultimateParentOfU;
            size[ultimateParentOfU] += size[ultimateParentOfV];
        }
    }
    
};


int numProvinces(vector<vector<int>> adj, int V) {
    DisjointSet ds(V);
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            if(adj[i][j] != 0) {
                ds.unionBySize(i,j);
            }
        }
    }
    
    int count = 0;
    for(int i=0;i<V;i++) {
        if(ds.ultimateParent(i) == i) {
            count++;
        }
    }
    
    return count;
}