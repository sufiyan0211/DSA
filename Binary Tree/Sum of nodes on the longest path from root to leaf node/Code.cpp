class Solution {
  public:
    // {height, sum}
    pair<int, int> sumTree(Node *root) {
        if(root == NULL) return make_pair(0, 0);
        
        if(root->left == NULL && root->right == NULL) return make_pair(1, root->data);
        
        pair<int, int> ans;
        
        pair<int, int> leftSubtree = sumTree(root->left);
        pair<int, int> rightSubtree = sumTree(root->right);
        
        ans.first = 1 + max(leftSubtree.first, rightSubtree.first);
        
        if (leftSubtree.first > rightSubtree.first) {
            ans.second = root->data + leftSubtree.second;
        }
        else if (rightSubtree.first > leftSubtree.first) {
            ans.second = root->data + rightSubtree.second;
        }
        else { // leftSubtree.first == rightSubtree.first
            if (leftSubtree.second > rightSubtree.second) {
                ans.second = root->data + leftSubtree.second;
            }
            else {
                ans.second = root->data + rightSubtree.second;
            }
        }
        
        return ans;
    }
    
    
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        return sumTree(root).second;
    }
};
