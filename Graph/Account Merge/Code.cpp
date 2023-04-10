class DisjoinSet{
    vector<int> size, parent;
    public:
    
    DisjoinSet(int n) {
        size.resize(n+1);
        parent.resize(n+1);
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
            size[ultimateParentOfV] += size[ultimateParentOfU];
        }
        else {
            parent[ultimateParentOfV] = ultimateParentOfU;
            size[ultimateParentOfU] += size[ultimateParentOfV];
        }
    }
  
};


vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int n = accounts.size();
    DisjoinSet ds(n);
    unordered_map<string, int> mapMailNode;
    
    // mapping mails<String> to nodes<int> and if the there is repeating mail found 
    // Then add it Disjoint set (connect current node 'i' to its already present node 'mapMailNode[mail]')
    for(int i=0;i<n;i++) {
        for(int j = 1;j<accounts[i].size();j++) {
            string mail = accounts[i][j];
            if(mapMailNode.find(mail) == mapMailNode.end()) {
                mapMailNode[mail] = i;
            }
            else{
                ds.unionBySize(mapMailNode[mail], i);
            }
        }
    }
    
    
    // merging the mails based on their ultimate parent
    vector<string> mergeMail[n];
    for(auto it: mapMailNode) {
        string mail = it.first;
        int node = ds.ultimateParent(it.second);
        mergeMail[node].push_back(mail);
    }
    
    vector<vector<string>> ans;
    for(int i=0;i<n;i++) {
        if(mergeMail[i].size() == 0) continue;
        sort(mergeMail[i].begin(), mergeMail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it: mergeMail[i]) {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
