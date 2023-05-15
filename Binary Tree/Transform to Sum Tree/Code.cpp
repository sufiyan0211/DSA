class Solution {
public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree

    int sumTree(Node *root) {
        if(root == NULL) {
            return 0;
        }
        int oldValueOfRoot = root->data;
        int left = sumTree(root->left);
        int right = sumTree(root->right);
        root->data = left+right;
        return root->data + oldValueOfRoot;
    }

    void toSumTree(Node *root)
    {
        // Your code here
        sumTree(root);
    }
};