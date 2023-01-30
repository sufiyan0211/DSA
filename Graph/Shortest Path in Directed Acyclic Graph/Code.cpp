#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int>> &adj, int v, int u) {
    adj[v].push_back(u);
}



void dfs(vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s, int i) {
    visited[i] = true;
    
    for(int u: adj[i]) {
        if(visited[u] == false){
            dfs(adj, visited, s, u);
        }
    }
    
    s.push(i);
}

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
    map<pair<int, int>, int> weight;
    vector<vector<int>> adj(N);
    
    
    for(int i=0;i<M;i++) {
        weight[make_pair(edges[i][0],edges[i][1])] = edges[i][2];
        addEdge(adj, edges[i][0], edges[i][1]);
    }
    
    
    vector<bool> visited(N, false);
    stack<int> s;
    
    
    for(int i=0;i<N;i++) {
        if(visited[i] == false) {
            dfs(adj, visited, s, i);
        }
    }
    
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;
    
    while(!s.empty()) {
        int u = s.top();
        s.pop();
        
        if(dist[u] == INT_MAX) continue;
        
        for(int v: adj[u]) {
            if(dist[v] > dist[u]+weight[make_pair(u,v)]){
                dist[v] = dist[u]+weight[make_pair(u,v)];
            }
        }
    }
    
    for(int i=0;i<N;i++) {
        if(dist[i] == INT_MAX) {
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