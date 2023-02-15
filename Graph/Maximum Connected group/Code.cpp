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
    bool isValid(int newRow, int newCol, int n, int m) {
        return newRow >=0 && newRow<n && newCol >=0 && newCol<m;
    }
    
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        DisjointSet ds(n*m);
        
        for(int row=0;row<n;row++) {
            for(int col=0;col<m;col++) {
                if(grid[row][col] == 1) {
                    // row+1, col
                    // row, col+1
                    // row-1, col
                    // row, col-1
                    int dr[] = {1, 0, -1, 0};
                    int dc[] = {0, 1, 0, -1};
                    for(int k = 0;k<4;k++) {
                        int newRow = row+dr[k];
                        int newCol = col+dc[k];
                        
                        int nodeNo = row*m + col;
                        int adjNodeNo = newRow*m + newCol;
                        
                        if(isValid(newRow, newCol, n, m) && grid[newRow][newCol] == 1) {
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for(int row=0;row<n;row++) {
            for(int col=0;col<m;col++) {
                if(grid[row][col] == 0) {
                    // row+1, col
                    // row, col+1
                    // row-1, col
                    // row, col-1
                    int dr[] = {1, 0, -1, 0};
                    int dc[] = {0, 1, 0, -1};
                    
                    unordered_set<int> s;
                    for(int k = 0;k<4;k++) {
                        int newRow = row+dr[k];
                        int newCol = col+dc[k];
                        
                        int nodeNo = row*m + col;
                        int adjNodeNo = newRow*m + newCol;
                        
                        if(isValid(newRow, newCol, n, m)) {
                            if(grid[newRow][newCol] == 1) {
                                s.insert(ds.ultimateParent(adjNodeNo));
                            }
                        }
                    }
                    int count = 1;
                    for(auto it: s) {
                        count += ds.size[it];
                    }
                    ans = max(ans, count);
                }
            }
        }
        for (int i = 0; i < n * m; i++) {
            ans = max(ans, ds.size[ds.ultimateParent(i)]);
        }
        return ans;
    }
};