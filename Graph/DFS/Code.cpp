#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int>> &adj, int v, int u) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void bfs(vector<vector<int>> &adj, vector<int> &ans, int s, vector<bool> &visited) {
	
	visited[s] = true;

	queue<int> q;
	q.push(s);

	while(!q.empty()) {
		int u = q.front();
		ans.push_back(u);
		q.pop();

		for(auto v: adj[u]) {
			if(visited[v] == false) {
				q.push(v);
				visited[v] = true;
			}
		}
	}
	
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


	vector<int> ans;
	vector<bool> visited(v, false);

	// undirected Graph
	// May be Disconnected
	for(int s=0;s<v;s++) {
		if(visited[s] == false) {
			bfs(adj, ans, s, visited);
		}
	}

	for(auto ele: ans) {
		cout << ele << " ";
	} cout << endl;
	


	return 0;
}