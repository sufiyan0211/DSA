class Solution {
  public:
  
    bool findPath(Node *root, int key, vector<Node *> &path) {
        if (root == NULL) return false;
        
        path.push_back(root);
        if (root->data == key) return true;
        
        if (findPath(root->left, key, path) || 
            findPath(root->right, key, path)) return true;
        
        path.pop_back();
        return false;
    }
    
    
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        vector<Node *> pathN1, pathN2;
        if (findPath(root, n1, pathN1) == false ||
            findPath(root, n2, pathN2) == false) return NULL;
            
        for (int i=1; i<pathN1.size() && i<pathN2.size(); i++) {
            if (pathN1[i] != pathN2[i]) return pathN1[i-1];
        }
        
        return pathN1.size() < pathN2.size() ? pathN1[pathN1.size()-1] : pathN2[pathN2.size()-1];
    }
};