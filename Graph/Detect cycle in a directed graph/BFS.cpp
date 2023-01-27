#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int v, int u) {
    adj[v].push_back(u);
}


bool bfs(vector<int> adj[], int v) {
    // Finding Indegrees
    vector<int> indegrees(v, 0);
    for(int i=0;i<v;i++) {
        for(auto x: adj[i]) {
            indegrees[x]++;
        }
    }
    
    // enqueue all the zero degree nodes into queue
    queue<int> q;
    for(int i=0;i<v;i++) {
        if(indegrees[i] == 0) {
            q.push(i);
        }
    }
    
    // counting nodes
    int count = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto i: adj[u]) {
            indegrees[i]--;
            if(indegrees[i] == 0) {
                q.push(i);
            }
        }
        count++;
    }
    return (count != v);
}

bool isCyclic(int v, vector<int> adj[]) {
    // code here
    return bfs(adj, v);
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


