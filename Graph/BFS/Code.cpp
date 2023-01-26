#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int>> &adj, int v, int u) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(vector<vector<int>> &adj, vector<int> &ans, int s, vector<bool> &visited) {
	ans.push_back(s);
	visited[s] = true;
	for(auto v: adj[s]) {
		if(visited[v] == false) {
			dfs(adj, ans, v, visited);
		}
	}
}


int main() {
	int v = 5;
	vector<vector<int>> adj(v);
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 0);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 0);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 2);
	addEdge(adj, 3, 1);
	addEdge(adj, 3, 4);

	addEdge(adj, 4, 1);
	addEdge(adj, 4, 3);

	vector<int> ans;
	vector<bool> visited(v, false);

	// undirected Graph
	// No Breaks
	for(int s=0;s<v;s++) {
		if(visited[s] == false) {
			dfs(adj, ans, s, visited);
		}
	}

	for(auto ele: ans) {
		cout << ele << " ";
	} cout << endl;
	


	return 0;
}