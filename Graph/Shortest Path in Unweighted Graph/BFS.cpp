#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:

    void addEdge(vector<vector<int>> &adj, int node, int adjNode) {
        adj[node].push_back(adjNode);
        adj[adjNode].push_back(node);
    }

    void bfs(vector<vector<int>> &adj, int src, vector<int> &dist, vector<bool> &visited) {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        dist[src] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto adjNode: adj[node]) {
                if(!visited[adjNode]) {
                    dist[adjNode] = dist[node] + 1;
                    visited[adjNode] = true;
                    q.push(adjNode);
                }
            }
        }

        for(auto &ele: dist) {
            if(ele ==  1e8) {
                ele = -1;
            }
        }

    }


public:

    vector<int> shortestPath(vector<vector<int>>& edges, int vertices,
                             int edgesCount, int src){
        // code here
        vector<vector<int>> adj(vertices);
        for(auto edge: edges) {
            int node = edge[0];
            int adjNode = edge[1];
            addEdge(adj, node, adjNode);
        }
        vector<int> dist(vertices, 1e8);
        vector<bool> visited(vertices, false);

        bfs(adj, src, dist, visited);
        return dist;
    }
};