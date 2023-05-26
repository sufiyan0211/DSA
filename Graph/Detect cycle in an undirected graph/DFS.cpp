#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int>> &adj, int v, int u) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool dfs(vector<vector<int>> &adj, vector<bool> &visited, int src, int parent) {
	
	visited[src] = true;

	for(auto v: adj[src]) {
		if(visited[v] == false) {
			bool isCyclePresent = dfs(adj, visited, v, src);
			if(isCyclePresent) return true;
		}
		else if(v != parent) { // means if 'v' is visited but 'v' is not the parent of src
			return true;
		}
	}
	return false;
}

bool isCycleDetect(vector<vector<int>> &adj, vector<bool> &visited, int src) {
	return dfs(adj, visited, src, -1);
}


int main() {
	int v = 4;
	vector<vector<int>> adj(v);
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);

	addEdge(adj, 1, 0);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);

	addEdge(adj, 2, 0);
	addEdge(adj, 2, 1);
	addEdge(adj, 2, 3);

	addEdge(adj, 3, 1);
	addEdge(adj, 3, 2);

	vector<bool> visited(v, false);

	// undirected Graph
	// No Breaks
	bool ans = false;
	for(int s=0;s<v;s++) {
		if(visited[s] == false) {
			ans = isCycleDetect(adj, visited, s);
			if(ans == true) {
				cout << "Cycle Detected\n";
			}
		}
	}

	if(ans == false) {
		cout << "Cycle not Detected\n";
	}


	return 0;
}
