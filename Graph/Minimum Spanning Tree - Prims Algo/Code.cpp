#include <bits/stdc++.h>
using namespace std;


int primsAlgo(int v, int e, vector<vector<int>> &edges) {
    vector<vector<int>> adj(v);
    // <<u,v>,w>
    map<pair<int, int>, int> weights;


    for(int i=0;i<e;i++) {
        int u = edges[i][0];
        int vv = edges[i][1];
        int w = edges[i][2];

        weights[{u,vv}] = w;
        weights[{vv,u}] = w;

        adj[u].push_back(vv);
        adj[vv].push_back(u);
    }


    vector<int> key(v, INT_MAX);
    vector<bool> mst(v, false);
    key[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    minHeap.push({0,0});

    while(!minHeap.empty()) {
        auto top = minHeap.top();
        minHeap.pop();
        int node = top.second;
        mst[node] = true;


        for(auto nextNode: adj[node]) {
            int w = weights[{node, nextNode}];

            if(mst[nextNode] == false) {
                if(w < key[nextNode]) {
                    key[nextNode] = w;
                    minHeap.push({w, nextNode});
                }
            }

        }
    }
    int cost = 0;
    for(int i=0;i<v;i++) {
        cost += key[i];
    }
    return cost;
}


int main() {
    int v=3, e=3;
    vector<vector<int>> edges = {{0,1,5},{0,2,1},{1,2,3}};
  

     int cost = primsAlgo(v, e, edges);
     cout << cost << endl;

    return 0;
}