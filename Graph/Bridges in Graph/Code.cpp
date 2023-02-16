class Solution {
private:
    int timer = 1;
    void DFS(vector<vector<int>> &adj, vector<bool> &visited,
    int parent,int node,vector<int> &timeOfInsertion,vector<int> &lowestPossibleTime, 
    vector<vector<int>> &bridges) {
        visited[node] = true;
        timeOfInsertion[node] = lowestPossibleTime[node] = timer;
        timer++;

        for(auto adjNode : adj[node]) {
            if(adjNode == parent) continue;
            if(visited[adjNode] == false) {
                DFS(adj, visited, node, adjNode, timeOfInsertion, lowestPossibleTime, bridges);
                lowestPossibleTime[node] =  min(lowestPossibleTime[adjNode], lowestPossibleTime[node]);
                if(lowestPossibleTime[adjNode] > timeOfInsertion[node]) {
                    bridges.push_back({node, adjNode});
                }
            }
            else {
                lowestPossibleTime[node] = min(lowestPossibleTime[adjNode], lowestPossibleTime[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // step1: created Graph adjacency List
        vector<vector<int>> adj(n);
        
        for(auto it: connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        // Step2: Do a DFS traversal
        vector<bool> visited(n, false);
        vector<vector<int>> bridges;
        vector<int> timeOfInsertion(n), lowestPossibleTime(n);
        DFS(adj, visited, -1, 0, timeOfInsertion, lowestPossibleTime, bridges);
        return bridges;
    }
};