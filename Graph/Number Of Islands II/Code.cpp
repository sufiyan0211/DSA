class DisjointSet{
    vector<int> size, parent;
    public:
    
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
        return newRow < n && newRow >= 0 && newCol < m && newCol >= 0;
    }
    
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> visited(n, vector<int> (m, 0));
        
        int count = 0;
        vector<int> ans;
        for(auto it: operators) {
            int row = it[0];
            int col = it[1];
            if(visited[row][col] == 1) {
                ans.push_back(count);
                continue;
            }
            count++;
            visited[row][col] = 1;
            // row - 1, col
            // row , col + 1
            // row + 1, col
            // row, col - 1;
            int dr[] = { -1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for(int i=0;i<4;i++) {
                int newRow = row+dr[i];
                int newCol = col+dc[i];
                int node = row*m + col;
                int adjNode = newRow*m + newCol;
                
                if(isValid(newRow, newCol, n, m)) {
                    if(visited[newRow][newCol] == 1) {
                        if(ds.ultimateParent(node) != ds.ultimateParent(adjNode)) {
                            count--;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};