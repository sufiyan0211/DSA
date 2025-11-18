class Solution
{
public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root == NULL) return ans;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        map<int, vector<int>> nodes;
        while(!q.empty()) {
            Node *curr = q.front().first;
            int hd = q.front().second;
            q.pop();
            nodes[hd].push_back(curr->data);
            if(curr->left) {
                q.push(make_pair(curr->left, hd-1));
            }
            if(curr->right) {
                q.push(make_pair(curr->right, hd+1));
            }
        }

        for(auto s: nodes) {
            for(auto p : s.second) {
                ans.push_back(p);
            }
        }
        return ans;
    }
};
