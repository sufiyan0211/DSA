#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int v, int u) {
    adj[v].push_back(u);
}



bool dfs(vector<int> adj[], vector<bool> &visited, vector<bool> &recStack, int src, int parent) {
    visited[src] = true;
    recStack[src] = true;
    for(auto v: adj[src]) {
        if(visited[v] == false) {
            if(dfs(adj, visited, recStack, v, src) == true) return true;
        }
        else if(recStack[v] == true) {
            return true;
        }
    }
    
    recStack[src] = false;
    return false;
}
bool isCyclic(int v, vector<int> adj[]) {
    // code here
    vector<bool> visited(v, false);
    // recursion stack
    vector<bool> recStack(v, false);
    
    for(int i=0;i<v;i++) {
        if(visited[i] == false) {
            if(dfs(adj, visited, recStack, i, -1) ) return true;
        }
    }
    return false; 
}


int main() {
    int v = 4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 1);
    addEdge(adj, 3, 2);
    addEdge(adj, 3, 4);
        

    // undirected Graph
    // No Breaks

    bool ans = isCyclic(v, adj);
    if(ans == true) {
        cout << "Cycle Detected\n";
    }
    else {
        cout << "Cycle not Detected\n";
    }


    return 0;
}