class Solution {
  private:
    int timer = 1;
    void dfs(vector<int>adj[], vector<bool> &visited,vector<int> &timeOfInsertion, 
    vector<int> &minimumPossibleTime, vector<int> &mark, int node, int parent) {
        visited[node] = true;
        timeOfInsertion[node] = minimumPossibleTime[node] = timer;
        timer++;
        int child = 0;
        for(auto adjNode : adj[node]) {
            if(parent == adjNode) continue;
            if(visited[adjNode] == false) {
                dfs(adj, visited, timeOfInsertion, minimumPossibleTime, mark, adjNode, node);
                minimumPossibleTime[node] =  min(minimumPossibleTime[node], minimumPossibleTime[adjNode]);
                if(minimumPossibleTime[adjNode] >= timeOfInsertion[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                minimumPossibleTime[node] = min(minimumPossibleTime[node], timeOfInsertion[adjNode]);
            }
        }
        if(child > 1 && parent == -1){
            mark[node] = 1;
        }
    }
    
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<bool> visited(V, false);
        vector<int> timeOfInsertion(V), minimumPossibleTime(V);
        vector<int> mark(V, 0);
        
        for(int i=0;i<V;i++) {
            dfs(adj, visited, timeOfInsertion, minimumPossibleTime, mark, i, -1);
        }
        
        vector<int> ans;
        for(int i = 0;i<V;i++) {
            if(mark[i] == 1) {
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0) return {-1};
        return ans;
    }
};