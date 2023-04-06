#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, stack<int> &st, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    for(auto adjNode : adj[node]) {
        if(visited[adjNode] == false) {
            dfs(node, st, adj, visited);
        }
    }
    st.push(node);

}

vector<int> topologicalSort(vector<vector<int>> adj, int n) {
    stack<int> st;
    vector<bool> visited(n, false);
    for(int i=0;i<n;i++) {
        if(visited[i] == false) {
            dfs(i, st, adj, visited);
        }
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}