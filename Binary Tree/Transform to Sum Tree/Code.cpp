class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sumTreeUtility(Node *root) {
        if (root == NULL) return 0;
        
        int leftSubtree = sumTreeUtility(root->left);
        int rightSubtree = sumTreeUtility(root->right);
        
        int ans = root->data + leftSubtree + rightSubtree;
        
        root->data = leftSubtree + rightSubtree;
        
        return ans;
    }
    
    void toSumTree(Node *root) {
        // Your code here
        sumTreeUtility(root);
    }
};
