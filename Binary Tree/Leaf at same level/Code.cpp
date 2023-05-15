class Solution{
public:
    /*You are required to complete this method*/
    // iterative way -> levelorder Traversal
    bool recursive(Node *root, int &levelOfFirstLeafNode, int currLevel) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) {
            if(levelOfFirstLeafNode == 0) {
                levelOfFirstLeafNode = currLevel;
                return true;
            }
            if(levelOfFirstLeafNode == currLevel) {
                return true;
            }
            else return false;
        }
        bool left = recursive(root->left, levelOfFirstLeafNode, currLevel+1);
        bool right = recursive(root->right, levelOfFirstLeafNode, currLevel+1);

        return (left && right);
    }
    bool check(Node *root)
    {
        //Your code here
        int currLevel = 0;
        int levelOfFirstLeafNode = 0;
        return recursive(root, levelOfFirstLeafNode, currLevel);
    }
};