class Solution {
private:
    int oppColor(int c) {
        return c==0 ? 1 : 0;
    }
    bool bfs(vector<int>adj[], vector<int> &color, int node) {
        color[node] = 0;
        queue<int> q;
        q.push(node);
        while(!q.empty()) {
            node = q.front();
            q.pop();
            for(auto adjNode: adj[node]) {
                if(color[adjNode] == -1) {
                    color[adjNode] = oppColor(color[node]);
                    q.push(adjNode);
                }
                else {
                    if(color[node] == color[adjNode]) return false;
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V, -1);
	    // -1 --> Not yet colored
	    // 0 --> color One
	    // 1 --> color Two
	    
	    for(int i=0;i<V;i++) {
	        if(color[i] == -1) {
	            bool ans = bfs(adj, color, i);
	            if(ans == false) return false;
	        }
	    }
	    return true;
	}

};