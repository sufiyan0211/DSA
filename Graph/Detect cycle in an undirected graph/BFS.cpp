#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int>> &adj, int v, int u) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool bfs(vector<vector<int>> &adj, vector<bool> &visited, int src) {
	
	visited[src] = true;
	queue<int> q;
	q.push(src);
	unordered_map<int, int> parent;

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(auto v: adj[u]) {
			if(visited[v] == false) {
				q.push(v);
				visited[v] = true;
				parent[v] = u;
			}
			else if(parent[u] != v) {
				return true;
			}
		}
		
	}

	return false;
}

bool isCycleDetect(vector<vector<int>> &adj, vector<bool> &visited, int src) {
	return bfs(adj, visited, src);
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