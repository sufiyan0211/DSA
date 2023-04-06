#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> adj, int n) {
    vector<int> indegree(n);

    for(int i=0;i<n;i++) {
        for(auto it: adj[i]) {
            indegree[it]++;
        }
    }

    vector<bool> visited(n, false);
    queue<int> q;
    for(int i=0;i<n;i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto adjNode : adj[node]) {
            indegree[adjNode]--;
            if(indegree[adjNode] == 0) {
                q.push(adjNode);
            }
        }
    }
    return ans;
}