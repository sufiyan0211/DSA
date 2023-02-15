class Solution
{
private:
    void topologicalSort(vector<vector<int>>& adj, vector<bool> &visited, 
    stack<int> &st, int V, int i) {
        visited[i] = true;
        for(auto adjNode: adj[i]) {
            if(visited[adjNode] == false) {
                topologicalSort(adj, visited, st, V, adjNode);
            }
        }
        st.push(i);
    }
    
    void DFS(vector<vector<int>>& adjT,vector<bool> &visited, int i) {
        visited[i] = true;
        for(auto it: adjT[i]) {
            if(visited[it] == false) {
                DFS(adjT, visited, it);
            }
        }
    }
    
public:
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // step 1: find topological sort
        stack<int> st;
        vector<bool> visited(V, false);
        for(int i=0;i<V;i++) {
            if(visited[i] == false) {
                topologicalSort(adj, visited, st, V, i);
            }
        }
        
        // step 2: reverse every edge of Graph
        vector<vector<int>> adjT(V);
        for(int i=0;i<V;i++) {
            visited[i] = false;
            for(auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }
        
        // step3: count the calls of DFS 
        int scc = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            if(visited[node] == true) continue;
            if(visited[node] == false) {
                scc++;
                DFS(adjT, visited, node);
            }
        }
        
        return scc;
    }
};