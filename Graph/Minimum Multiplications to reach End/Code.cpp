int minimumMultiplications(vector<int>& arr, int start, int end) 
{    
    // {steps, nums}
    queue<pair<int, int>> q;
    q.push({0, start});
    vector<int> dist(100000, INT_MAX);
    dist[start] = 0;
    
    while(!q.empty()) {
        int steps = q.front().first;
        int node = q.front().second;
        q.pop();
        
        for(auto it: arr) {
            int num = (it*node)%100000;
            if(steps+1 < dist[num]) {
                dist[num] = steps+1;
                if(num == end) {
                    return steps+1;
                }
                q.push({steps+1, num});
            }
        }
    }
    return -1;
}