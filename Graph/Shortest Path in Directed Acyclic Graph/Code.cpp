#include <bits/stdc++.h>
using namespace std;


void dfs(int u, stack<int> &st, vector<vector<pair<int, int>>> &adj, 
vector<bool> &visited) {
    visited[u] = true;
    for(auto v: adj[u]) {
        int adjNode = v.first;
        if(visited[adjNode] == false) 
            dfs(adjNode, st, adj, visited);
    }
    st.push(u);
}
    
 vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    // code here

    // create Weightd graph from edges
    // Space Complexity O(N*M) & Time complexity O(M)
    vector<vector<pair<int, int>>> adj(N);
    for(int i=0;i<M;i++) {
        int node = edges[i][0];
        int adjNode = edges[i][1];
        int weight = edges[i][2];
        adj[node].push_back({adjNode, weight});
    }

    stack<int> st;
    vector<bool> visited(N, false);

    for(int i=0;i<N;i++) {
        if(visited[i] == false) {
            dfs(i, st, adj, visited);
        }
    }


    vector<int> dist(N, 1e8);
    dist[0] = 0;

    while(!st.empty()) {
        int node = st.top();
        st.pop();
        for(auto v: adj[node]) {
            int adjNode = v.first;
            int weight = v.second;
            if(dist[adjNode] > dist[node]+weight) {
                dist[adjNode] = dist[node]+weight;
            }
        }
    }

    for(int i=0;i<N;i++) {
        if(dist[i] == 1e8) {
            dist[i] = -1;
        }
    }
    return dist;
}


int main() {
    int N=6, M=7;
    vector<vector<int>> edges = {{0,1,2},{0,4,1},{4,5,4}
            ,{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
  

     vector<int> ans = shortestPath(N, M, edges);
     for(auto ele: ans) {
        cout << ele << " ";
     } cout << endl;

    return 0;
}
