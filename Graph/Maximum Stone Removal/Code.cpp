class DisjointSet {
public: 
    vector<int> size, parent;
    
    DisjointSet(int n) {
      size.resize(n+1, 1);
      parent.resize(n+1);
      for(int i=0;i<=n;i++) {
          parent[i] = i;
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


class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxRow = 0;
        int maxCol = 0;
        for(auto it: stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow+maxCol+1);
        unordered_map<int, int> stoneNodes;
        
        for(auto it: stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        
        int count = 0;
        for(auto it: stoneNodes) {
            if(it.first == ds.ultimateParent(it.first)) {
                count++;
            }
        }
        return n-count;
    }
};