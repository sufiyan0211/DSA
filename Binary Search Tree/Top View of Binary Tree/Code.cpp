class Solution
{
public:
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL) return ans;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        map<int, int> nodes;
        while(!q.empty()) {
            Node *curr = q.front().first;
            int hd = q.front().second;
            q.pop();
            if(nodes.count(hd) == 0) {
                nodes[hd] = curr->data;
            }
            if(curr->left) {
                q.push(make_pair(curr->left, hd-1));
            }
            if(curr->right) {
                q.push(make_pair(curr->right, hd+1));
            }
        }
        for(auto s: nodes) {
            ans.push_back(s.second);
        }
        return ans;
    }
};