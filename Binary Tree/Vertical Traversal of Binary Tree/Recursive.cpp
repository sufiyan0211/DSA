class Solution {
  public:
  
    void traverse(Node *root, int pos, map<int, vector<Node *>> &nodeMap) {
        if(root == NULL) return;
        nodeMap[pos].push_back(root);
        traverse(root->left, pos-1, nodeMap);
        traverse(root->right, pos+1, nodeMap);
    }
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        map<int, vector<Node *>> nodeMap;
        traverse(root, 0, nodeMap);
        
        for(auto entry: nodeMap) {
            vector<int> level;
            for (auto node: entry.second) {
                level.push_back(node->data);
            }
            ans.push_back(level);
        }
       return ans; 
    }
};